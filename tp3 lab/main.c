#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

int main()
{
	setbuf(stdout, NULL);
	int terminar=0;
	int bandera=0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {

        switch(menu())
        {
            case 1:
            	if(bandera==0)
            	{
            		controller_loadFromText("data.csv",listaEmpleados);
            		bandera++;
            	}else
					printf("Sa se cargo los usuarios\n");
                break;
            case 2:
            	if(bandera==0)
            	{
            		controller_loadFromBinary("data.bin",listaEmpleados);
					bandera++;
            	}else
            		printf("Ya se cargaron los usuarios\n");

                break;
            case 3:
            	if(bandera!=0)
            	{
            	controller_addEmployee(listaEmpleados);
            	bandera++;
            	}else
            		printf("Se deben cargar los usuarios\n");
                break;
            case 4:
            	if(bandera!=0)
            	{
            	controller_editEmployee(listaEmpleados);
            	bandera++;
            	}else
            		printf("Se deben cargar los usuarios\n");
                break;
            case 5 :
            	if(bandera!=0)
            	{
            	controller_removeEmployee(listaEmpleados);
            	bandera++;
            	}else
            		printf("Se deben cargar los usuarios\n");
            	break;
            case 6 :
            	if(bandera!=0)
            	{
            	controller_ListEmployee(listaEmpleados);
            	bandera++;
            	}else
            		printf("Se deben cargar los usuarios\n");
            	break;
            case 7 :
            	if(bandera!=0)
            	{
            	controller_sortEmployee(listaEmpleados);
            	bandera++;
            	}else
            		printf("Se deben cargar los usuarios\n");
            	break;

            case 8 :
            	if(bandera!=0)
            	{
            	controller_saveAsText("data.csv",listaEmpleados);
            	bandera++;
            	}else
            		printf("Se deben cargar los usuarios\n");
            	break;

            case 9 :
            	if(bandera!=0)
            	{
            	controller_saveAsBinary("data.bin",listaEmpleados);
            	bandera++;
            	}else
            		printf("Se deben cargar los usuarios\n");
                break;
            case 10 :
            		terminar=1;
            	break;

        }
    }while(terminar==0);
    return 0;
}

