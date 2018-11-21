/*
 * =====================================================================================
 *
 *       Filename:  prototipos.h
 *
 *    Description: En este archivo de cabecera se guardan los prototipos de todos los metodos
 *                 numericos clasificados segun la opcion
 *
 *        Version:  1.0
 *        Created:  18/11/18    13:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Martin Enrique Villanueva Serrano ; martitaxco@gmail.com
 *   Organization:  IPN ESIME Zacatenco
 *
 * =====================================================================================
 */

#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

//************************************MENU PRINCIPAL*****************************************************//

 void loc_de_raices();

 void sis_de_ecs();

 void interpolacion();

 void regresion();

 void integracion();

//************************************FUNCIONES*****************************************************//

 double df(double *);

 double f(double);

//************************************LOCALIZACION DE RAICES*****************************************************//

 void Biseccion(double, double, double, int, int, double *, int *, double *);

 void falsa_posicion (double, double, double, int, int, double *, int *, double *);

 void newton_raphson (double, double, int, int, double *, int *, double *);

 void secante (double, double, double, int, int, double *, int *, double *);

 void secante_mejorado (double, double, double, int, int, double *, int *, double *);

 double raiz_falsa_posicion(double, double);

 double raiz_secante (double, double);

 double raiz_secante_mejorada (double, double, double);

//************************************SOLUCION DE SIS DE ECS*****************************************************//

 void Eliminacion_G (double **, double *, int);

 void Sustitucion_G(double **, double *, double *, int);

 void Eliminacion_GM (double **, double *, int, double *, double, double);

 void Sustitucion_GM(double **, double *, double *, int);

 void pivoteo_GM(double **, double *, double *, int, int);

 void Gauss_GM (double **, double *, int, double *, double, double);

 void Gseid (double **, double *, int, double *, int, double, double);

//************************************INTERPOLACION****************************************************//

 void interpolacion_new (double *, double *, int, double , double *, double * );  //int es tam

 void lagrange(double *, double *, int, double);

//************************************REGRESION*****************************************************//

 void regresion_lineal(double *, double *, int, double*, double*, double*, double*);

 void regresion_poli(double *, double *, int, int, double **, double *, double, double);

 void porcentaje_regresion_p(double*, double*, double*, double*, int, int);

//************************************INTEGRACION*****************************************************//

 double trapeciom(double , int , double *);

 double simpson_1_3(double, int, double *);

 double simpson_3_8(double, double, double, double, double);

 double simpson_combiando(int, double *, double);

#endif // PROTOTIPOS_H_INCLUDED
