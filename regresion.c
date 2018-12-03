/*
 * =====================================================================================
 *
 *       Filename:  regresion.c
 *
 *    Description: Se muestran las opciones disponibles al seleccionar la opcion
 *                 "regresion" en el menu principal.
 *
 *                 las funciones para esta opcion se encuentran en el archivo:
 *                 func_regresion.c
 *
 *        Version:  1.0
 *        Created:  17/11/18    22:31
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

/** \brief regresion muestra el procedimiento posterior a elegir "regresion" en el menu principal
 *         aqui se elige entre las distintas formas de encontrar una ecuacion. posterior
 *         a elegir una opcion, se solicitan los parametros para realizar cada opcion
 *
 */

void regresion()
{
    double *x, *y;
    int tam, i, grado_polinomio, er, eleccion_metodo;
    double a0, a1, s_yx, r_cuadrado, tolerancia = 0;

    do
    {
        printf("\n\n Seleccione una opcion:\n\n"
                "\n 1.- Regresion lineal"
                "\n 2.- Regresion polinomial"
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

        printf("\n introduce el numero de puntos dados  ");
        scanf("%d",&tam);

        x = crear_vector(tam);
        y = crear_vector(tam);

        printf("\n dame los puntos conocidos");
        for(i = 0 ; i < tam ; i++)
        {
            printf("\n\n punto %d \n"
                   " x = ", i+1);
            scanf("%lf",&x[i]);

            printf("\n y = ");
            scanf("%lf",&y[i]);
        }

        if(eleccion_metodo == 2)
        {
            do
            {
                system("cls");
                printf("\n introduce el grado del polinomio (el grado tiene que ser menor o igual a %d )\n", tam-1);
                scanf("%d",&grado_polinomio);

                if(tam < grado_polinomio + 1)
                    printf("\n la regresion no es posible ");
            }
            while (tam < grado_polinomio + 1);
        }

        system("cls");
        printf("\n datos conocidos\n"
               "       x               y\n"
               "_______________________________\n");

        for(i = 0 ; i < tam ; i++)
        {
            printf(" %11.6lf     %11.6lf \n", x[i], y[i]);
        }

        printf("\n\n");

        if(eleccion_metodo == 1)
        {
            regresion_lineal(x, y, tam, &a1, &a0, &s_yx, &r_cuadrado);
            printf(" la ecuacion es: \n"
                   " %11.6lf + %11.6lf x \n"
                   " \n se representa a los puntos en un %11.6lf % \n", a0, a1, r_cuadrado * 100.0);
        }

        else if(eleccion_metodo == 2)
        {
            /*
            * A es una matriz utilizada para obtener los coeficientes de la
            * ecuacion que representa la regresion
            *
            * Los coeficientes de la ecuacion se guardaran en X
            */

            double **A, *X;

            A = crear_matriz(grado_polinomio+1, grado_polinomio+1);
            X = crear_vector(grado_polinomio+1);

            regresion_poli(x, y, tam, grado_polinomio, A, X, tolerancia, er); //aqui esta el error

            printf("\n\n la ecuacion es: \n");

            for(i = 0 ; i < grado_polinomio + 1 ; i++)
            {
                printf("(%11.6lfx^%d) +", X[i], i);
            }
            printf("  0\n\n");


            porcentaje_regresion_p(x, y, X, &r_cuadrado, tam, grado_polinomio);

            printf("la ecuacion representa los puntos en un %11.6lf \n\n", r_cuadrado);

            destruye_vector(X);
            destruye_matriz(A, grado_polinomio + 1, grado_polinomio + 1);
        }

        destruye_vector(x);
        destruye_vector(y);
    }
}

