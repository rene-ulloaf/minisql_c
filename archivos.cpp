#include <stdlib.h>
#include <fstream>

#include "estructuras.h"
#include "TDAListaTabla.h"
#include "archivos.h"

using namespace std;

/*Funcion que valida si existe el archivo de entrada, retorna verdadero o falso*/
bool clsArchivos :: existe(char* nombre){
	ifstream fin;
	fin.open(nombre);

	if(!fin.is_open()){
		fin.close();
		return false;
	}else{
		fin.close();
		return true;
	}
}

bool clsArchivos :: ValidaTablas(char *arch){
	ifstream f;
    string s;
    int l,i;

    f.open(arch, ios::in);
    if(f.is_open()){
		while(!f.eof()){
            f >> s;
			l = s.length();

            for(i=0;i<l;i++){
                if(!isdigit(s[i])){
                    return false;
                }
            }

			f >> s;
			if(s == ""){
                return false;
            }
		}

		f.close();
	}

    return true;
}

ListaTablas* clsArchivos :: ObtenerTablas(char *arch, ListaTablas *tablas){
    DatosTablas tabla;
	ifstream f;
    string s;

    clsTDAListaTabla TDALT;

    f.open(arch, ios::in);
    if(f.is_open()){
		while(!f.eof()){
            f >> s;
			tabla.id = convertir(s);
			f >> s;
			tabla.nombre = convertir(s);
		}

		f.close();
	}

	tablas = TDALT.ingresar(tabla,(tablas->ultimo+1),tablas);

    return tablas;
}

bool CreaArchivoTablas(ListaTablas *tablas){
    int cant = tablas->ultimo;

    while(cant > 0){

        cant--;
    }
}

char* clsArchivos :: convertir(string s){
    int i,cant;
    char *c=NULL;

    c = (char *) malloc(sizeof(char) + s.length());
    cant = s.length();

    for(i=0;i<cant;i++){
        c[i] = s[i];
    }

    return c;
}
