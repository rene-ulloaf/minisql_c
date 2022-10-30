# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <vector>
# include <fstream>
# include <sstream>
# include <string.h>
# include <math.h>
#include <sys/types.h>

using namespace std;

bool existe(char*);

int main ( int argc, char *argv[] ){
	/*Se realiza la validación de los argumentos de entrada con la funcion mediante getopt*/
	int tFlag=0, iFlag=0, oFlag=0, c;
	char *tValue=NULL, *iValue=NULL, *oValue=NULL;   
	int opterr = 0;   

	/*Se declaran 2 banderas d y f cada una de estos requiere valores */  
	while ((c = getopt (argc, argv, "t:i:o:")) != -1){
		switch (c){
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
				}else{
					fprintf (stderr,"Caracter desconocido de la función `\\x%x'.\n", optopt);
				}

             			return -10;
			default:
				abort ();
		}
	}

	/*Se valida la existencia de la bandera -d y -f*/
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
	if (!existe(iValue)){
		fprintf (stderr,"El archivo: '[%s]' no existe \n", iValue);
		return -7;
	}

	if (!existe(iValue)){
		fprintf (stderr,"El archivo: '[%s]' no es válido \n", iValue);
		return -8;
	}

	if (!existe(oValue)){
		fprintf (stderr,"Imposible reconocer formato de archivo: '[%s]'\n", oValue);
		return -9;
	}

	/*Se valida que las funciones sean correctas*/
	/*if(funciones[0] == "error"){
		fprintf (stderr,"El archivo: [%s] no es válido \n", fvalue);
		return -6;
	}*/

	/*Se valida que los datos sean correctos*/
	/*if(datos[0] == "error"){
		fprintf (stderr,"El archivo: [%s] no es válido \n", dvalue);
		return -6;
	}*/
}

/*Funcion que valida si existe el archivo de entrada, retorna verdadero o falso*/
bool existe(char* nombre){
	ifstream fin;
	fin.open(nombre);

	if (!fin.is_open()){
		fin.close();
		return false;
	}else{
		fin.close();
		return true;
	}
}
