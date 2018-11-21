/*
 * =====================================================================================
 *
 *       Filename:  integracion.c
 *
 *    Description: Se muestran las opciones disponibles al seleccionar la opcion
 *                 "integracion" en el menu principal.
 *
 *                 las funciones para esta opcion se encuentran en el archivo:
 *                 func_integracion.c
 *
 *        Version:  1.0
 *        Created:  17/11/18    21:50
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

void integracion()
{
    double *y;                        //VECTOR QUE GUARDA LA EVALUACION DE CADA VALOR DEL INTERVALO
    double a, b, h, area;             //h PASO DE INTEGRACION
    int tam, i, eleccion_metodo;

    do
    {
        printf("\n\n Seleccione una opcion:\n\n"
                "\n 1.- Regla del trapecio"
                "\n 2.- Regla simpson 1/3 multiple (se requiere un numero par de segmentos)"
                "\n 3.- Regla de simpson combinada"
                "\n 4.- Regresar \n");
        scanf("%d",&eleccion_metodo);

        if(eleccion_metodo < 1 || eleccion_metodo > 4)
        {
            printf("\n opcion invalida");
            system("cls");
        }
    }
    while(eleccion_metodo < 1 && eleccion_metodo > 4);

    if(eleccion_metodo == 4)
    {
        system("cls");
    }

    else
    {
        system("cls");
        printf("\n Dar el inicio del intervalo deseado (a)\n");
        scanf("%lf",&a);
        printf("\n Dar el fin del intervalo deseado (b)\n");
        scanf("%lf",&b);

        if(eleccion_metodo == 1 || eleccion_metodo == 3)
        {
            printf("\n Dar el numero de segmentos\n");
            scanf("%d",&tam);
        }

        if(eleccion_metodo == 2)
        {
            do
            {
                printf("\n Dar el numero de segmentos\n");
                scanf("%d",&tam);

                if(tam%2 != 0 )
                {
                    printf("\n %d no es par. introduce otro numero",tam);
                }
            }
            while (tam%2 != 0);
        }
        y = crear_vector(tam + 1);
        h = (b - a) / tam;

        for(i = 0 ; i <= tam ; i++)
        {
            y[i] = f(a + i * h);
        }

        if(eleccion_metodo == 1)
        {
            area = trapeciom(h, tam, y);
            printf("\n el valor de la integral desde %lf hasta %lf es:  %lf\n\n", a, b, area);
        }

        if(eleccion_metodo == 2)
        {
            area = simpson_1_3(h, tam, y);
            printf("\n el valor de la integral desde %lf hasta %lf es:  %lf\n\n", a, b, area);
        }

        if(eleccion_metodo == 3)
        {
            area = simpson_combiando(tam, y, h);
            printf("\n el valor de la integral desde %lf hasta %lf es:  %lf\n\n", a, b, area);
        }

        destruye_vector(y);
    }
}

