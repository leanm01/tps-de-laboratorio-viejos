/*
 * empleados.h
 *
 *  Created on: 9 may. 2021
 *      Author: Leandro
 */

#ifndef EMPLEADOS_H_
#define EMPLEADOS_H_

typedef struct
{

	int idEmpleado;
    char nombre[25];
    char apellido[25];
	int salario;
	int sector;
	int isEmpty;

}eEmpleado;
/** \brief estructura para el empleado
 *
 * \param
 * \param
 * \return 
 *
 */

int initEmpleados(eEmpleado arrayEmpleado[], int tamArray);
/** \brief funcion que inicializa empleados
 *
 * \param
 * \param
 * \return devuelve si se inicio o no un empleado
 *
 */
int agregarEmpleados(eEmpleado arrayEmpleado[], int tamArray, int contador);
/** \brief funcion que agrega o crea empleados
 *
 * \param
 * \param
 * \return devuelve al empleado que se agrego
 *
 */
int mostrarEmpleados(eEmpleado arrayEmpleado[] ,int tamArray);
/** \brief funcion que muestra empleados
 *
 * \param
 * \param
 * \return devuelve a los empleados para mostrarlos
 *
 */
int mostrarEmpleado(eEmpleado arrayEmpleado[] ,int i);
/** \brief funcion que muestra solo un empleado
 *
 * \param
 * \param
 * \return devuelve al empleado para mostrarlo
 *
 */
int modificacionEmpleados(eEmpleado arrayEmpleado[], int tamArray);
/** \brief funcion que modifica empleados
 *
 * \param
 * \param
 * \return devulve al empleado modificado
 *
 */
int bajaEmpleado(eEmpleado arrayEmpleado[], int tamArray);
/** \brief funcion que da de baja empleados
 *
 * \param
 * \param
 * \return devulve el espacio libre del empleado eliminado
 *
 */
int ordenamientoEmpleados(eEmpleado arrayEmpleado[], int tamArray);
/** \brief funcion que ordena empleados
 *
 * \param
 * \param
 * \return devuelve a los empleados ordenados
 *
 */
void promedioTotal(eEmpleado arrayEmpleado[], int tamArray);
/** \brief funcion que saca el promedio total
 *
 * \param
 * \param
 * \return devuelve el promedio total
 *
 */

#endif /* EMPLEADOS_H_ */
