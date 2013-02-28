#ifndef MANEJODEARCHIVOSCSV_H
#define MANEJODEARCHIVOSCSV_H

#include <ventanaprincipal.h>
#include <ui_dialogoparaimportararchivoscsv.h>
#include <variablesglobales.h>

///##############################
///### Definción de la estructura para contabilizar el número de variables y casos del archivo CSV
///##############################
struct informacion {
  long unsigned totalDeCampos;
  long unsigned totalDeCasos;
} dimensionDeLosDatos;

///##############################
///### Procedimientos para determinar el número de variables y casos del archivo csv
///##############################
void cb1 (void *s, size_t len, void *data)
{
    ((struct informacion *)data)->totalDeCampos++;
}

void cb2 (int c, void *data)
{
    ((struct informacion *)data)->totalDeCasos++;
    if (numeroDeVariablesTemporal < dimensionDeLosDatos.totalDeCampos)
    {
        numeroDeVariablesTemporal = dimensionDeLosDatos.totalDeCampos;
    }
    ((struct informacion *)data)->totalDeCampos = 0;
}

///##############################
///### Función para verificar que el formato del archivo CSV sea correcto
///##############################
bool formatoDelArchivoCSVCorrecto(FILE *archivoCSVParaImportar)
{
    struct stat tamanoDelArchivo;
    struct csv_parser analizador;
    bool archivoCSVBueno;
    long totalDeBytesLeidos;
    size_t bytesLeidos;
    char bufferTemporal[1024];
    size_t valorRegresado;
    double porcentajeAnalizadoDelArchivo;

    stat(nombreDeArchivoCSV.toAscii().data(), &tamanoDelArchivo);
    archivoCSVBueno = true;
    totalDeBytesLeidos = 0;
    numeroDeVariablesTemporal = 0;
    dimensionDeLosDatos.totalDeCasos = 0;
    ///##############################
    ///### Inicialización del analizador para el archivo CSV
    ///##############################
    if (csv_init(&analizador, CSV_STRICT) != 0)
    {
        ///##############################
        ///### Falló la inicialización del analizador para el archivo CSV
        ///##############################
        QMessageBox mensajeErrorDeInicializacionDelAnalizadorDelArchivoCSV;
        mensajeErrorDeInicializacionDelAnalizadorDelArchivoCSV.setText(QString::fromUtf8(errorDeInicializacionDelAnalizadorDelArchivoCSV));
        mensajeErrorDeInicializacionDelAnalizadorDelArchivoCSV.exec();
    }
    else
    {
        ///##############################
        ///### Análisis del archivo CSV
        ///##############################
        while (((bytesLeidos=fread(bufferTemporal, 1, 1024, archivoCSVParaImportar)) > 0) and (archivoCSVBueno))
        {
            if ((valorRegresado = csv_parse(&analizador, bufferTemporal, bytesLeidos, cb1, cb2, &dimensionDeLosDatos)) != bytesLeidos)
            {
                archivoCSVBueno = false;
            }
            else
            {
                totalDeBytesLeidos += bytesLeidos;
                porcentajeAnalizadoDelArchivo = (totalDeBytesLeidos*100)/tamanoDelArchivo.st_size;
                dialogoParaImportarUnArchivoCSV->ui->porcentajeDeAnalisis->setValue(porcentajeAnalizadoDelArchivo);
            }
        }
    }
    ///##############################
    ///### Se libera la estructura que se usa para el anáisis del archivo CSV
    ///##############################
    csv_free(&analizador);
    if (dimensionDeLosDatos.totalDeCasos == 0)
    {
        archivoCSVBueno = false;
    }

    return archivoCSVBueno;
}

///##############################
///### Función para realizar la conexión a la base de datos funcional
///##############################
bool VentanaPrincipal::conexionCorrectaALaBdFuncional()
{
    if ((sqlite3_open("./baseDeDatosFuncional", &db) != SQLITE_OK))
    {
        return false;
    }
    else
    {
        ///##############################
        ///### Crear el modelo de datos funcional y ligarlo al qtableview correspondiente
        ///##############################
        modeloDeLaBaseDeDatosFuncionalParaDatos = new QSqlTableModel;
        modeloDeLaBaseDeDatosFuncionalParaDatos->setEditStrategy(QSqlTableModel::OnFieldChange);
        ui->tablaDeDatos->setModel(modeloDeLaBaseDeDatosFuncionalParaDatos);
        ///##############################
        ///### Crear el modelo de variables funcional y ligarlo al qtableview
        ///##############################
        modeloDeLaBaseDeDatosFuncionalParaVariables = new QSqlTableModel;
        modeloDeLaBaseDeDatosFuncionalParaVariables->setEditStrategy(QSqlTableModel::OnFieldChange);
        ui->tablaDeVariables->setModel(modeloDeLaBaseDeDatosFuncionalParaVariables);
    }

    return true;
}

///##############################
///### Procedimiento para eliminar el archivo de la base de datos funcional
///##############################
void VentanaPrincipal::eliminarArchivoDeLaBdFuncional()
{
    if (remove("./baseDeDatosFuncional") < -1)
    {
        ///##############################
        ///### Falló el borrado de la base de datos funcional
        ///##############################
        QMessageBox mensajeDeErrorAlBorrarArchivoDeDatosFuncional;
        mensajeDeErrorAlBorrarArchivoDeDatosFuncional.setText(QString::fromUtf8(errorAlBorrarArchivoDeDatosFuncional));
        mensajeDeErrorAlBorrarArchivoDeDatosFuncional.exec();
    }
}

///##############################
///### Procedimiento para cerrar la conexión a la base de datos funcional
///##############################
void VentanaPrincipal::cerrarConexionALaBdFuncional()
{
    ///##############################
    ///### Operaciones para cerrar la conexión a la base de datos funcional
    ///##############################
    delete modeloDeLaBaseDeDatosFuncionalParaDatos;
    delete modeloDeLaBaseDeDatosFuncionalParaVariables;
    baseDeDatosFuncional->close();
    delete baseDeDatosFuncional;
    QSqlDatabase::removeDatabase(nombreDeLaConexionALaBdFuncional);
}

///##############################
///### Procedimiento de "refresh" de las vistas de datos y de variables de la base de datos funcional
///##############################
void VentanaPrincipal::actualizarVistasDeLaBdFuncional()
{
    modeloDeLaBaseDeDatosFuncionalParaDatos->setTable("datos");
    modeloDeLaBaseDeDatosFuncionalParaDatos->select();
    modeloDeLaBaseDeDatosFuncionalParaVariables->setTable("variables");
    modeloDeLaBaseDeDatosFuncionalParaVariables->select();
}

///##############################
///### Función para crear la base de datos funcional
///##############################
bool VentanaPrincipal::crearBaseDeDatosFuncional(bool variablesEstanEnLaPrimeraFila)
{
    char numero[9];
    unsigned long totalDeCasosLeidos;

    ///##############################
    ///### Se abre el archivo CSV
    ///##############################
    archivoDeEntrada.open(nombreDeArchivoCSV.toAscii().data());
    ///##############################
    ///### Definición del diccionario de datos de la tabla de datos funcional
    ///##############################
    strcpy (consulta, "CREATE TABLE datos (");
    for (unsigned int x=1; x<numeroDeVariablesFuncional; x++)
    {
        sprintf (numero, "var%d", x);
        strcat (consulta, numero);
        strcat (consulta, " NUMERIC,");
    }
    sprintf (numero, "var%ld", numeroDeVariablesFuncional);
    strcat (consulta, numero);
    strcat (consulta, " NUMERIC)");
    //##############################
    ///### Inicio de transacciones en la base de datos funcional
    ///##############################
    sqlite3_exec(db, "PRAGMA synchronous = OFF", NULL, NULL, &sErrMsg);
    sqlite3_exec(db, "PRAGMA journal_mode = MEMORY", NULL, NULL, &sErrMsg);
    //sqlite3_exec(db, "BEGIN TRANSACTION", NULL, NULL, &sErrMsg);
    ///##############################
    ///### Borrado de la tabla de datos funcional y creación de la tabla de datos funcional con la nueva estructura
    ///### También se establece la tabla correspondiente al modelo de datos funcional
    ///##############################
    sqlite3_exec(db, "DELETE FROM datos WHERE 1", NULL, NULL, &sErrMsg);
    sqlite3_exec(db, consulta, NULL, NULL, &sErrMsg);
    modeloDeLaBaseDeDatosFuncionalParaDatos->setTable("datos");
    ///##############################
    ///### Sección de inserción de los casos del archivo CSV en la tabla de datos funcional
    ///##############################
    totalDeCasosLeidos = 0;    
    ///##############################
    ///### Inserción de los casos
    ///##############################
    while(getline(archivoDeEntrada, linea)  && archivoDeEntrada.good())
    {
        strcpy (consulta, "INSERT INTO datos VALUES(");
        strcat (consulta, linea.c_str());
        strcat (consulta, ")");
        sqlite3_exec(db, consulta, NULL, NULL, &sErrMsg);
        totalDeCasosLeidos++;
    }
    archivoDeEntrada.close();
    modeloDeLaBaseDeDatosFuncionalParaDatos->select();
    ///##############################
    ///### Se elimina el primer registro en caso de que las variables estén en la primera línea
    ///##############################
    if (variablesEstanEnLaPrimeraFila)
    {
        arregloDeVariablesFuncional = modeloDeLaBaseDeDatosFuncionalParaDatos->record(0);
        modeloDeLaBaseDeDatosFuncionalParaDatos->removeRow(0);
        for (unsigned long i=0; i<numeroDeVariablesFuncional; i++)
        {
            modeloDeLaBaseDeDatosFuncionalParaDatos->setHeaderData(i, Qt::Horizontal, arregloDeVariablesFuncional.value(i).toString().toAscii().data());
        }
    }
    ///##############################
    ///### Borrado de la tabla de variables funcional y creación de la nueva tabla de variables funcional
    ///### También se establece la tabla correspondiente al modelo de variables funcional
    ///##############################
    sqlite3_exec(db, "DELETE FROM variables WHERE 1", NULL, NULL, &sErrMsg);
    sqlite3_exec(db, "CREATE TABLE variables (Nombre text, Tipo text, Etiqueta text, Valores text, Escala text)", NULL, NULL, &sErrMsg);
    modeloDeLaBaseDeDatosFuncionalParaVariables->setTable("variables");
    ///##############################
    ///### Sección de inserción de las variables considerando sus características iniciales
    ///##############################
    for (unsigned long i=0; i<numeroDeVariablesFuncional; i++)
    {
        ///##############################
        ///### Detección del tipo de dato inicial de la variable i
        ///##############################
        char tipoInicialDeDatoDeLaVariable[9];
        sprintf (consulta, "SELECT COUNT(tipo) FROM (SELECT TYPEOF(var%lu) AS tipo FROM datos WHERE var%lu<>'') WHERE tipo='text'", i+1, i+1);
        sqlite3_exec(db, consulta, NULL, NULL, &sErrMsg);

        /*while (tipoDeDatoInicialDeLaVariable.next())
        {
            if (tipoDeDatoInicialDeLaVariable.value(0).toInt() > 0)
            {
                strcpy (tipoInicialDeDatoDeLaVariable, QString::fromUtf8(texto).toAscii().data());
            }
            else
            {*/
                strcpy (tipoInicialDeDatoDeLaVariable, QString::fromUtf8(numerico).toAscii().data());
          /*  }
        }*/
        ///##############################
        ///### Tipo de escala inicial de la variable i
        ///##############################
        char tipoInicialDeEscalaLaVariable[12];
        if (strcmp(tipoInicialDeDatoDeLaVariable, "Texto") == 0)
        {
            strcpy (tipoInicialDeEscalaLaVariable, QString::fromUtf8(nominal).toAscii().data());
        }
        else
        {
            strcpy (tipoInicialDeEscalaLaVariable, QString::fromUtf8(escala).toAscii().data());
        }
        if (variablesEstanEnLaPrimeraFila)
        {
            sprintf (consulta, "INSERT INTO variables VALUES ('%s', '%s', '%s', '', '%s')", arregloDeVariablesFuncional.value(i).toString().toAscii().data(), tipoInicialDeDatoDeLaVariable, arregloDeVariablesTemporal.value(i).toString().toAscii().data(), tipoInicialDeEscalaLaVariable);
        }
        else
        {
            sprintf (consulta, "INSERT INTO variables VALUES ('var%lu', '%s', 'var%lu', '', '%s')", i+1, tipoInicialDeDatoDeLaVariable, i+1, tipoInicialDeEscalaLaVariable);
        }
        sqlite3_exec(db, consulta, NULL, NULL, &sErrMsg);
    }
    modeloDeLaBaseDeDatosFuncionalParaVariables->select();
    //##############################
    ///### Finalización de transacciones en la base de datos funcional
    ///##############################
    //sqlite3_exec(db, "END TRANSACTION", NULL, NULL, &sErrMsg);
    actualizarVistasDeLaBdFuncional();

    return true;
}

///##############################
///### Procedimiento para importar un archivo con formato CSV
///##############################
void VentanaPrincipal::on_accionImportarArchivoConFormatoCSV_triggered()
{
    QFileDialog dialogoParaImportarArchivoCSV;
    FILE *archivoCSVParaImportar;

    ///##############################
    ///### Abrir ventana de diálogo para seleccionar archivo CSV
    ///##############################
    dialogoParaImportarArchivoCSV.setNameFilter("*.csv");
    if (dialogoParaImportarArchivoCSV.exec())
    {
        ///##############################
        ///### Se asigna a la variable nombreDeArchivoCSV el archivo seleccionado incluyendo la ruta
        ///##############################
        nombreDeArchivoCSV = dialogoParaImportarArchivoCSV.selectedFiles().first().toAscii().data();
        if ((archivoCSVParaImportar = fopen64((const char*)nombreDeArchivoCSV.toAscii().data(), "r")) == NULL)
        {
            ///##############################
            ///### Falló el intento de abrir el archivo CSV
            ///##############################
            QMessageBox mensajeErrorAlIntentarAbrirElArchivoCSV;
            mensajeErrorAlIntentarAbrirElArchivoCSV.setText(QString::fromUtf8(errorAlIntentarAbrirElArchivoCSV));
            mensajeErrorAlIntentarAbrirElArchivoCSV.exec();
        }
        ///##############################
        ///### Se pudo abrir el archivo CSV para lectura y se procede a realizar el análisis del mismo y en su
        ///### caso el vaciado a las tablas correspodientes
        ///##############################
        else
        {
            ///##############################
            ///### Definición del diálogo para importar el archivo CSV seleccionado
            ///##############################
            dialogoParaImportarUnArchivoCSV = new DialogoParaImportarArchivosCSV();
            dialogoParaImportarUnArchivoCSV->ui->nombreDelArchivoCSVAImportar->setText(nombreDeArchivoCSV.toAscii().data());
            ///##############################
            ///### Se elimina el botón de cerrado [X] de la parte superior derecha del diálogo de importación del
            ///### archivo CSV y se realiza el desplegado del mismo en la pantalla
            ///##############################
            dialogoParaImportarUnArchivoCSV->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
            dialogoParaImportarUnArchivoCSV->show();
            ///##############################
            ///### Se verifica que el formato del archivo CSV seleccionado sea correcto
            ///##############################
            if (formatoDelArchivoCSVCorrecto(archivoCSVParaImportar))
            {
                ///##############################
                ///### El formato del archivo CSV es correcto
                ///##############################
                numeroDeCasosTemporal = dimensionDeLosDatos.totalDeCasos;
                if (baseDeDatosFuncionalEnUso)
                {
                    cerrarConexionALaBdFuncional();
                }
            }
            else
            {
                ///##############################
                ///### El formato del archivo CSV es incorrecto
                ///##############################
                QMessageBox mensajeFormatoIncorrectoDelArchivoCSV;
                mensajeFormatoIncorrectoDelArchivoCSV.setText(QString::fromUtf8(formatoIncorrectoDelArchivoCSV));
                mensajeFormatoIncorrectoDelArchivoCSV.exec();
                dialogoParaImportarUnArchivoCSV->~DialogoParaImportarArchivosCSV();
            }
        }
    }
    else
    {
        ///##############################
        ///### No se seleccionó ningún archivo CSV y se cierra el diálogo para abrir archivos
        ///##############################
    }
}

//##############################
///### Procedimiento de cambio en el checkbox que indica si las variables se encuentran en la primera fila
///##############################
void VentanaPrincipal::cambioEnCheckBoxVariablesEnLaPrimeraFila()
{
    ///##############################
    ///### Se seleccionó el checkbox de variables en primera fila
    ///##############################
    if (dialogoParaImportarUnArchivoCSV->ui->variablesEnPrimeraFila->isChecked())
    {
        for (unsigned long i=0; i<numeroDeVariablesTemporal; i++)
        {
            modeloDeLaBaseDeDatosTemporalParaDatos->setHeaderData(i, Qt::Horizontal, arregloDeVariablesTemporal.value(i).toString().toAscii().data());
        }
        numeroDeCasosTemporal--;
        dialogoParaImportarUnArchivoCSV->ui->numeroDeCasos->setText(QString::number(numeroDeCasosTemporal));
    }
    else
    {
        numeroDeCasosTemporal++;
        dialogoParaImportarUnArchivoCSV->ui->numeroDeCasos->setText(QString::number(numeroDeCasosTemporal));
    }
}

///##############################
///### Procedimiento para cancelar la importación del archivo CSV
///##############################
void VentanaPrincipal::botonCancelarDeLaVentanaDeAnalisisDelArchivoCSVOprimido()
{
    ///##############################
    ///### Regresar el control a la base de datos funcional que está en uso
    ///##############################
    if (baseDeDatosFuncionalEnUso)
    {
        if (!conexionCorrectaALaBdFuncional())
        {
            ///##############################
            ///### Falló la creación de la base de datos funcional
            ///### y se despliega el error correspondiente
            ///##############################
            QMessageBox mensajeDeErrorNoSePuedeReconectarALaBaseDeDatosFuncional;
            mensajeDeErrorNoSePuedeReconectarALaBaseDeDatosFuncional.setText(QString::fromUtf8(errorNoSePuedeReconectarALaBaseDeDatosFuncional));
            mensajeDeErrorNoSePuedeReconectarALaBaseDeDatosFuncional.exec();
            cerrarConexionALaBdFuncional();
            eliminarArchivoDeLaBdFuncional();
            baseDeDatosFuncionalEnUso = false;
        }
        else
        {
            //##############################
            ///### Actualizar las vistas de la base de datos funcional
            ///##############################
            actualizarVistasDeLaBdFuncional();
        }
    }
    ///##############################
    ///### Se llama al destructor del diálogo para importar archivos CSV
    ///##############################
    dialogoParaImportarUnArchivoCSV->~DialogoParaImportarArchivosCSV();
}

///##############################
///### Procedimiento para aceptar la importación del archivo CSV
///##############################
void VentanaPrincipal::botonAceptarDeLaVentanaDeAnalisisDelArchivoCSVOprimido()
{
    ///##############################
    ///### Llamar al procedimiento de guardar base de datos funcional en caso de que esté en uso actualmente
    ///##############################
    if (baseDeDatosFuncionalEnUso)
    {

    }
    else
    {
        if (!conexionCorrectaALaBdFuncional())
        {
            ///##############################
            ///### Falló la creación de la base de datos funcional
            ///### y se despliega el error correspondiente
            ///##############################
            QMessageBox mensajeDeErrorNoSePuedeCrearLaBaseDeDatosFuncional;
            mensajeDeErrorNoSePuedeCrearLaBaseDeDatosFuncional.setText(QString::fromUtf8(errorNoSePuedeCrearLaBaseDeDatosFuncional));
            mensajeDeErrorNoSePuedeCrearLaBaseDeDatosFuncional.exec();
        }
        else
        {
            ///##############################
            ///### Definición y desplegado de la ventana de progreso del vaciado del archivo CSV
            ///##############################
            numeroDeCasosFuncional = numeroDeCasosTemporal;
            numeroDeVariablesFuncional = numeroDeVariablesTemporal;
            if (!crearBaseDeDatosFuncional(dialogoParaImportarUnArchivoCSV->ui->variablesEnPrimeraFila->isChecked()))
            {
                ///##############################
                ///### Error al crear la base de datos funcional
                ///##############################
                QMessageBox mensajeErrorAlCrearLaBaseDeDatosFuncional;
                mensajeErrorAlCrearLaBaseDeDatosFuncional.setText(QString::fromUtf8(errorAlCrearLaBaseDeDatosFuncional));
                mensajeErrorAlCrearLaBaseDeDatosFuncional.exec();
            }
            else
            {
                baseDeDatosFuncionalEnUso = true;
            }
        }
    }
    dialogoParaImportarUnArchivoCSV->~DialogoParaImportarArchivosCSV();
}

#endif // MANEJODEARCHIVOSCSV_H
