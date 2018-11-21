/*
 * =====================================================================================
 *
 *       Filename:  interpolacion.c
 *
 *    Description: Se muestran las opciones disponibles al seleccionar la opcion
 *                 "interpolacion" en el menu principal.
 *
 *                 las funciones para esta opcion se encuentran en el archivo:
 *                 func_interpolacion.c
 *
 *        Version:  1.0
 *        Created:  17/11/18    21:51
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

void interpolacion()
{

    double *x, *y;                                      //VECTORES QUE GUARDAN LOS PUNTOS INICIALES
    double x_aproximado, *y_aproximado, *error_apro;
    int i, tam, eleccion_metodo;

    do
    {
        printf("\n\n Seleccione una opcion:\n\n"
                "\n 1.- Interpolacion de newton "
                "\n 2.- Interpolacion de Lagrange"
                "\n 3.- Regresar \n");
        scanf("%d",&eleccion_metodo);

        if(eleccion_metodo < 1 || eleccion_metodo > 3)
        {
            printf("\n opcion invalida");
            system("cls");
        }
    }
    while(eleccion_metodo < 1 && eleccion_metodo > 3);

    if(eleccion_metodo == 3)
    {
        system("cls");
    }
    else
    {
        system("cls");
        printf("\n ingresa el numero de puntos dados  ");
        scanf("%d",&tam);

        x = crear_vector(tam);
        y = crear_vector(tam);

        printf("\n ingresa los puntos conocidos");
        for(i = 0 ; i < tam ; i++)
        {
            printf("\n\n punto %d \n"
                   " x = ", i + 1);
            scanf("%lf",&x[i]);

            printf("\n y = ");
            scanf("%lf",&y[i]);
        }

        printf("\n que punto desea encontrar?  ");
        scanf("%lf", &x_aproximado);

        if(eleccion_metodo == 1)
        {
            y_aproximado = crear_vector(tam);
            error_apro = crear_vector(tam);
        }

        system("cls");
        printf("\n x buscado = %11.6lf"
               "\n datos conocidos\n"
               "       x               y\n"
               "_______________________________\n", x_aproximado);
        for(i = 0 ; i < tam ; i++)
        {
            printf(" %11.6lf     %11.6lf \n", x[i], y[i]);
        }

        if(eleccion_metodo == 1)
        {
            printf("\n\n");
            interpolacion_new (x, y, tam, x_aproximado, y_aproximado, error_apro  );

            destruye_vector(y_aproximado);
            destruye_vector(error_apro);
        }

        if(eleccion_metodo == 2)
        {
            printf("\n\n");
            lagrange(x, y, tam, x_aproximado);
        }

        destruye_vector(x);
        destruye_vector(y);
    }
}

