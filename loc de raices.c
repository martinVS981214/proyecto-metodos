/*
 * =====================================================================================
 *
 *       Filename:  loc de raices.c
 *
 *    Description: Se muestran las opciones disponibles al seleccionar la opcion
 *                 "raices de ecuaciones" en el menu principal.
 *
 *                 las funciones para esta opcion se encuentran en los archivos:
 *                 func_raices_abiertos.c y func_raices_cerrados.c
 *
 *        Version:  1.0
 *        Created:  17/11/18    22:09
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

void loc_de_raices()
{

    double xa, xb, error, raiz, ea, lambda;
    int imax, i, res, eleccion_metodo;

    do
    {

        /*
        * Los metodos BISECCION y FALSA POSICION son metodos CERRADOS
        *
        * Los metodos NEWTON-RAPHSON, SECANTE y SECANTE MEJORADO
        * son meotodos ABIERTOS
        */

        printf("\n\n Seleccione una opcion:\n\n"
                "\n 1.- Biseccion"
                "\n 2.- Falsa posicion "
                "\n 3.- Newton-Raphson"
                "\n 4.- Secante"
                "\n 5.- Secante mejorado"
                "\n 6.- Regresar \n");
        scanf("%d",&eleccion_metodo);

        if(eleccion_metodo < 1 || eleccion_metodo > 6)
        {
            printf("\n opcion invalida");
            system("cls");
        }
    }
    while(eleccion_metodo < 1 && eleccion_metodo > 6);

    if(eleccion_metodo == 6)
    {
        system("cls");
    }
    else
    {
        if (eleccion_metodo == 1 || eleccion_metodo == 2)
        {
            do
            {
                system("CLS");
                printf("\n Ingrese el dato mayor del intervalo: ");
                scanf("%lf",&xa);
                printf("\n Ingrese el dato menor del intervalo: ");
                scanf("%lf",&xb);
            }
            while(f(xa) * f(xb) > 0);
        }

        else if (eleccion_metodo == 3)
        {
            system("CLS");
            printf("\n Ingrese el valor inicial: ");
            scanf("%lf",&xa);
        }

        else if (eleccion_metodo == 4)
        {
            system("CLS");
            printf("\n Ingrese el dato mayor del intervalo: ");
            scanf("%lf",&xa);
            printf("\n Ingrese el dato menor del intervalo: ");
            scanf("%lf",&xb);
        }

        else if (eleccion_metodo == 5)
        {
            do
            {
                system("CLS");
                printf("\n Ingrese el valor inicial: ");
                scanf("%lf",&xa);
                printf("\n Ingrese un numero entre 0 y 1: ");
                scanf("%lf",&lambda);
            }
            while (lambda >= 1 && lambda <= 0);
        }

        printf("\n Ingrese el error maximo: ");
        scanf("%lf",&error);
        printf("\n Ingrese el no max de iteraciones: ");
        scanf("%d",&imax);
        printf("\nDesea tabular los resultados?: (si=1/no=0)");
        scanf("%d",&res);


        if(eleccion_metodo == 1)
            Biseccion(xb, xa, error, imax, res, &raiz, &i, &ea);

        else if(eleccion_metodo == 2)
            falsa_posicion(xb, xa, error, imax, res, &raiz, &i, &ea);

        else if(eleccion_metodo == 3)
            newton_raphson(xa, error, imax, res, &raiz, &i, &ea);

        else if(eleccion_metodo == 4)
            secante(xb, xa, error, imax, res, &raiz, &i, &ea);

        else if (eleccion_metodo == 5)
            secante_mejorado(xa, lambda, error, imax, res, &raiz, &i, &ea);


        printf("\n\nLa raiz es: %lf", raiz);
        printf("\nCon un error de: %lf", ea);
        printf("\nIteraciones: %d\n\n", i);
    }
}
