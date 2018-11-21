/*
 * =====================================================================================
 *
 *       Filename:  funciones.c
 *
 *    Description: Se muestra la funcion utilizada para todos los metodos numericos que
 *                 requieran el uso de una funcion o su derivada (localizacion de raices
 *                 e integracion)
 *
 *                 Las funciones pueden ser modificadas
 *
 *        Version:  1.0
 *        Created:  17/11/18    21:40
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

//************************************FUNCION ORIGINAL*****************************************************//

double f(double x)
{
    return sin(x + 2) - 0.2;
}

//************************************DERIVADA DE LA FUNCION ORIGINAL*****************************************************//

double df(double *x)
{
    return cos(*x + 2);
}












