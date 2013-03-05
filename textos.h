#ifndef TEXTOS_H
#define TEXTOS_H

///##############################
///### Textos de la aplicación en idioma español
///##############################

///##############################
///### Errores relativos al proceso de importación de un archivo CSV
///##############################
const char *errorAlIntentarAbrirElArchivoCSV = "Error al intentar abrir el archivo CSV";
const char *errorDeInicializacionDelAnalizadorDelArchivoCSV = "Error al inicializar el analizador del archivo CSV";
const char *formatoIncorrectoDelArchivoCSV = "Formato incorrecto del archivo CSV";
<<<<<<< HEAD
const char *noSePuedeEstablecerLaConexionALaBaseDeDatosTemporal = "No se puede establecer la conexión con la base de datos temporal - Intente borrar manualmente el archivo <<<baseDeDatosTemporal>>>";
const char *errorAlCrearLaBaseDeDatosTemporal = "Error al crear la base de datos temporal - Intente borrar manualmente el archivo <<<baseDeDatosTemporal>>>";
const char *errorAlBorrarArchivoDeDatosTemporal = "No se puede borrar el archivo temporal de datos <<<baseDeDatosTemporal>>> - Eliminarlo manualmente y reiniciar mes";
const char *errorNoSePuedeCrearLaBaseDeDatosFuncional = "No se puede crear la base de datos funcional";
const char *errorAlCrearLaBaseDeDatosFuncional = "Error al crear la base de datos funcional <<<baseDeDatosFuncional>>> - Eliminarlo manualmente y reiniciar mes";
const char *errorAlBorrarArchivoDeDatosFuncional = "No se puede borrar el archivo funcional de datos <<<baseDeDatosFuncional>>> - Eliminarlo manualmente y reiniciar mes";
const char *errorNoSePuedeReconectarALaBaseDeDatosFuncional = "Falló la reconexión al archivo funcional de datos <<<baseDeDatosFuncional>>> - Eliminarlo manualmente y reiniciar mes";
=======
const char *errorAlLeerElArchivoCSV = "Error al leer el archivo CSV";
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9

///##############################
///### Etiquetas del tipo de las variables
///##############################
const char *texto = "Texto";
const char *numerico = "Numérico";

///##############################
///### Etiquetas de la escala de las variables
///##############################
const char *escala = "Escala";
const char *ordinal = "Ordinal";
const char *nominal = "Nominal";

///##############################
///### Errores relativos al proceso apertura de un archivo de datos mes
///##############################

///##############################
///### Estadísticas descriptivas univariadas
///##############################

#endif // TEXTOS_H
