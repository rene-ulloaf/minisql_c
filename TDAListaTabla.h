#ifndef TDALISTATABLA_H_INCLUDED
#define TDALISTATABLA_H_INCLUDED

using namespace std;

class clsTDAListaTabla{
    public:
        //typedef int posicion;
        NodoTablas *creaNodo(DatosTablas);
        ListaTablas *creaLista();
        ListaTablas *ingresar(DatosTablas, int, ListaTablas *);
        int localizar(DatosTablas, ListaTablas *);
        ListaTablas *modificar(int, DatosTablas, ListaTablas *);
        DatosTablas *recuperar(int, ListaTablas *);
        ListaTablas *eliminar(ListaTablas *, int);
        DatosTablas tope(ListaTablas *);
        int CantidadProd(ListaTablas *);
        short esIgual(DatosTablas, char *);
        DatosTablas *copiarDato(NodoTablas *);
    private:
};

#endif // TDALISTATABLA_H_INCLUDED
