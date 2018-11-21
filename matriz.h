/*
 * =====================================================================================
 *
 *       Filename:  matriz.h
 *
 *    Description: En este archivo de cabecera se guardan los prototipos de aquellas funciones
 *                 que tengan relacion con la lectura, impresion, creacion y destruccion
 *                 de matrices o vectores
 *
 *        Version:  1.0
 *        Created:  18/11/18    13:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Martin Enrique Villanueva Serrano ; martitaxco@gmail.com
 *   Organization:  IPN ESIME Zacatenco
 *
 * =====================================================================================
 */

#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

//************************************CREACION*****************************************************//

 double ** crear_matriz (int filas, int columnas );

 double * crear_vector (int tam );

 //************************************LECTURA*****************************************************//

 void lee_matriz ( double **m, int filas, int columnas );

 void lee_vector ( double *v, int tam );

 //************************************IMPRESION*****************************************************//

 void imprime_matriz ( double **m, int filas, int columnas );

 void imprime_matriz_aumentada ( double **a, double *b, int tam );

 void imprime_vector ( double *, int);

 //************************************DESTRUCCION*****************************************************//

 void destruye_vector ( double *v );

 void destruye_matriz(double **m, int filas, int columnas);

#endif // MATRIZ_H_INCLUDED
