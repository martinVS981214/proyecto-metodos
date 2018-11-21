/*
 * =====================================================================================
 *
 *       Filename:  formulas para raices.c
 *
 *    Description: Se muestran funciones que contienen las formulas para obtener las
 *                 raices de algunos metodos
 *
 *        Version:  1.0
 *        Created:  17/11/18 16:54
 *       Revision:  none
 *       Compiler:  GCC
 *
 *         Author:  Martin Enrique Villanueva Serrano ; martitaxco@gmail.com
 *   Organization:  IPN ESIME Zacatenco
 *
 * =====================================================================================
 */

#include "cabecera.h"
#include "prototipos.h"
#include "matriz.h"




double raiz_secante_mejorada (double xi, double x_dec,double x_sum_dec)
{
    return xi - (x_dec * xi * f(xi)) / (f(x_sum_dec) - f(xi));
}
