/*
 * =====================================================================================
 *
 *       Filename:  func_raices_abiertos.c
 *
 *    Description: Se muestran las funciones utilizadas para los distintos metodos de
 *                 raices abiertos
 *
 *        Version:  1.0
 *        Created:  17/11/18    21:32
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

//************************************NEWTON-RAPHSON*****************************************************//

void newton_raphson (double xi, double es, int imax, int res, double *apraiz, int *api, double *apea)
{
    double xrold = xi;
    *api = 0;
    if(res==1)
    {
        printf("\n i  |     xi     |     xr     |     ea     ");
        printf("\n--------------------------------------------------------");
    }

    do
    {
        *apraiz = xrold - f(xrold) / df(&xrold);
        *api = *api + 1;

        if(*apraiz != 0)
            {
                *apea = fabs( (*apraiz - xrold) / (*apraiz) ) * 100;
            }

        if(res == 1)
        {
             printf("\n%3d | %10.6lf | %10.6lf | %10.6lf",*api,xrold,*apraiz,*apea);
        }

        xrold = *apraiz;
    }
    while(*apea > es && *api <= imax);
}

//************************************SECANTE*****************************************************//

void secante (double xl, double xu, double es, int imax, int res, double  *apraiz, int *api, double *apea)
{
    *api = 0;

    if(res == 1)
    {
        printf("\n i  |     xl     |     xu     |     xr     |     ea     ");
        printf("\n--------------------------------------------------------");
    }

    do{
        *apraiz = raiz_secante(xu,xl);
        *api = *api + 1;

        if(res == 1)
        {
             printf("\n%3d | %10.6lf | %10.6lf | %10.6lf | %10.6lf",*api, xl, xu, *apraiz, *apea);
        }

        if(*apraiz != 0)
        {
            *apea = fabs( (*apraiz - xl) / (*apraiz) ) * 100;
        }

        xl = xu;
        xu = *apraiz;

    }
    while(*apea > es && *api <= imax);
}

double raiz_secante (double xu, double xl)
{
    return xu - (f(xu) * (xl-xu)) / (f(xl) - f(xu));
}

//************************************SECANTE MEJORADO*****************************************************//

void secante_mejorado(double xi, double x_dec, double es, int imax, int res, double  *apraiz, int *api, double *apea)
{
    double x_sum_dec, factor;           //x_sum_dec es una suma, solo que su tipo de dato es real (double)

    *api=0;
    factor = xi + x_dec;

    if(res==1)
    {
        printf("\n decimal : %lf \n",x_dec);
        printf("\n i  |     xi     |    xi+dec     |     xr     |     ea     ");
        printf("\n------------------------------------------------------------");
    }

    do
    {
        *api = *api + 1;
        x_sum_dec = xi * factor;
        *apraiz = raiz_secante_mejorada(xi, x_dec, x_sum_dec);

        if(*apraiz != 0)
        {
            *apea = fabs( (*apraiz - xi) / (*apraiz) )*100;
        }

        if(res==1)
        {
             printf("\n%3d | %10.6lf |  %10.6lf   | %10.6lf | %10.6lf\n",*api, xi, x_sum_dec, *apraiz, *apea);
        }

        xi = *apraiz;

    }
    while(*apea > es && *api <= imax);

}

double raiz_secante_mejorada (double xi, double x_dec,double x_sum_dec)
{
    return xi - (x_dec * xi * f(xi)) / (f(x_sum_dec) - f(xi));
}
