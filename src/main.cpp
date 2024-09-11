#include "View.h"

int main()
{
    View menu;
    bool archivosParametrizados = menu.pantallaBienvenido();
    if (archivosParametrizados)
    {
        menu.visualizacionDatosExtra();
        menu.buscarPorPalabraClaveYFormacion();
    }
    menu.salir();
    return 0;
}