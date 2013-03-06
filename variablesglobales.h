#ifndef VARIABLESGLOBALES_H
#define VARIABLESGLOBALES_H

///##############################
///### Includes generales
///##############################
#include <dialogoparaguardararchivodedatossiono.h>
#include <dialogoparaimportararchivoscsv.h>
#include <iostream>
#include <QCloseEvent>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <textos.h>
#include <csv.h>
#include <sys/stat.h>
#include <fstream>
#include <QSqlQuery>
<<<<<<< HEAD

//using namespace std;

///##############################
///### Variable de control relativas al manejo de la base de datos funcional
///##############################
bool baseDeDatosFuncionalEnUso;
=======
#include <QTextStream>
#include <QFile>

///##############################
///### Variables de la base de datos
///##############################
bool baseDeDatosEnUso;
<<<<<<< HEAD
QSqlDatabase *baseDeDatos;
QSqlTableModel *modeloParaDatos;
QSqlTableModel *modeloParaVariables;
QString nombreDeLaConexionALaBdFuncional;
DialogoParaGuardarArchivoDeDatosSiONo *guardarBaseDeDatos;
=======
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9
DialogoParaGuardarArchivoDeDatosSiONo *guardarBaseDeDatosFuncional;
QSqlRecord arregloDeVariablesFuncional;
>>>>>>> f969703cb223799254a551f2fe16dfc250f0d13f

///##############################
///### Variables para la importación de un archivo con formato CSV
///##############################
DialogoParaImportarArchivosCSV *dialogoParaImportarUnArchivoCSV;

///##############################
///### Variables de los nombres de los archivos MES y CSV
///##############################
QString nombreDeArchivoCSV;

///##############################
///### Variables de control para el número de variables y casos de las bases de datos temporal y funcional
///##############################
unsigned long numeroDeVariablesTemporal;
unsigned long numeroDeCasosTemporal;
<<<<<<< HEAD
unsigned long numeroDeVariables;
unsigned long numeroDeCasos;
=======
unsigned long numeroDeVariablesFuncional;
unsigned long numeroDeCasosFuncional;

///##############################
///### Variables relativas a la base de datos temporal
///##############################
QSqlDatabase *baseDeDatosTemporal;
QSqlTableModel *modeloDeLaBaseDeDatosTemporalParaDatos;
QSqlTableModel *modeloDeLaBaseDeDatosTemporalParaVariables;
QString nombreDeLaConexionALaBdTemporal;
<<<<<<< HEAD
ifstream archivoDeEntrada;
string linea;
=======
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9

///##############################
///### Variables relativas a la base de datos temporal
///##############################
QSqlDatabase *baseDeDatosFuncional;
QSqlTableModel *modeloDeLaBaseDeDatosFuncionalParaDatos;
QSqlTableModel *modeloDeLaBaseDeDatosFuncionalParaVariables;
QString nombreDeLaConexionALaBdFuncional;
>>>>>>> f969703cb223799254a551f2fe16dfc250f0d13f

///##############################
///### Variables para el control de las consultas a las bases de datos tanto temporal como funcional
///##############################
char consulta[99999];

#endif // VARIABLESGLOBALES_H
