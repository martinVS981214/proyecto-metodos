/*
 * =====================================================================================
 *
 *       Filename:  func_regresion.c
 *
 *    Description: Se muestran las funciones utilizadas para los distintos metodos de
 *                 regresion
 *
 *        Version:  1.0
 *        Created:  17/11/18    21:35
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

//************************************LINEAL*****************************************************//

void regresion_lineal(double *x, double *y, int tam, double *a1, double *a0, double *syx, double *r2)
{
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0, st = 0, sr = 0;
    double x_media, y_media;
    int i;

    for(i=0 ; i < tam ; i++)
    {
        sum_x = sum_x + x[i];
        sum_y = sum_y + y[i];
        sum_xy = sum_xy + x[i] * y[i];
        sum_x2 = sum_x2 + x[i] * x[i];
    }

    x_media = sum_x / tam;
    y_media = sum_y / tam;

    *a1 = (tam * sum_xy - sum_x * sum_y) / (tam * sum_x2 - sum_x * sum_x);
    *a0 = y_media - (*a1) * x_media;

    for(i=0 ; i < tam ; i++)
    {
        st = st + pow((y[i] - y_media),2);
        sr = sr + pow((y[i] - (*a1) * x[i] - *a0),2);
    }

    *syx = pow((sr / (tam - 2)),0.5);
    *r2 = (st - sr) / st;
}

//*****************************************POLINOMIAL*********************************************//

void regresion_poli(double *x, double *y, int tam, int grado, double **A, double *X, double tol, double er)
{
    int i, j, k, e;
    double sum, *resultados;

    resultados = crear_vector(grado+1);

    for(i=0 ; i < grado+1 ;i++)                            //coeficientes e las ecuaciones lineales
    {
        for(j=0 ; j <= i ; j++)
        {
            k = (i+1) + (j+1) - 2;
            sum = 0;
            for(e=0 ; e < tam ; e++)
            {
                sum = sum + pow(x[e],k);
            }
            A[i][j] = sum;
            A[j][i] = sum;
        }
        sum = 0;
        for(e=0 ; e < tam ; e++)
        {
            sum = sum +y[e]*(pow(x[e],(i+1)-1));
        }
        A[i][grado+2] = sum;
    }

    for(i=0 ; i < grado + 1 ; i++)                          //resultados sistema de ecuaciones simultaneas
    {
        sum = 0;
        for(e = 0 ; e < tam ; e++)
        {
            sum = sum + y[e] * pow(x[e],(i+1) - 1);
        }
        resultados[i]=sum;
    }

    Gauss_GM(A,resultados, grado+1, X, tol, er);
}

void porcentaje_regresion_p(double *x, double *y, double*X, double *r_cuadrado, int tam, int grado)
{
    /*
    * esta funcion es usada para determinar el porcentaje con el que se acerca la
    * funcion calculada en regresion polinomial a los puntos dados inicialmente
    */

    double suma_1 = 0, suma_2 = 0, y_media, sum_media, *s_1, *s_2;
    int i, j;

    sum_media = 0;
    s_1 = crear_vector(tam);
    s_2 = crear_vector(tam);

    for(i = 0 ; i < tam ; i++)         //inicializacion de ambos vectores a 0 para evitar indeterminaciones
    {
        s_2[i] = 0;
        s_1[i] = 0;
    }

    for(i = 0 ; i < tam ; i++)
    {
        s_1[i] = y[i];
        for(j = 0 ; j < grado + 1 ; j++)
        {
            s_2[i] = s_2[i] + X[j] * pow(x[i],j);
        }
        sum_media = sum_media + y[i];
    }

    y_media = sum_media / tam;

    for(i = 0 ; i < tam ; i++)
    {
        suma_1 = suma_1 + pow(y[i] - y_media,2);
        suma_2 = suma_2 + pow(s_1[i] - s_2[i],2);
    }

    *r_cuadrado = (suma_1-suma_2) / suma_1 * 100;
}

