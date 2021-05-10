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

int initEmpleados(eEmpleado arrayEmpleado[], int tamArray);

int agregarEmpleados(eEmpleado arrayEmpleado[], int tamArray, int contador);

int mostrarEmpleados(eEmpleado arrayEmpleado[] ,int tamArray);

int mostrarEmpleado(eEmpleado arrayEmpleado[] ,int i);

int modificacionEmpleados(eEmpleado arrayEmpleado[], int tamArray);

int bajaEmpleado(eEmpleado arrayEmpleado[], int tamArray);

int ordenamientoEmpleados(eEmpleado arrayEmpleado[], int tamArray);

void promedioTotal(eEmpleado arrayEmpleado[], int tamArray);

#endif /* EMPLEADOS_H_ */
