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
#include "sqlite3.h"

//using namespace std;

///##############################
///### Variable de control relativas al manejo de la base de datos funcional
///##############################
bool baseDeDatosFuncionalEnUso;
DialogoParaGuardarArchivoDeDatosSiONo *guardarBaseDeDatosFuncional;
QSqlRecord arregloDeVariablesFuncional;
sqlite3 * db;
char * sErrMsg = 0;

///##############################
///### Variables para la importación de un archivo con formato CSV
///##############################
DialogoParaImportarArchivosCSV *dialogoParaImportarUnArchivoCSV;
QSqlRecord arregloDeVariablesTemporal;

///##############################
///### Variables de los nombres de los archivos MES y CSV
///##############################
QString nombreDeArchivoCSV;

///##############################
///### Variables de control para el número de variables y casos de las bases de datos temporal y funcional
///##############################
unsigned long numeroDeVariablesTemporal;
unsigned long numeroDeCasosTemporal;
unsigned long numeroDeVariablesFuncional;
unsigned long numeroDeCasosFuncional;

///##############################
///### Variables relativas a la base de datos temporal
///##############################
QSqlDatabase *baseDeDatosTemporal;
QSqlTableModel *modeloDeLaBaseDeDatosTemporalParaDatos;
QSqlTableModel *modeloDeLaBaseDeDatosTemporalParaVariables;
QString nombreDeLaConexionALaBdTemporal;
ifstream archivoDeEntrada;
string linea;

///##############################
///### Variables relativas a la base de datos temporal
///##############################
QSqlDatabase *baseDeDatosFuncional;
QSqlTableModel *modeloDeLaBaseDeDatosFuncionalParaDatos;
QSqlTableModel *modeloDeLaBaseDeDatosFuncionalParaVariables;
QString nombreDeLaConexionALaBdFuncional;

///##############################
///### Variables para el control de las consultas a las bases de datos tanto temporal como funcional
///##############################
char consulta[99999];

#endif // VARIABLESGLOBALES_H
