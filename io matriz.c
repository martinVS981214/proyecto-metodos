/*
 * =====================================================================================
 *
 *       Filename:  io matriz.c
 *
 *    Description: Se muestra la definicion de todas las funciones que tengan relacion
 *                 con la lectura, impresion, creacion y destruccion de matrices o vectores
 *
 *        Version:  1.0
 *        Created:  17/11/18    21:55
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

//************************************CREACION*****************************************************//

double * crear_vector (int tam )
{
    double *v;
    v = (double *) malloc(tam * sizeof(double));
    return v;
}

double **crear_matriz (int filas, int columnas )
{
    double **m;
    int j;

    m = (double **) malloc(filas * sizeof(double *));

    for(j = 0 ; j < filas ; j++)
        m[j] = (double *)malloc(columnas * sizeof(double));

    return m;
}

//************************************LECTURA*****************************************************//

void lee_vector ( double *v, int tam )
{
    int i;
    for (i = 0; i < tam; i++) {
        printf("\nDar el elemento [%d] = ", i+1);
        scanf("%lf",&v[i]);
    }
}

void lee_matriz ( double **m, int filas, int columnas )
{
    int i, j;
    double dato;

    for ( i = 0 ; i < filas ; i++ )
    {
        for (j = 0 ; j < columnas ; j++ )
        {
            printf("Dar el elemento [%d,%d]: ", i+1, j+1);
            scanf("%lf", &dato);
            m[i][j] = dato;
        }
        printf("\n");
    }
}

//************************************IMPRESION*****************************************************//

void imprime_vector ( double *v, int tam )
{
    int i;

    for (i = 0; i < tam; i++) {
        printf("x[%d] = [ %11.6lf ] \n", i+1, v[i]);
    }
}

void imprime_matriz ( double **m, int filas, int columnas )
{
    int i, j;

    for (i = 0 ; i < filas ; i++ )
    {
        for (j = 0 ; j < columnas ; j++ )
        {
            printf("[ %11.6lf ] ", m[i][j]);
        }
        printf("\n");
    }
}

void imprime_matriz_aumentada ( double **a, double *b, int tam )
{
    int i, j;

    for (i = 0 ; i < tam ; i++ )
        {
            for (j = 0 ; j < tam ; j++ )
            {
                printf("[ %11.6lf ] ", a[i][j]);
            }
        printf(" = [ %11.6lf ]", b[i]);
        printf("\n");
    }
}

//************************************DESTRUCCION*****************************************************//

void destruye_vector ( double *v )
{
    free(v);
}

void destruye_matriz(double **m, int filas, int columnas)
{
    int j;

    for(j = 0 ; j < filas ; j++)
        free(m[j]);

    free(m);
    return;
}


