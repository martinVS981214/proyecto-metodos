#include "cabecera.h"
#include "prototipos.h"
#include "matriz.h"

int menu_raices_de_ecs(int eleccion_metodo)
{
    do
    {
        printf("\n\n Seleccione una opcion:\n\n"
                "\n 1.- biseccion"
                "\n 2.- falsa posicion "
                "\n 3.- newton-raphson"
                "\n 4.- secante"
                "\n 5.- secante mejorado"
                "\n 6.- regresar \n");
        scanf("%d",&eleccion_metodo);

        if(eleccion_metodo < 1 || eleccion_metodo > 6)
        {
            printf("\n opcion invalida");
            system("cls");
        }
    }
    while(eleccion_metodo < 1 && eleccion_metodo > 6);
    return eleccion_metodo;
}
