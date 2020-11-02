/*
 * utn.c
 *
 *  Created on: 31 oct. 2020
 *      Author: Leandro
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int getInt(char text[])
{
    int option;
    fflush(stdin);
    printf("%s",text);
    scanf("%d",&option);

    return option;
}

void getString(char mensaje[], char input[])
{
    printf(mensaje);
    fflush(stdin);
    gets(input);
}

int menu()
{
	int opcion=0;
    printf("------------------ALTA|||-BAJA-|||MODIFICACION---------------------\n\n");
    printf("1) Cargar los datos en forma de texto (data.csv)\n");
	printf("2) Cargar los datos en de forma binaria (data.bin)\n");
	printf("3) Alta empleado\n");
	printf("4) Modificar empleado\n");
	printf("5) Baja empleado\n");
	printf("6) Listar empleados\n");
	printf("7) Ordenar empleados\n");
	printf("8) Guardar los datos en forma de texto (data.csv)\n");
	printf("9) Guardar los datos de forma binaria (data.bin)\n");
	printf("10) Salir\n");
	printf("\n\ningrese la opcion: ");
	fflush(stdin);
    scanf("%d",&opcion);
    fflush(stdin);

    return opcion;
}












