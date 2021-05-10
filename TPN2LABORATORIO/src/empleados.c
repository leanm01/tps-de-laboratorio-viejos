/*
 * empleados.c
 *
 *  Created on: 9 may. 2021
 *      Author: Leandro
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "empleados.h"
#include "UTN.h"

int initEmpleados(eEmpleado arrayEmpleado[], int tamArray)
{
    int i;
    int resultado=-1;


       if (tamArray !=0)
        {
            for (i=0;i<tamArray;i++)
            {
            	arrayEmpleado[i].isEmpty=1;
                resultado=0;
            }
        }

        return resultado;
}
int agregarEmpleados(eEmpleado arrayEmpleado[], int tamArray, int contador)
{
    int resultado=0;
    int espacioLibre=-1;
    int i;
    /////
    if (tamArray >0)
    {
        for (i=0;i<tamArray;i++)
        {
            if (arrayEmpleado[i].isEmpty==1)
            {

                espacioLibre=i;

                break;
            }
        }
    }

    if(espacioLibre>=0)
    {



    	    utn_getNombre("\nIngrese el nombre: ","\nIngrese un nombre correcto: ",arrayEmpleado[espacioLibre].nombre,2,25);

    	    utn_getNombre("\nIngrese el apellido: ","\nIngrese un apellido correcto: ",arrayEmpleado[espacioLibre].apellido,2,25);

            utn_getInt("\nIngrese el salario: ","\nIngresa un valor correcto 0-99999: ",&arrayEmpleado[espacioLibre].salario,2,99999,0);

            utn_getInt("\nIngrese el sector: ","\nIngresa un valor correcto 0-999: ",&arrayEmpleado[espacioLibre].sector,2,999,0);


            arrayEmpleado[espacioLibre].idEmpleado=contador+1;
            arrayEmpleado[espacioLibre].isEmpty=0;


            resultado=1;
    }



    return resultado;
}
int mostrarEmpleados(eEmpleado arrayEmpleado[] ,int tamArray)
{

    int i;
    int resultado=-1;
    if(arrayEmpleado != NULL && tamArray>=0)
    {
        for(i=0;i<tamArray;i++)
        {
            if(arrayEmpleado[i].isEmpty==0)
            {
            	mostrarEmpleado(arrayEmpleado,i);
            }

       }
       resultado=1;
    }

    return resultado;
}
int mostrarEmpleado(eEmpleado arrayEmpleado[] ,int i)
{
   printf("\nNOMBRE:%s---APELLIDO:%s---SALARIO:%d---SECTOR:%d---ID:%d\n",  arrayEmpleado[i].nombre,
		   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   arrayEmpleado[i].apellido,
																		   arrayEmpleado[i].salario,
																		   arrayEmpleado[i].sector,
																		   arrayEmpleado[i].idEmpleado);


    return 1;
}
int modificacionEmpleados(eEmpleado arrayEmpleado[], int tamArray)
{

    int retorno=-2;
    int opcionMod;
    int i;
    int aux;
    char auxChar;

    mostrarEmpleados(arrayEmpleado,tamArray);

    utn_getInt("\nIngrese el ID  del usuario que quiera modificar: ","\nIngresa un valor correcto 0-999: ",&aux,2,999,0);


    if(tamArray > 0 && arrayEmpleado != NULL)
    {
        for(i=0;i<tamArray;i++)
        {
            if(aux==arrayEmpleado[i].idEmpleado && arrayEmpleado[i].isEmpty==0)
            {
            	mostrarEmpleado(arrayEmpleado,i);
                utn_getChar("\nDesea modificar este usuario(s--O--n): ","\nIngrese la opcion correcta entre(s--O--n): ",&auxChar,2);

                if(auxChar=='s')
                {
                    opcionMod=modificar();

                    switch(opcionMod)
                    {
                            case 1:
                        	    utn_getNombre("\nIngrese el nombre: ","\nIngrese un nombre correcto: ",arrayEmpleado[i].nombre,2,25);
                                break;
                            case 2:
                        	    utn_getNombre("\nIngrese el apellido: ","\nIngrese un apellido correcto: ",arrayEmpleado[i].apellido,2,25);
                                break;
                            case 3:
                                utn_getInt("\nIngrese el salario: ","\nIngresa un valor correcto 0-99999: ",&arrayEmpleado[i].salario,2,99999,0);
                                break;
                            case 4:
                                utn_getInt("\nIngrese el sector: ","\nIngresa un valor correcto 0-999: ",&arrayEmpleado[i].sector,2,999,0);
                                break;

                    }
                    retorno=1;
                    break;
                }
            }
        }

    }


    return retorno;
}
int bajaEmpleado(eEmpleado arrayEmpleado[], int tamArray)
{
    int aux;
    char auxChar;
    int i;
    int resultado = 0;

    mostrarEmpleados(arrayEmpleado,tamArray);

    utn_getInt("\nIngrese el legajo  del usuario que quiere dar de baja: ","\nIngresa un valor correcto 0-999: ",&aux,2,999,0);

    for(i=0;i<tamArray;i++)
    {
        if(aux==arrayEmpleado[i].idEmpleado && arrayEmpleado[i].isEmpty==0)
        {
        	mostrarEmpleado(arrayEmpleado,i);
            utn_getChar("\nDesea elimnar este usuario(s--O--n): ","\nIngrese la opcion correcta entre(s--O--n): ",&auxChar,2);

            if(auxChar=='s')
            {
            	arrayEmpleado[i].isEmpty=1;
                resultado=1;
                break;
            }
        }
    }
    return resultado;
}
int ordenamientoEmpleados(eEmpleado arrayEmpleado[], int tamArray)
{
	eEmpleado auxiliarEmpleado;

	int i;
    int j;
    char auxiliarOpcion[50];
    int opcion;

    printf("\n\nComo desea ordenar la lista? 1-POR APELLIDO / 2-POR SECTOR: ");
    fflush(stdin);
    gets(auxiliarOpcion);
    while(esNumerico(auxiliarOpcion)==0)
    {
        printf("\nUsted ha ingresado una opcion incorrecta. Ingrese nuevamente: ");
        fflush(stdin);
        gets(auxiliarOpcion);
    }
    opcion=atoi(auxiliarOpcion);
    switch(opcion)
    {
    case 1:
        for(i=0; i<tamArray-1; i++)
        {
            for(j=i+1; j<tamArray; j++)
            {
                if(strcmp(arrayEmpleado[i].apellido,arrayEmpleado[j].apellido))
                {
                    auxiliarEmpleado=arrayEmpleado[i];
                    arrayEmpleado[i]=arrayEmpleado[j];
                    arrayEmpleado[j]=auxiliarEmpleado;
                }
            }
        }
        break;
    case 2:
        for(i=0; i<tamArray-1; i++)
        {
            for(j=i+1; j<tamArray; j++)
            {
                if(arrayEmpleado[i].sector > arrayEmpleado[j].sector)
                {
                    auxiliarEmpleado=arrayEmpleado[i];
                    arrayEmpleado[i]=arrayEmpleado[j];
                    arrayEmpleado[j]=auxiliarEmpleado;
                }
            }
        }
        break;
    default:
        printf("\n\nNO SE HA MODIFCADO NADA. se va a mostrar la lista sin ordenar.\n");
        break;
    }

    return 0;

}

void promedioTotal(eEmpleado arrayEmpleado[], int tamArray)
{
    int contador=0 ;
    int contadorPromedio=0;
    int salarioPromedio=0;
    int salario=0;

    for (int i=0;i<tamArray;i++)
        {
            if (arrayEmpleado[i].isEmpty==0)
            {
                salario= salario + arrayEmpleado[i].salario;
                contador++;
            }

        }

    salarioPromedio = salario / contador;

      for (int i=0;i<tamArray;i++)
        {
            if (arrayEmpleado[i].salario >= salarioPromedio && arrayEmpleado[i].isEmpty==0)
            {
                contadorPromedio++;
            }

        }

    printf("\nEl salario promedio es:%d\n",salarioPromedio);
    printf("\nLa cantidad de empleados que superan el salario promedio son:%d\n",contadorPromedio);


}

