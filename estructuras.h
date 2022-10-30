#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED

typedef struct str_datos{
    char* idDato;
    char *nombDato;
} Datos;

typedef struct str_nodo_datos{
    Datos elemDato;
    struct str_nodo_datos *sgteDato;
} NodoDatos;

typedef struct str_Lista_datos{
    NodoDatos *iniDato;
    int ultDato;
} ListaDatos;

typedef struct str_tablas{
	char *id;
    char *nombre;
    ListaDatos datos;
} DatosTablas;

typedef struct str_nodo_tablas{
    DatosTablas elem;
    struct str_nodo_tablas *sgte;
} NodoTablas;

typedef struct str_Lista_tablas{
    NodoTablas *inicial;
    int ultimo;
} ListaTablas;

#endif // ESTRUCTURAS_H_INCLUDED
