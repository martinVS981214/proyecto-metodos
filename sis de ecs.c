/*
 * =====================================================================================
 *
 *       Filename:  sis de ecs.c
 *
 *    Description: Se muestran las opciones disponibles al seleccionar la opcion
 *                 "sistemas de ecuaciones" en el menu principal.
 *
 *                 las funciones para esta opcion se encuentran en el archivo:
 *                 func_sis ecuaciones.c
 *
 *        Version:  1.0
 *        Created:  18/11/18    12:59
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

void sis_de_ecs()
{
    double **A, *B, *X;
    double error, tolerancia = 0, lambda;                         //
    int imax, i, er, tam, eleccion_metodo;

    do
    {
        printf("\n\n Seleccione una opcion:\n\n"
                "\n 1.- Gauss"
                "\n 2.- Gauss modificado "
                "\n 3.- Gauss-Seidel "
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
        printf("dame el numero de ecuaciones;  ");
        scanf("%d",&tam);
        A=crear_matriz(tam, tam);
        B=crear_vector(tam);
        X=crear_vector(tam);

        for(i = 0 ; i < tam ; i++)
        {
            X[i] = 0;
        }
        i = 0;

        printf("\n introduce los valores de las ecuaciones\n\n");
        lee_matriz(A, tam, tam);
        lee_vector(B, tam);

        if(eleccion_metodo == 3)
        {
            printf("\n Ingrese el error maximo: ");
            scanf("%lf",&error);
            printf("\n Ingrese el no max de iteraciones: ");
            scanf("%d",&imax);
            printf("\n introduce un factor ponderado (entre 0 y 2):  ");
            scanf("%lf",&lambda);
        }

        printf("\n Matriz original\n");
        imprime_matriz_aumentada (A, B, tam );

        if(eleccion_metodo == 1)
        {
            Eliminacion_G(A, B, tam);

            printf("\n Matriz tras eliminacion\n");
            imprime_matriz_aumentada (A, B, tam );

            Sustitucion_G(A,B,X,tam);
        }

        else if(eleccion_metodo == 2)
        {
            Gauss_GM(A, B, tam, X, tolerancia, er);
        }

        else if(eleccion_metodo == 3)
        {
            Gseid(A,B,tam,X,imax,error,lambda);
        }

        imprime_vector(X,tam);

        destruye_vector(B);
        destruye_vector(X);
        destruye_matriz(A,tam,tam);

        printf("\n\n");
    }
}
