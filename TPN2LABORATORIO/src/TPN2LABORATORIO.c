/*
 ============================================================================
 MERINO LEANDRO

1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
de Id. El resto de los campos se le pedirá al usuario.

2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector

3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.

4. INFORMAR:
1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "empleados.h"
#define TAM_EMP 3
#include "UTN.h"

int main()

{
	setbuf(stdout, NULL);

	eEmpleado lista[TAM_EMP];
	initEmpleados(lista, TAM_EMP);
    int contadorId=0;
    int opcion;
    int estadoAlta;
    int estadoBaja;
    int hayEmpleado=0;
    do
    {
        opcion = menu();
        switch(opcion)
        {
            case 1:
            	estadoAlta = agregarEmpleados(lista, TAM_EMP, contadorId);

            	 if (estadoAlta==-1)
                 {
            	      printf("\nAlta empleado erronea!!\n\n");
            	 }
            	 else
            	 {
            	       printf("\nAlta empleado exitosa!!\n\n");
            	       contadorId++;
            	       hayEmpleado=1;
            	 }


                break;

            case 2:
            	if (hayEmpleado==0)
                {
            	      printf("\nNo hay empleados que mostrar!!\n\n");
            	}
            	else
            	{
            	      estadoBaja=mostrarEmpleados(lista, TAM_EMP);

            	      if (estadoBaja==-1)
            	      {
            	            printf("\nOperacion erronea!!\n\n");

            	      }
            	      else
            	      {
            	            printf("\nOperacion exitosa!!\n\n");
            	      }
            	}

                break;
            case 3:

            	if (hayEmpleado==0)
                {
            	    printf("\nNo hay empleados que modificar!!\n\n");
            	}
            	else
            	{
            	    estadoBaja=modificacionEmpleados(lista, TAM_EMP);

            	    if (estadoBaja==-1)
            	    {
            	          printf("\nOperacion erronea!!\n\n");
                    }
            	    else
            	    {
            	          printf("\nOperacion exitosa!!\n\n");
            	    }
            	}

            break;

            case 4:

            	if (hayEmpleado==0)
                {
            	      printf("\nNo hay empleados que dar de baja!!\n\n");
                }
            	else
            	{
            	    estadoBaja=bajaEmpleado(lista, TAM_EMP);

            	       if (estadoBaja==-1)
            	       {
            	            printf("\nOperacion erronea!!\n\n");

            	       }
            	       else
            	       {
            	            printf("\nOperacion exitosa!!\n\n");
            	       }
            	}


            break;
            case 5:


                switch (informes())
                {

                      case 1:

                    	     printf("\nOrdenar alfabeticamente y por sector\n");
                    	     ordenamientoEmpleados(lista, TAM_EMP);
                             break;
                       case 2:

                    	   if (hayEmpleado==0)
                    	   {
                    	          printf("\nNo hay empleados para mostrar!!\n\n");
                    	   }
                    	    else
                    	    {
                    	         promedioTotal(lista, TAM_EMP);

                    	         if (estadoBaja==-1)
                    	         {

                    	        	 printf("\nOperacion erronea!!\n\n");

                    	         }
                    	          else
                    	          {
                    	           printf("\nOperacion exitosa!!\n\n");

                    	          }
                    	     }
			   
			   break;
                       case 3:

                    	   printf("\nSalir\n");
                    	   break;

              }

            break;

            case 6:
            	printf("\nGracias por usar el programa...\n");
            break;
        }


    }while(opcion!=6);


    return 0;
}
