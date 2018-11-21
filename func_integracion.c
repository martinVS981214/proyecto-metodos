/*
 * =====================================================================================
 *
 *       Filename:  func_integracion.c
 *
 *    Description: Se muestran las funciones utilizadas para los distintos metodos de
 *                 integracion
 *
 *        Version:  1.0
 *        Created:  17/11/18   21:26
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

//************************************TRAPECIO*****************************************************//

double trapeciom(double h, int n, double *f)
{

    double sum ;
    int i;

    sum = f[0];
    for(i=1 ; i < n ; i++)
    {
        sum =sum + 2 * f[i];
    }
    sum = sum + f[n];

    return h * sum / 2;
}

//************************************SIMPSON 1/3*****************************************************//

double simpson_1_3(double h, int n, double *f)
{

    double sum;
    int i;

    sum = f[0];
    for(i = 1 ; i < n - 2 ; i = i + 2)
    {
        sum = sum + 4 * f[i] + 2 * f[i+1];
    }
    sum = sum + 4 * f[n-1] + f[n];

    return h * sum / 3;
}

//************************************SIMPSON COMBINADO*****************************************************//

double simpson_combiando(int n, double *f, double h)
{

    double suma = 0, odd;
    int m, entero;

    if(n == 1)
        suma = trapeciom(h,n,f);
    else
    {
        m = n;
        entero = (int)n / 2;
        odd = n / 2.0 - entero;
        if(odd > 0 && n > 1)
        {
            suma = suma + simpson_3_8(h, f[n-3], f[n-2], f[n-1], f[n]);
            m = n - 3;
        }
        if(m > 1)
        {
            suma = suma + simpson_1_3(h,m,f);
        }
    }
    return suma;
}

double simpson_3_8(double h, double f0, double f1, double f2, double f3)
{
    return 3 * h * (f0 + 3 * (f1+f2) + f3) / 8;
}


