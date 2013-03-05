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
///### Función para realizar la conexión a la base de datos temporal
///##############################
bool VentanaPrincipal::conexionCorrectaALaBdTemporal()
{
    ///##############################
    ///### Inicialización de algunos argumentos de la base de datos temporal
    ///##############################
    baseDeDatosTemporal = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    baseDeDatosTemporal->setDatabaseName("./baseDeDatosTemporal");
    nombreDeLaConexionALaBdTemporal = baseDeDatosTemporal->connectionName();
    if (!baseDeDatosTemporal->open())
    {
        return false;
    }
    else
    {
        ///##############################
        ///### Crear el modelo de datos temporal y ligarlo al qtableview correspondiente del diálogo para importar archivos CSV
        ///##############################
        modeloDeLaBaseDeDatosTemporalParaDatos = new QSqlTableModel;
        modeloDeLaBaseDeDatosTemporalParaDatos->setEditStrategy(QSqlTableModel::OnFieldChange);
        dialogoParaImportarUnArchivoCSV->ui->tablaDeDatosTemporal->setModel(modeloDeLaBaseDeDatosTemporalParaDatos);
        ///##############################
        ///### Crear el modelo de variables temporal y ligarlo al qtableview correspondiente del diálogo para importar archivos CSV
        ///##############################
        modeloDeLaBaseDeDatosTemporalParaVariables = new QSqlTableModel;
        modeloDeLaBaseDeDatosTemporalParaVariables->setEditStrategy(QSqlTableModel::OnFieldChange);
        dialogoParaImportarUnArchivoCSV->ui->tablaDeVariablesTemporal->setModel(modeloDeLaBaseDeDatosTemporalParaVariables);
    }

    return true;
}

///##############################
///### Procedimiento para cerrar la conexión a la base de datos temporal
///##############################
void VentanaPrincipal::cerrarConexionALaBdTemporal()
{
    ///##############################
    ///### Operaciones para cerrar la conexión a la base de datos temporal
    ///##############################
    delete modeloDeLaBaseDeDatosTemporalParaDatos;
    delete modeloDeLaBaseDeDatosTemporalParaVariables;
    baseDeDatosTemporal->close();
    delete baseDeDatosTemporal;
    QSqlDatabase::removeDatabase(nombreDeLaConexionALaBdTemporal);
    if (remove("./baseDeDatosTemporal") < -1)
    {
        ///##############################
        ///### Falló el borrado de la base de datos temporal, se cierra el diálogo de importación de archivos CSV
        ///### y se despliega el error correspondiente
        ///##############################
        QMessageBox mensajeDeErrorAlBorrarArchivoDeDatosTemporal;
        mensajeDeErrorAlBorrarArchivoDeDatosTemporal.setText(QString::fromUtf8(errorAlBorrarArchivoDeDatosTemporal));
        mensajeDeErrorAlBorrarArchivoDeDatosTemporal.exec();
    }
}

///##############################
///### Función para crear la base de datos temporal
///##############################
bool crearBaseDeDatosTemporal(bool variablesEstanEnLaPrimeraFila)
{
    char numero[9];
    unsigned long totalDeCasosLeidos;
    int casosParaElAnalisis=99;

    ///##############################
    ///### Se abre el archivo CSV
    ///##############################
    archivoDeEntrada.open(nombreDeArchivoCSV.toAscii().data());
    ///##############################
    ///### Definición del diccionario de datos de la tabla de datos temporal
    ///##############################
    strcpy (consulta, "CREATE TABLE datos (");
    for (unsigned int x=1; x<numeroDeVariablesTemporal; x++)
    {
        sprintf (numero, "var%d", x);
        strcat (consulta, numero);
        strcat (consulta, " NUMERIC,");
    }
    sprintf (numero, "var%ld", numeroDeVariablesTemporal);
    strcat (consulta, numero);
    strcat (consulta, " NUMERIC)");
    //##############################
    ///### Inicio de transacciones en la base de datos temporal
    ///##############################
    QSqlQuery iniciarTransaccionesEnLaBaseDeDatosTemporal("BEGIN TRANSACTION");
    ///##############################
    ///### Borrado de la tabla de datos temporal y creación de la tabla de datos temporal con la nueva estructura
    ///### También se establece la tabla correspondiente al modelo de datos temporal
    ///##############################
    QSqlQuery borradoDeLaTablaDeDatosTemporal("DELETE FROM datos WHERE 1");
    QSqlQuery crearTablaDeDatosTemporal (consulta);
    modeloDeLaBaseDeDatosTemporalParaDatos->setTable("datos");
    ///##############################
    ///### Sección de inserción de los primeros 99 casos -o menos- del archivo CSV en la tabla de datos temporal
    ///##############################
    totalDeCasosLeidos = 0;
    ///##############################
    ///### Inserción de los primeros 99 0 100 casos dependiendo si el nombre de las variables está oen la primera fila
    ///##############################
    if (variablesEstanEnLaPrimeraFila)
    {
        casosParaElAnalisis = 100;
    }
    while(getline(archivoDeEntrada, linea)  && archivoDeEntrada.good() && (totalDeCasosLeidos < casosParaElAnalisis))
    {
        strcpy (consulta, "INSERT INTO datos VALUES(");
        strcat (consulta, linea.c_str());
        strcat (consulta, ")");
        QSqlQuery insertarRegistrosDeDatos (consulta);
        totalDeCasosLeidos++;
    }
    archivoDeEntrada.close();
    modeloDeLaBaseDeDatosTemporalParaDatos->select();
    ///##############################
    ///### Se elimina el primer registro en caso de que las variables estén en la primera línea
    ///##############################
    if (variablesEstanEnLaPrimeraFila)
    {
        arregloDeVariablesTemporal = modeloDeLaBaseDeDatosTemporalParaDatos->record(0);
        modeloDeLaBaseDeDatosTemporalParaDatos->removeRow(0);
    }
    ///##############################
    ///### Borrado de la tabla de variables temporal y creación de la nueva tabla de variables temporal
    ///### También se establece la tabla correspondiente al modelo de variables temporal
    ///##############################
    QSqlQuery borradoDeLaTablaDeVariablesTemporal("DELETE FROM variables WHERE 1");
    QSqlQuery definirTablaDeVariablesTemporal("CREATE TABLE variables (Nombre text, Tipo text, Etiqueta text, Valores text, Escala text)");
    modeloDeLaBaseDeDatosTemporalParaVariables->setTable("variables");
    ///##############################
    ///### Sección de inserción de las variables considerando sus características iniciales
    ///##############################
    for (unsigned long i=0; i<numeroDeVariablesTemporal; i++)
    {
        ///##############################
        ///### Detección del tipo de dato inicial de la variable i
        ///##############################
        char tipoInicialDeDatoDeLaVariable[9];
        sprintf (consulta, "SELECT COUNT(tipo) FROM (SELECT TYPEOF(var%lu) AS tipo FROM datos WHERE var%lu<>'') WHERE tipo='text'", i+1, i+1);
        QSqlQuery tipoDeDatoInicialDeLaVariable(consulta);
        while (tipoDeDatoInicialDeLaVariable.next())
        {
            if (tipoDeDatoInicialDeLaVariable.value(0).toInt() > 0)
            {
                strcpy (tipoInicialDeDatoDeLaVariable, QString::fromUtf8(texto).toAscii().data());
            }
            else
            {
                strcpy (tipoInicialDeDatoDeLaVariable, QString::fromUtf8(numerico).toAscii().data());
            }
        }
///##############################
///### DE MOMENTO LOS VALORES NO SE PUEDEN EDITAR DURANTE EL ANÁLISIS DEL ARCHIVO CSV A IMPORTAR
///##############################
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
            sprintf (consulta, "INSERT INTO variables VALUES ('%s', '%s', '%s', '', '%s')", arregloDeVariablesTemporal.value(i).toString().toAscii().data(), tipoInicialDeDatoDeLaVariable, arregloDeVariablesTemporal.value(i).toString().toAscii().data(), tipoInicialDeEscalaLaVariable);
        }
        else
        {
            sprintf (consulta, "INSERT INTO variables VALUES ('var%lu', '%s', 'var%lu', '', '%s')", i+1, tipoInicialDeDatoDeLaVariable, i+1, tipoInicialDeEscalaLaVariable);
        }
        QSqlQuery insertarDefinicionInicialDeVariables(consulta);
    }
    modeloDeLaBaseDeDatosTemporalParaVariables->select();
    //##############################
    ///### Finalización de transacciones en la base de datos temporal
    ///##############################
    QSqlQuery finalizarTransaccionesEnLaBaseDeDatosTemporal( "COMMIT TRANSACTION");

    return true;
}

///##############################
///### Función para realizar la conexión a la base de datos funcional
///##############################
bool VentanaPrincipal::conexionCorrectaALaBdFuncional()
{
    ///##############################
    ///### Inicialización de algunos argumentos de la base de datos funcional
    ///##############################
    baseDeDatosFuncional = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    baseDeDatosFuncional->setDatabaseName("./baseDeDatosFuncional");
    nombreDeLaConexionALaBdFuncional = baseDeDatosFuncional->connectionName();
    if (!baseDeDatosFuncional->open())
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
void eliminarArchivoDeLaBdFuncional()
{
    if (remove("./baseDeDatosFuncional") < -1)
    {
        ///##############################
        ///### Falló el borrado de la base de datos funcional
        ///##############################
        QMessageBox mensajeDeErrorAlBorrarArchivoDeDatosFuncional;
        mensajeDeErrorAlBorrarArchivoDeDatosFuncional.setText(QString::fromUtf8(errorAlBorrarArchivoDeDatosTemporal));
        mensajeDeErrorAlBorrarArchivoDeDatosFuncional.exec();
    }
}

///##############################
///### Procedimiento para cerrar la conexión a la base de datos funcional
///##############################
void cerrarConexionALaBdFuncional()
{
    ///##############################
    ///### Operaciones para cerrar la conexión a la base de datos funcional
    ///##############################
    //baseDeDatosFuncional->close();
    delete modeloDeLaBaseDeDatosFuncionalParaDatos;
    delete modeloDeLaBaseDeDatosFuncionalParaVariables;
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
    //QSqlQuery actualizarEncabezadosDeLaTablaDeDatos("SELECT nombre from variables")
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
    QSqlQuery iniciarTransaccionesEnLaBaseDeDatosFuncional("BEGIN TRANSACTION");
    ///##############################
    ///### Borrado de la tabla de datos funcional y creación de la tabla de datos funcional con la nueva estructura
    ///### También se establece la tabla correspondiente al modelo de datos funcional
    ///##############################
    QSqlQuery borradoDeLaTablaDeDatosFuncional("DELETE FROM datos WHERE 1");
    QSqlQuery crearTablaDeDatosFuncional (consulta);
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
        QSqlQuery insertarRegistrosDeDatos (consulta);
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
    QSqlQuery borradoDeLaTablaDeVariablesFuncional("DELETE FROM variables WHERE 1");
    QSqlQuery definirTablaDeVariablesFuncional("CREATE TABLE variables (Nombre text, Tipo text, Etiqueta text, Valores text, Escala text)");
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
        QSqlQuery tipoDeDatoInicialDeLaVariable(consulta);
        while (tipoDeDatoInicialDeLaVariable.next())
        {
            if (tipoDeDatoInicialDeLaVariable.value(0).toInt() > 0)
            {
                strcpy (tipoInicialDeDatoDeLaVariable, QString::fromUtf8(texto).toAscii().data());
            }
            else
            {
                strcpy (tipoInicialDeDatoDeLaVariable, QString::fromUtf8(numerico).toAscii().data());
            }
        }
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
        QSqlQuery insertarDefinicionInicialDeVariables(consulta);
    }
    modeloDeLaBaseDeDatosFuncionalParaVariables->select();
    //##############################
    ///### Finalización de transacciones en la base de datos funcional
    ///##############################
    QSqlQuery finalizarTransaccionesEnLaBaseDeDatosFuncional("COMMIT TRANSACTION");

=======
///### Procedimiento para insertar los primeros 99 casos -o menos- del archivo CSV
///##############################
bool VentanaPrincipal::insertarPrimeros99CasosOMenosDelArchivoCSV()
{
    unsigned long totalDeCasosLeidos;
    unsigned long fila;

    ///##############################
    ///### Configuración del número de columnas de la tabla de datos temporal y el número de filas de la tabla de datos temporal
    ///##############################
    dialogoParaImportarUnArchivoCSV->ui->tablaDeVariablesTemporal->setRowCount(numeroDeVariablesTemporal);
    dialogoParaImportarUnArchivoCSV->ui->tablaDeDatosTemporal->setColumnCount(numeroDeVariablesTemporal);
    ///##############################
    ///### Abriendo el archivo CSV para lectura
    ///##############################
    QFile archivoCSV(nombreDeArchivoCSV.toAscii().data());
    QString linea;
    if (!archivoCSV.open(QIODevice::ReadOnly))
    {
        return false;
    }
    QTextStream cadena(&archivoCSV);
    ///##############################
    ///### Se elimina el primer registro en caso de que las variables estén en la primera línea
    ///##############################
    if (dialogoParaImportarUnArchivoCSV->ui->variablesEnPrimeraFila->isChecked())
    {
        QString linea = cadena.readLine();
        QStringList campos = linea.split(",");
        for (int i = 0; i < numeroDeVariablesTemporal; i++)
        {
            QTableWidgetItem *dato=new QTableWidgetItem (campos.at(i).toLocal8Bit().constData());
            dialogoParaImportarUnArchivoCSV->ui->tablaDeVariablesTemporal->setItem(i, 0, dato);
        }
        numeroDeCasosTemporal--;
    }
    else
    {
        QString nombresDeLasVariables = "";
        for (int i = 0; i < numeroDeVariablesTemporal; i++)
        {
            nombresDeLasVariables += "var" + QString::number(i+1) + ",";
        }
        dialogoParaImportarUnArchivoCSV->ui->tablaDeDatosTemporal->setHorizontalHeaderLabels(nombresDeLasVariables.split(","));
        numeroDeCasosTemporal = dimensionDeLosDatos.totalDeCasos;
    }
    ///##############################
    ///### Desplegado del nombre del archivo, número de variables, número de casos y configuración del número de filas
    ///### de la tabla de datos
    ///##############################
    dialogoParaImportarUnArchivoCSV->ui->nombreDelArchivoCSVAImportar->setText(nombreDeArchivoCSV.toAscii().data());
    dialogoParaImportarUnArchivoCSV->ui->numeroDeVariables->setText(QString::number(numeroDeVariablesTemporal));
    dialogoParaImportarUnArchivoCSV->ui->numeroDeCasos->setText(QString::number(numeroDeCasosTemporal));
    (numeroDeCasosTemporal < 99)
        ? dialogoParaImportarUnArchivoCSV->ui->tablaDeDatosTemporal->setRowCount(numeroDeCasosTemporal)
        : dialogoParaImportarUnArchivoCSV->ui->tablaDeDatosTemporal->setRowCount(99);
    ///##############################
    ///### Llenado de la tabla de datos temporal
    ///##############################
    totalDeCasosLeidos = 0;
    fila = 0;
    while(!cadena.atEnd())
    {
        QString linea = cadena.readLine();
        ///##############################
        ///### Se eliminan las ""
        ///##############################
        linea.replace(QString("\""),QString(""));
        QStringList campos = linea.split(",");
        for (int i = 0; i < numeroDeVariablesTemporal; ++i)
        {
            QTableWidgetItem *dato=new QTableWidgetItem (campos.at(i).toLocal8Bit().constData());
            dialogoParaImportarUnArchivoCSV->ui->tablaDeDatosTemporal->setItem(fila, i, dato);
            ///##############################
            ///### Detectar el tipo de la variable
            ///##############################
            bool esNumero = false;
            qreal valor = campos.at(i).toDouble(&esNumero);
            if ((esNumero) or (campos.at(i).trimmed().isEmpty()))
            {
                std::cout << "Número";
            }
            else
            {
                cout << "Texto";
            }
            std::cout << "" << std::endl;
        }
        fila++;
    }
    //##############################
    ///### Inserción de las variables considerando sus características iniciales
    ///##############################

    archivoCSV.close();
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9
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
<<<<<<< HEAD
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
                if (!conexionCorrectaALaBdTemporal())
                {
                    ///##############################
                    ///### Falló la creación de una conexión correcta a la base de datos temporal
                    ///##############################
                    QMessageBox mensajeNoSePuedeEstablecerLaConexionALaBaseDeDatosTemporal;
                    mensajeNoSePuedeEstablecerLaConexionALaBaseDeDatosTemporal.setText(QString::fromUtf8(noSePuedeEstablecerLaConexionALaBaseDeDatosTemporal));
                    mensajeNoSePuedeEstablecerLaConexionALaBaseDeDatosTemporal.exec();
                    dialogoParaImportarUnArchivoCSV->~DialogoParaImportarArchivosCSV();
=======
        else
        {
            ///##############################
            ///### Se cosntruye y muestra el diálogo para la importación de un archivo CSV
            ///##############################
            dialogoParaImportarUnArchivoCSV = new DialogoParaImportarArchivosCSV();
            dialogoParaImportarUnArchivoCSV->ui->nombreDelArchivoCSVAImportar->setText(nombreDeArchivoCSV.toAscii().data());
            dialogoParaImportarUnArchivoCSV->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
            dialogoParaImportarUnArchivoCSV->show();
            dialogoParaImportarUnArchivoCSV->ui->variablesEnPrimeraFila->setEnabled(true);
            ///##############################
            ///### Se verifica que el formato del archivo CSV seleccionado sea correcto
            ///##############################
            numeroDeVariablesTemporal = 0;
            numeroDeCasosTemporal = 0;
            if (formatoDelArchivoCSVCorrecto(archivoCSVParaImportar))
            {
                numeroDeCasosTemporal = dimensionDeLosDatos.totalDeCasos;
                if (insertarPrimeros99CasosOMenosDelArchivoCSV())
                {
                    ///##############################
                    ///### Definición de acciones--->procedimientos y funciones para el diálogo de importación de archivos CSV
                    ///##############################
                    QObject::connect (dialogoParaImportarUnArchivoCSV->ui->variablesEnPrimeraFila,SIGNAL(clicked()),this,SLOT(insertarPrimeros99CasosOMenosDelArchivoCSV()));
                    QObject::connect (dialogoParaImportarUnArchivoCSV->ui->botonCancelar,SIGNAL(clicked()),this,SLOT(botonCancelarDeLaVentanaDeAnalisisDelArchivoCSVOprimido()));
                    QObject::connect (dialogoParaImportarUnArchivoCSV->ui->botonAceptar,SIGNAL(clicked()),this,SLOT(botonAceptarDeLaVentanaDeAnalisisDelArchivoCSVOprimido()));
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9
                }
                else
                {
                    ///##############################
<<<<<<< HEAD
                    ///### Desplegar el número inicial de variables y casos encontrados en el archivo CSV analizado
                    ///##############################
                    dialogoParaImportarUnArchivoCSV->ui->numeroDeVariables->setText(QString::number(numeroDeVariablesTemporal));
                    dialogoParaImportarUnArchivoCSV->ui->numeroDeCasos->setText(QString::number(numeroDeCasosTemporal));
                    ///##############################
                    ///### Llenar base de datos temporal con los primeros 99 casos -o menos-
                    ///### Estos primeros casos se toman para definir las características iniciales de las variables
                    ///##############################
                    if (!crearBaseDeDatosTemporal(false))
                    {
                        ///##############################
                        ///### Error al crear la base de datos temporal
                        ///##############################
                        QMessageBox mensajeErrorAlCrearLaBaseDeDatosTemporal;
                        mensajeErrorAlCrearLaBaseDeDatosTemporal.setText(QString::fromUtf8(errorAlCrearLaBaseDeDatosTemporal));
                        mensajeErrorAlCrearLaBaseDeDatosTemporal.exec();
                        dialogoParaImportarUnArchivoCSV->~DialogoParaImportarArchivosCSV();
                    }
                    ///##############################
                    ///### Se habilitan los elementos del diálogo para importar archivos CSV
                    ///### necesarios para la interacción con el usuario: checkbox variables en primera fila
                    ///### y botones de aceptar y cancelar
                    ///##############################
                    dialogoParaImportarUnArchivoCSV->ui->variablesEnPrimeraFila->setEnabled(true);
                    dialogoParaImportarUnArchivoCSV->ui->botonCancelar->setEnabled(true);
                    dialogoParaImportarUnArchivoCSV->ui->botonAceptar->setEnabled(true);
                    ///##############################
                    ///### Definición de acciones--->procedimientos y funciones para el diálogo de importación
                    ///### de archivos CSV
                    ///##############################
                    QObject::connect (dialogoParaImportarUnArchivoCSV->ui->variablesEnPrimeraFila,SIGNAL(clicked()),this,SLOT(cambioEnCheckBoxVariablesEnLaPrimeraFila()));
                    QObject::connect (dialogoParaImportarUnArchivoCSV->ui->botonCancelar,SIGNAL(clicked()),this,SLOT(botonCancelarDeLaVentanaDeAnalisisDelArchivoCSVOprimido()));
                    QObject::connect (dialogoParaImportarUnArchivoCSV->ui->botonAceptar,SIGNAL(clicked()),this,SLOT(botonAceptarDeLaVentanaDeAnalisisDelArchivoCSVOprimido()));
=======
                    ///### Error al leer el archivo CSV
                    ///##############################
                    QMessageBox mensajeErrorAlLeerElArchivoCSV;
                    mensajeErrorAlLeerElArchivoCSV.setText(QString::fromUtf8(errorAlLeerElArchivoCSV));
                    mensajeErrorAlLeerElArchivoCSV.exec();
                    dialogoParaImportarUnArchivoCSV->~DialogoParaImportarArchivosCSV();
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9
                }
            }
            else
            {
                ///##############################
<<<<<<< HEAD
                ///### El formato del archivo CSV es incorrecto
=======
                ///### Formato del archivo CSV es incorrecto
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9
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

<<<<<<< HEAD
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
        if (!crearBaseDeDatosTemporal(true))
        {
            ///##############################
            ///### Error al crear la base de datos termporal
            ///##############################
            QMessageBox mensajeErrorAlCrearLaBaseDeDatosTemporal;
            mensajeErrorAlCrearLaBaseDeDatosTemporal.setText(QString::fromUtf8(errorAlCrearLaBaseDeDatosTemporal));
            mensajeErrorAlCrearLaBaseDeDatosTemporal.exec();
            dialogoParaImportarUnArchivoCSV->~DialogoParaImportarArchivosCSV();
        }
        for (unsigned long i=0; i<numeroDeVariablesTemporal; i++)
        {
            modeloDeLaBaseDeDatosTemporalParaDatos->setHeaderData(i, Qt::Horizontal, arregloDeVariablesTemporal.value(i).toString().toAscii().data());
        }
        numeroDeCasosTemporal--;
        dialogoParaImportarUnArchivoCSV->ui->numeroDeCasos->setText(QString::number(numeroDeCasosTemporal));
    }
    else
    {
        if (!crearBaseDeDatosTemporal(false))
        {
            ///##############################
            ///### Error al crear la base de datos termporal
            ///##############################
            QMessageBox mensajeErrorAlCrearLaBaseDeDatosTemporal;
            mensajeErrorAlCrearLaBaseDeDatosTemporal.setText(QString::fromUtf8(errorAlCrearLaBaseDeDatosTemporal));
            mensajeErrorAlCrearLaBaseDeDatosTemporal.exec();
            dialogoParaImportarUnArchivoCSV->~DialogoParaImportarArchivosCSV();
        }
        numeroDeCasosTemporal++;
        dialogoParaImportarUnArchivoCSV->ui->numeroDeCasos->setText(QString::number(numeroDeCasosTemporal));
    }
}

=======
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9
///##############################
///### Procedimiento para cancelar la importación del archivo CSV
///##############################
void VentanaPrincipal::botonCancelarDeLaVentanaDeAnalisisDelArchivoCSVOprimido()
{
<<<<<<< HEAD
    ///##############################
    ///### Regresar el control a la base de datos funcional que está en uso
    ///##############################
    if (baseDeDatosFuncionalEnUso)
    {
        if (!conexionCorrectaALaBdFuncional())
        {
            ///##############################
            ///### Falló la conexión a la base de datos funcional
            ///### y se despliega el error correspondiente
            ///##############################
            QMessageBox mensajeDeErrorNoSePuedeReconectarALaBaseDeDatosFuncional;
            mensajeDeErrorNoSePuedeReconectarALaBaseDeDatosFuncional.setText(QString::fromUtf8(errorNoSePuedeReconectarALaBaseDeDatosFuncional));
            mensajeDeErrorNoSePuedeReconectarALaBaseDeDatosFuncional.exec();
            cerrarConexionALaBdFuncional();
            eliminarArchivoDeLaBdFuncional();
        }
        else
        {
            //##############################
            ///### Actualizar las vistas de la base de datos funcional
            ///##############################
            actualizarVistasDeLaBdFuncional();
        }
    }
    cerrarConexionALaBdTemporal();
=======

>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9
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
<<<<<<< HEAD
    cerrarConexionALaBdTemporal();
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
=======
    ///##############################
    ///### Se llama al destructor del diálogo para importar archivos CSV
    ///##############################
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9
    dialogoParaImportarUnArchivoCSV->~DialogoParaImportarArchivosCSV();
}

#endif // MANEJODEARCHIVOSCSV_H
