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
///### Procedimiento para insertar los primeros 99 casos -o menos- del archivo CSV
///##############################
bool VentanaPrincipal::insertarPrimeros99CasosOMenosDelArchivoCSV()
{
    unsigned long totalDeCasosLeidos;
    unsigned long fila;

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
        QString line = cadena.readLine();
        numeroDeCasosTemporal--;
    }
    ///##############################
    ///### Desplegado del nombre del archivo, numero de variables, numero de casos y configuración del numero de columnas y filas
    ///### de las tablas de variables y de datos
    ///##############################
    dialogoParaImportarUnArchivoCSV->ui->nombreDelArchivoCSVAImportar->setText(nombreDeArchivoCSV.toAscii().data());
    dialogoParaImportarUnArchivoCSV->ui->numeroDeVariables->setText(QString::number(numeroDeVariablesTemporal));
    dialogoParaImportarUnArchivoCSV->ui->numeroDeCasos->setText(QString::number(numeroDeCasosTemporal));
    dialogoParaImportarUnArchivoCSV->ui->tablaDeVariablesTemporal->setRowCount(numeroDeVariablesTemporal);
    (numeroDeCasosTemporal < 99)
        ? dialogoParaImportarUnArchivoCSV->ui->tablaDeDatosTemporal->setRowCount(numeroDeCasosTemporal)
        : dialogoParaImportarUnArchivoCSV->ui->tablaDeDatosTemporal->setRowCount(99);
    dialogoParaImportarUnArchivoCSV->ui->tablaDeDatosTemporal->setColumnCount(numeroDeVariablesTemporal);
    ///##############################
    ///### Llenado de la tabla de datos temporal
    ///##############################
    totalDeCasosLeidos = 0;
    fila = 0;
    while(!cadena.atEnd())
    {
        QString linea = cadena.readLine();
        QStringList campos = linea.split(",");
        for (int i = 0; i < campos.size(); ++i)
        {
            QTableWidgetItem *dato=new QTableWidgetItem (campos.at(i).toLocal8Bit().constData());
            dialogoParaImportarUnArchivoCSV->ui->tablaDeDatosTemporal->setItem(i, fila, dato);
        }
        fila++;
    }
    archivoCSV.close();
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
        else
        {
            ///##############################
            ///### Se cosntruye y muestra el diálogo para la importación de un archivo CSV
            ///##############################
            dialogoParaImportarUnArchivoCSV = new DialogoParaImportarArchivosCSV();
            dialogoParaImportarUnArchivoCSV->ui->nombreDelArchivoCSVAImportar->setText(nombreDeArchivoCSV.toAscii().data());
            dialogoParaImportarUnArchivoCSV->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
            dialogoParaImportarUnArchivoCSV->show();
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
                    QObject::connect (dialogoParaImportarUnArchivoCSV->ui->variablesEnPrimeraFila,SIGNAL(clicked()),this,SLOT(cambioEnCheckBoxVariablesEnLaPrimeraFila()));
                    QObject::connect (dialogoParaImportarUnArchivoCSV->ui->botonCancelar,SIGNAL(clicked()),this,SLOT(botonCancelarDeLaVentanaDeAnalisisDelArchivoCSVOprimido()));
                    QObject::connect (dialogoParaImportarUnArchivoCSV->ui->botonAceptar,SIGNAL(clicked()),this,SLOT(botonAceptarDeLaVentanaDeAnalisisDelArchivoCSVOprimido()));
                }
                else
                {
                    ///##############################
                    ///### Error al leer el archivo CSV
                    ///##############################
                    QMessageBox mensajeErrorAlLeerElArchivoCSV;
                    mensajeErrorAlLeerElArchivoCSV.setText(QString::fromUtf8(errorAlLeerElArchivoCSV));
                    mensajeErrorAlLeerElArchivoCSV.exec();
                    dialogoParaImportarUnArchivoCSV->~DialogoParaImportarArchivosCSV();
                }
            }
            else
            {
                ///##############################
                ///### Formato del archivo CSV es incorrecto
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
    ///### Se llama al destructor del diálogo para importar archivos CSV
    ///##############################
    dialogoParaImportarUnArchivoCSV->~DialogoParaImportarArchivosCSV();
}

#endif // MANEJODEARCHIVOSCSV_H
