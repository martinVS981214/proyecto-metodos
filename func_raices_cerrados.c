/*
 * =====================================================================================
 *
 *       Filename:  func_raices_cerrados.c
 *
 *    Description: Se muestran las funciones utilizadas para los distintos metodos de
 *                 raices cerrados
 *
 *        Version:  1.0
 *        Created:  17/11/18    21:29
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

//*************************************BISECCION*****************************************************//

void Biseccion(double xl, double xu, double es, int imax, int res, double *apraiz, int *api, double *apea)
{

    double xrold, test;

    *api = 0;

    if(res == 1)
    {
        printf("\n i  |     xl     |     xu     |     xr     |     ea     ");
        printf("\n--------------------------------------------------------");
    }

    do
    {
        xrold = *apraiz;
        *apraiz = (xl+xu) / 2;
        *api = *api + 1;

        if(*apraiz != 0)
        {
            *apea = fabs( (*apraiz - xrold) / (*apraiz) ) * 100;
        }

        if(res == 1)
        {
             printf("\n%3d | %10.6lf | %10.6lf | %10.6lf | %10.6lf", *api, xl, xu, *apraiz, *apea);
        }

        test = f(xl) * f(*apraiz);
        if(test < 0)
        {
            xu = *apraiz;
        }
        else if(test > 0)
        {
            xl = *apraiz;
        }
        else
        {
            *apea = 0;
        }
    }while(*apea > es && *api <= imax);

}

//************************************FALSA POSICION*****************************************************//

void falsa_posicion(double xl, double xu, double es, int imax, int res, double *apraiz, int *api, double *apea)
{

    double xrold, test;

    *api = 0;

    if(res == 1)
    {
        printf("\n i  |     xl     |     xu     |     xr     |     ea     ");
        printf("\n--------------------------------------------------------");
    }

    do
    {
        xrold = *apraiz;
        *apraiz = raiz_falsa_posicion(xu, xl);
        *api = *api + 1;

        if(*apraiz != 0)
        {
            *apea = fabs( (*apraiz - xrold) / (*apraiz) ) * 100;
        }

        if(res == 1)
        {
             printf("\n%3d | %10.6lf | %10.6lf | %10.6lf | %10.6lf", *api, xl, xu, *apraiz, *apea);
        }

        test = f(xl) * f(*apraiz);
        if(test < 0)
        {
            xu = *apraiz;
        }
        else if(test > 0)
        {
            xl = *apraiz;
        }
        else
        {
            *apea = 0;
        }
    }
    while(*apea > es && *api <= imax);
}

double raiz_falsa_posicion(double xu, double xl)
{
    return xu - (f(xu) * (xl - xu)) / (f(xl) - f(xu));
}


