/*
 * =====================================================================================
 *
 *       Filename:  func_sis ecuaciones.c
 *
 *    Description: Se muestran las funciones utilizadas para los distintos metodos de
 *                 resolucion de sistemas de ecuaciones lineales
 *
 *        Version:  1.0
 *        Created:  17/11/18    21:36
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

//********************************************GAUSS*********************************************//
void Eliminacion_G (double **A, double *B, int n)
{
    int k, i, j;
    double factor;
    n = n - 1;                                   //esta operacion es para permitir el uso de <= en el manejo del vector

    for(k=0 ; k <= n ; k++)
    {
        for (i = k+1 ; i <= n ; i++)
        {
            factor = A[i][k] / A[k][k];
            for(j = k + 1 ; j <= n ; j++)
            {
                A[i][j] = A[i][j] - factor * A[k][j];
            }
            B[i] = B[i] - factor * B[k];
        }
    }
}

void Sustitucion_G(double **A, double *B, double *X, int n)
{
    double sum;
    int i,j;
    n = n-1;                                //esta operacion es para permitir el uso de <= en el manejo del vector

    X[n] = B[n] / A[n][n];
    for(i = n - 1 ; i >= 0 ; i--)
    {
        sum = B[i];
        for(j = i + 1 ; j <= n ; j++)
        {
            sum = sum - A[i][j] * X[j];
        }
    X[i] = sum / A[i][i];
    }
}

//****************************************GAUSS MODIFICADO**************************************//

void Gauss_GM (double **A, double *B, int n, double *X, double tolerancia, double er)
{
    double *S;
    int i, j;

    S = crear_vector(n);    //Vector que guardan valores para realizar el pivoteo
    er = 0;
    n = n - 1;

    for(i = 0 ; i <= n ; i++)
    {
        S[i] = fabs(A[i][1]);

        for(j = 1 ; j <= n ; j++)
        {
            if( fabs( A[i][j] ) > S[i] )
                S[i] = fabs(A[i][j]);
        }
    }

    Eliminacion_GM(A, B, n, S, tolerancia, er);

    /*n=n+1;
    printf("\n Matriz tras eliminacion\n");                    Operacion para mostrar didacticamente el sistema con la
    imprime_matriz_aumentada (A, B, n );                       eliminacion hacia atras finalizada
    n=n-1;*/

    if(er != -1)
    {
        Sustitucion_GM(A, B, X, n);
    }
}

void pivoteo_GM(double **A, double *B, double *S , int tam, int k)
{
    int p;
    int ii, jj;                          //variables para cambiar de fila y columna
    double big, dummy;

    p = k;
    big = fabs( A[k][k] / S[k] );
    for(ii = k+1 ; ii <= tam ; ii++)
    {
        dummy = fabs(A[ii][k] / S[ii]);

        if(dummy > big)
        {
            big = dummy;
            p = ii;
        }
    }
    if(p != k)
    {
        for(jj = k ; jj <= tam ; jj++)
        {
            dummy = A[p][jj];
            A[p][jj] = A[k][jj];
            A[k][jj] = dummy;
        }

        dummy = B[p];
        B[p] = B[k];
        B[k] = dummy;

        dummy = S[p];
        S[p] = S[k];
        S[k] = dummy;
    }
}

void Eliminacion_GM (double **A, double *B, int n, double *S, double toleracia, double er)
{
    double factor;
    int i, j, k;

    for(k = 0 ; k <= n ; k++)
    {
        pivoteo_GM(A, B, S, n, k);
        if(fabs((A[k][k]) / (S[k])) < toleracia)
        {
            er = -1;
            k = n+200000000000;                   //operacion realizada para salir del for en linea 120
        }
        for(i = k + 1 ; i <= n ; i++)
        {
            factor = A[i][k]/A[k][k];
            for(j = k + 1; j <= n ; j++)
            {
                A[i][j] = A[i][j] - factor * A[k][j];
            }
            B[i] = B[i] - factor * B[k];
        }
    }
    if(fabs(A[n][n] / S[n]) < toleracia)
    {
        er = -1;
    }
}
void Sustitucion_GM(double **A, double *B, double *X, int n)
{
    int i, j;
    double sum;

    X[n] = B[n] / A[n][n];

    for(i = n - 1 ; i >= 0 ; i--)
    {
        sum = B[i];
        for(j = i + 1 ; j <= n ; j++)
        {
            sum = sum - A[i][j] * X[j];
        }
        X[i] = sum / A[i][i];
    }
}

//**********************************GAUSS SEIDEL************************************************//

void Gseid (double **A, double *B, int n, double *X, int imax, double es, double lambda)
{
    int i, j, iter, sentinel;              //iter maneja las iteraciones del metodo, mientras i es de la matriz
    double dummy, sum, ea, old;

    for(i = 0 ; i < n ; i++)
    {
        dummy = A[i][i];

        for(j = 0 ; j < n ; j++)
        {
            A[i][j] = A[i][j] / dummy;
        }

        B[i] = B[i] / dummy;
    }

    for(i = 0 ; i < n ; i++)
    {
        sum = B[i];
        for(j = 0 ; j < n ; j++)
        {
            if(i != j)
                sum = sum - A[i][j] * X[j];
        }
        X[i] = sum;
    }
    iter = 1;
    do
    {
        sentinel = 1;
        for(i = 0 ; i < n ; i++)
        {
            old = X[i];
            sum = B[i];

            for(j = 0 ; j < n ; j++)
            {
                if(i != j)
                    sum = sum - A[i][j] * X[j];
            }
            X[i]= lambda * sum + (1 - lambda) * old;
            if((sentinel = 1) && (X[i] != 0))
            {
                ea = fabs(((X[i]-old) / X[i]) * 100);
                if(ea > es)
                    sentinel = 0;
            }
        }
        iter = iter + 1;
    }
    while(sentinel != 1 && iter <= imax);
}









