/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description: Se muestra el menu principal. Aqui se seleccionara el tipo de operacion
 *                 que se quiera realizar.
 *
 *        Version:  1.0
 *        Created:  17/11/18    22:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Martin Enrique Villanueva Serrano ; martitaxco@gmail.com
 *   Organization:  IPN ESIME Zacatenco
 *
 * =====================================================================================
 */

#include "cabecera.h"
#include "prototipos.h"
#include "matriz.h"

int main()
{

    int eleccion_op, eleccion_metodo = 0;

    do
    {
        printf("\n seleccione lo que quiera realizar"
               "\n 1.- raices de ecuaciones"
               "\n 2.- sistemas de ecuaciones"
               "\n 3.- interpolacion (grafica que toque todos los puntos)"
               "\n 4.- regresion (grafica que se acerque a los puntos, no necesariamente tocarlos)"
               "\n 5.- integracion "
               "\n 99.- SALIR\n");
        scanf("%d",&eleccion_op);

        if (eleccion_op == 1)                                                  //raices de ecuaciones
        {
            loc_de_raices();   //el codigo esta en el archivo loc de raices.c
        }

        else if(eleccion_op == 2)                                             //sistemas de ecuacones
        {
            sis_de_ecs();     // el codigo esta en el archivo sis de ecs.c
        }

        else if(eleccion_op == 3)                                            //interpolacion
        {
            interpolacion(); //el codigo esta en el archivo interpolacion.c
        }

        else if(eleccion_op == 4)                                            //regresion
        {
            regresion();     //el codigo esta en el archivo regresion.c
        }

        else if(eleccion_op == 5)                                           //integracion
        {
            integracion();   //el codigo esta en el archivo integracion.c
        }

    }
    while(eleccion_op != 99);
    return 0;
}
