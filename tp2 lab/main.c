/*1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
de Id. El resto de los campos se le pedirá al usuario.

2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector

3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.

4. INFORMAR:
1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio. */
///////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include "laboratorio.h"
#define TAM 5




int main()
{

eEmpleados empleados[TAM];
inicializadorLista(empleados,TAM);
int existeUnEmpleado=0;
int estadoBaja;
int opcion;

//int flag=0;

    do
    {
        printf("\nABM\n1-Cargar un empleado\n2-Mostrar a los empleados\n3-Modificar un empleado \n4-Eliminar un empleado\n5-INFORMES\n6-Salir\n");
        printf("\nElija una opcion:");
        fflush(stdin);
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                //cargarUnEmpleado(empleados,TAM);
                if( cargarUnEmpleado(empleados,TAM))
                {
                   // flag=1;
                    printf("\n se cargo correctamente:\n");
                }


               break;
            case 2:
                ordenamientoEmpleados(empleados,TAM);

                mostrarEmpleados(empleados,TAM);

                break;
            case 3:
                modificarEmpleados(empleados,TAM);

                break;
            case 4:
                 //eliminarEmpleado(empleados,TAM);
                 if (existeUnEmpleado==1)
                {
                    printf("\nNo hay empleados para eliminar!!\n\n");
                }
                else
                {
                    estadoBaja=eliminarEmpleado(empleados,TAM);

                    if (estadoBaja==-1)
                    {
                        printf("\n error en la operacion!!\n\n");

                    }
                    else
                    {
                        printf("\nexito en la operacion!!\n\n");
                    }
                }
               break;

            case 5:
                 switch (informes())
                  {
                        case 1:

                        if (existeUnEmpleado==0)
                        {
                           ordenamientoEmpleados(empleados, TAM);
                           mostrarEmpleados(empleados, TAM);
                        }
                        else
                        {
                            printf("\nNo se encontraron empleados\n\n");
                            system("pause");
                        }
                        break;
                    case 2:
                            TotalPromedio(empleados, TAM);
                        break;
                    case 3:
                        break;
                    default:
                        printf("\nEsta opcion es invalida\n\n");
                        break;
                }
                break;

            case 6:
                printf("\nGracias por usar el programa...\n");
                break;
            default:
                printf("\ningresate mal un numero, vuelve a ingresar\n");
                break;


        }
                system("pause");
                system("cls");

    }while(opcion!=6);

    return 0;




}


