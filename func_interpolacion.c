/*
 * =====================================================================================
 *
 *       Filename:  func_interpolacion.c
 *
 *    Description: Se muestran las funciones utilizadas para los distintos metodos de
 *                 interpolacion
 *
 *        Version:  1.0
 *        Created:  17/11/18    21:27
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

//*********************************INTERPOLACION NEWTON*****************************************************//

void interpolacion_new (double *x, double *y, int tam, double x_aproximado, double *y_aproximado, double *error_apro )
{

    double **FDD;

    /*
    * FDD es una matriz donde se guardan los valores de la tabla para realizar la interpolacion de Newton
    *
    * El resultado de la interpolacion se guarda en el ultimo valor de y_aproximado
    */

    double x_term, y2;
    int i, j, order;

    FDD = crear_matriz(tam,tam);
    for(i=0 ; i < tam ; i++)
    {
        for(j = 0 ; j < tam ; j++)
        {
            FDD[i][j] = 0;
        }
    }

    for(i = 0 ; i < tam ; i++)
    {
        FDD[i][0] = y[i];
    }

    for(j = 1 ; j < tam ; j++)
    {
        for(i = 0 ; i < tam - j ; i++)
        {
            FDD[i][j] = (FDD[i + 1][j - 1] - FDD[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    y_aproximado[0] = FDD[0][0];
    x_term = 1;

    for(order=1 ; order < tam ;order++)
    {
        x_term = x_term * (x_aproximado - x[order-1]);

        y2 = y_aproximado[order-1] + FDD[0][order] * x_term;

        error_apro[order - 1] = (y2 - y_aproximado[order-1]) / y2 * 100;

        y_aproximado[order] = y2;

        printf(" %d dif dividida:  y = %11.6lf       ea = %11.6lf \n", order, y_aproximado[order], error_apro[order-1]);
    }
}

//*******************************INTERPOLACION LAGRANGE*****************************************************//

void lagrange(double *x, double *y, int tam, double x_buscado)
{
    double suma, producto;
    int i, j;

    suma = 0;
    for(i=0 ; i < tam ;i++)
    {
        producto = y[i];
        for(j=0 ; j < tam ; j++)
        {
            if(i != j)
                producto = producto * (x_buscado - x[j]) / (x[i] - x[j]);
        }
        suma = suma + producto;
    }
    printf("\n y = %11.6lf \n",suma);
}
