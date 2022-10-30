#include <cstdlib>
#include <string.h>
#include <iostream>
#include <fstream>

#include "estructuras.h"
#include "TDAListaTabla.h"
#include "archivos.h"

using namespace std;

int main(int argc, char *argv[]){
	/*Se realiza la validación de los argumentos de entrada con la funcion mediante getopt*/
	int tFlag=0, iFlag=0, oFlag=0, c;
	char *tValue=NULL, *iValue=NULL, *oValue=NULL;
    ListaTablas *lt = NULL;

    clsTDAListaTabla TDALT;
	clsArchivos arch;

	/*Se declaran 3 banderas t ,i  y o cada una de estos requiere valores */
	while((c = getopt (argc, argv, "t:i:o:")) != -1){
		switch(c){
			case 't':
				tFlag = 1;
				tValue = optarg;
			break;
			case 'i':
				iFlag = 1;
				iValue = optarg;
			break;
				case 'o':
		 		oFlag = 1;
				oValue = optarg;
		   	break;
			case '?':
				if (optopt == 't'){
					fprintf (stderr, "Uso válido: ./minisql -t [hebra] -i [archivo_consulta] -o [archivo_salida]\n");
					return -4;
				}else if (optopt == 'i'){
		   		fprintf (stderr, "Uso válido: ./minisql -t [hebra] -i [archivo_consulta] -o [archivo_salida]\n");
					return -5;
				}else if (optopt == 'o'){
		   		fprintf (stderr, "Uso válido: ./minisql -t [hebra] -i [archivo_consulta] -o [archivo_salida]\n");
					return -6;
				}else if (isprint (optopt)){
					fprintf (stderr, "Opción desconocida `-%c'.\n", optopt);
					return -10;
				}else{
					fprintf (stderr,"Caracter desconocido de la función `\\x%x'.\n", optopt);
					return -10;
				}
			default:
				abort ();
		}
	}

	/*Se valida la existencia de la bandera -t, -i y -o*/
	if (tFlag == 0) {
		fprintf (stderr, "Uso válido: ./minisql -t [hebra] -i [archivo_consulta] -o [archivo_salida]\n");
		return -1;
	}

	if (iFlag == 0){
		fprintf (stderr, "Uso válido: ./minisql -t [hebra] -i [archivo_consulta] -o [archivo_salida]\n");
		return -2;
	}

	if (oFlag == 0){
		fprintf (stderr, "Uso válido: ./minisql -t [hebra] -i [archivo_consulta] -o [archivo_salida]\n");
		return -3;
	}

	/*Se valida que exista los valores de los archivos de entrada*/
	if (!arch.existe(iValue)){
		fprintf (stderr,"El archivo: '[%s]' no existe \n", tValue);
		return -7;
	}

	if (!arch.ValidaTablas(iValue)){
		fprintf (stderr,"El archivo: '[%s]' no es válido \n", iValue);
		return -8;
	}

	if (!arch.ValidaTablas(iValue)){
		fprintf (stderr,"Imposible reconocer formato de archivo: '[%s]'\n", oValue);
		return -9;
	}

	lt = TDALT.creaLista();
	lt = arch.ObtenerTablas(iValue, lt);
}
