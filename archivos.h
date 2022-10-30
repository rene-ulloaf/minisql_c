#ifndef archivos_H_INCLUDED
#define archivos_H_INCLUDED

using namespace std;

class clsArchivos{
    public:
        bool existe(char *);
        bool ValidaTablas(char *);
        ListaTablas* ObtenerTablas(char *, ListaTablas *);
    private:
        char* convertir(string);
};

#endif // archivos_H_INCLUDED
