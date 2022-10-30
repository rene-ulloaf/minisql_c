#include <stdlib.h>
#include <string.h>

#include "estructuras.h"
#include "TDAListaTabla.h"
/*#include "recursos.h"*/

using namespace std;

ListaTablas * clsTDAListaTabla :: creaLista(){
   ListaTablas *Lista = (ListaTablas *) malloc(sizeof(ListaTablas));

   if(Lista != NULL){
       Lista->ultimo = 0;
       Lista->inicial = NULL;
   }

   return Lista;
}

NodoTablas * clsTDAListaTabla :: creaNodo(DatosTablas p){
   NodoTablas *nuevo = (NodoTablas *) malloc(sizeof(NodoTablas));

	if(nuevo != NULL){
     	nuevo->sgte = NULL;
		nuevo->elem.id = p.id;
     	nuevo->elem.nombre = p.nombre;
   }

   return nuevo;
}

ListaTablas * clsTDAListaTabla :: ingresar(DatosTablas p, int pos, ListaTablas *L){
    int i;
    NodoTablas *nuevo = creaNodo(p);
    NodoTablas *aux = L->inicial;

    if((pos > L->ultimo+1) || (pos < 0)){
        pos = L->ultimo;
    }

    if(pos == 1){
        nuevo->sgte = L->inicial;
        L->inicial = nuevo;
        L->ultimo++;
    }else{
        for(i=2;i<pos;i++){
            aux = aux->sgte;
        }

        nuevo->sgte = aux->sgte;
        aux->sgte = nuevo;
        L->ultimo++;
    }

    return L;
}

int clsTDAListaTabla :: localizar(DatosTablas p, ListaTablas *L){
    int pos=0,pos_ret=0;
    NodoTablas *aux = L->inicial;

    while(aux != NULL){
        pos++;

        if(esIgual(p,aux->elem.id)){
           pos_ret = pos;
        }

        aux=aux->sgte;
    }

    return pos_ret;
}

ListaTablas * clsTDAListaTabla :: modificar(int pos, DatosTablas p, ListaTablas *L){
    int i;
    NodoTablas *aux = L->inicial;

    if((pos < L->ultimo + 1) || (pos > 0)){
        if(pos == 1){
			aux->elem.id = p.id;
            aux->elem.nombre = p.nombre;
        }else{
            for(i=1;i<pos;i++){
                aux = aux->sgte;
            }

			aux->elem.id = p.id;
            aux->elem.nombre = p.nombre;
        }
    }

    return L;
}

DatosTablas * clsTDAListaTabla :: recuperar(int pos, ListaTablas *L){
    int i;
    DatosTablas *p;
    NodoTablas *aux = L->inicial;

    if((pos>L->ultimo + 1) || (pos < 0)){
        pos = L->ultimo;
    }

    if(pos == 1){
        p = copiarDato(L->inicial);
    }else{
        for(i=1;i<pos;i++){
            aux = aux->sgte;
        }

        p = copiarDato(aux);
    }

    return p;
}

ListaTablas * clsTDAListaTabla :: eliminar(ListaTablas *L, int pos){
    int i;
    NodoTablas *aux = L->inicial;
    NodoTablas *ant;

    if(L != NULL){
        if((pos > 0) && (pos <= L->ultimo)){
            if(pos == 1){
                L->inicial->sgte = NULL;
            }else{
                for(i=2;i<=pos;i++){
                    ant = aux;
                    aux = aux->sgte;
                }

                ant->sgte = aux->sgte;
                L->ultimo--;
            }

            free(aux);
        }
    }

    return L;
}

DatosTablas clsTDAListaTabla :: tope(ListaTablas *L){
    return L->inicial->elem;
}

int clsTDAListaTabla :: CantidadProd(ListaTablas *L){
    return L->ultimo;
}

short clsTDAListaTabla :: esIgual(DatosTablas p, char *id){
    short ret = 0;

    if(strcmp(p.id,id) == 0){
        ret = 1;
    }

    return ret;
}

DatosTablas * clsTDAListaTabla :: copiarDato(NodoTablas *n){
    DatosTablas *nuevo = (DatosTablas *)  malloc(sizeof(NodoTablas));

	nuevo->id = n->elem.id;
    nuevo->nombre = n->elem.nombre;
    nuevo->datos = n->elem.datos;

    return nuevo;
}
