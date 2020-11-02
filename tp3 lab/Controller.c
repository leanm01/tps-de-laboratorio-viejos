#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{

     FILE* pArchivo;

     pArchivo=fopen(path,"r");

     if(pArchivo!=NULL)
     {
    	parser_EmployeeFromText(pArchivo, pArrayListEmployee);
     }
     fclose(pArchivo);


	return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{

	 FILE* pArchivo;

	     pArchivo=fopen(path,"rb");

	     if(pArchivo!=NULL)
	     {

	    	 parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);

	     }
	     fclose(pArchivo);




	return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{

	Employee* NuevoEmployee = employee_new();

	int retorno = 0;


	char auxId[100];
	char auxNombre[100];
	char auxHorasTrabajadas[100];
	char auxSalario[100];

	int getId;
	int len;


    len = ll_len(pArrayListEmployee);

	    if(pArrayListEmployee != NULL)
	    {
	        getId = getInt("\nIngrese id: ");
	        itoa(getId, auxId, 10);

	        for(int i=0;i<len;i++)
	        {
	        	NuevoEmployee = (Employee*) ll_get(pArrayListEmployee,i);

	            if(getId == NuevoEmployee->id)
	            {
	                printf("este ID ya esta en uso\n");
	                retorno = 1;

	                break;
	            }
	        }
	        if(getId != NuevoEmployee->id)
	        {
	            getString("Ingrese nombre: ", auxNombre);
	            getString("Ingrese horas: ", auxHorasTrabajadas);
	            getString("Ingrese salario: ", auxSalario);

	            NuevoEmployee = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSalario);

	            ll_add(pArrayListEmployee, NuevoEmployee);
	            printf("\nSe cargo correctamente al empleado\n");
	        }
	    }

	    return retorno;


}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	 Employee* auxEmpleado = employee_new();

	 int retorno=0;

	 int  auxId;
	 char auxNombre[100];
	 int  auxHorasTrabajadas;
	 int  auxSalario;
	 int  i;
	 int  len;
	 int  opcion = 0;


	 len = ll_len(pArrayListEmployee);

	    if(pArrayListEmployee !=NULL)
	    {
	    	auxId =getInt("\nIngrese id del empleado para modificar: ");

	        for(i=0; i<len; i++)
	        {
	        	auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);

	            if(auxId == auxEmpleado->id)
	            {

	                do
	                {
	                	opcion =getInt("\n1.Nombre-\n2.Horas trabajadas-\n3.Salario-\n4.Salir-\nIngresar una opcion ");

	                    switch(opcion)
	                    {
	                        case 1:
	                        	getString("\nIngresar el nombre del empleado: ",auxNombre);
	                            employee_setNombre(auxEmpleado, auxNombre);
	                            break;
	                        case 2:
	                        	auxHorasTrabajadas =getInt("Ingresar las horas de trabajo: ");
	                            employee_setHorasTrabajadas(auxEmpleado, auxHorasTrabajadas);
	                            break;
	                        case 3:
	                        	auxSalario =getInt("Ingresar el salario del empleado: ");
	                            employee_setSueldo(auxEmpleado, auxSalario);
	                            break;
	                        case 4:
	                        	opcion = 4;
	                            break;
	                        default:
	                            printf("\n Ingresar la opcion correcta: \n");
	                            break;
	                    }

	                }
	                while(opcion != 4);
                 }
	        }

	    }

   return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	    int retorno = 0;
	    int idEmpleado;

	    if(pArrayListEmployee != NULL)
	    {
	    	controller_ListEmployee(pArrayListEmployee);
	    	printf("\nIngrese el usuario que quiere eliminar: ");
	    	fflush(stdin);
	    	scanf("%d",&idEmpleado);
	    	printf("\nSe elimino el id:%d \n",idEmpleado);

			ll_remove(pArrayListEmployee, controller_FindId(pArrayListEmployee,idEmpleado));
			retorno = 0;


	    }
	    return retorno;
	}


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	 int  auxId;
	 char auxNombre[128];
	 int  auxHorasTrabajadas;
	 int  auxSueldo;
	 int  len = ll_len(pArrayListEmployee);
	 Employee* pEmpleado=employee_new();
	 printf("Len = %d\n",len);
	 if(pEmpleado !=NULL && len >0 && pArrayListEmployee != NULL )
	 {
		printf("---ID---|---NOMBRE---|---HORAS TRABAJADAS|---SALARIO\n");
		for(int i=0 ;i<len;i++)
		{
			pEmpleado=ll_get(pArrayListEmployee,i);

				 employee_getId(pEmpleado,&auxId);
				 employee_getNombre(pEmpleado,auxNombre);
				 employee_getHorasTrabajadas(pEmpleado,&auxHorasTrabajadas);
				 employee_getSueldo(pEmpleado,&auxSueldo);
				 printf("%4d %13s %14d %15d \n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);

		 }
	 }
	 return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
     int retorno=0;

	 int option;

	    if(pArrayListEmployee != NULL)
	    {
	        option = getInt("\n1. Ordenar por ID\n2. Ordenar por Nombre\n3.\nIngrese una opcion: ");


	        switch(option)
	        {
	            case 1:
	                ll_sort(pArrayListEmployee,employee_sortID);
	                break;
	            case 2:
	                ll_sort(pArrayListEmployee,employee_sortName);
	                break;

	            default:
	                printf("No es una opcion valida");
	                break;
	        }
	    }
	    return retorno;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{

	FILE* pFile;

	Employee* auxEmpleado;

	int len;

	pFile = fopen(path,"w");
	len = ll_len(pArrayListEmployee);

	    if(pFile != NULL && pArrayListEmployee != NULL)
	    {
	        for(int i=0;i<len;i++)
	        {
	        	auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
	            fprintf(pFile,"%d,%s,%d,%d\n", auxEmpleado->id, auxEmpleado->nombre, auxEmpleado->horasTrabajadas, auxEmpleado->sueldo);
	        }
	        printf("Se guardaron los datos en forma de:|(texto)|\n");
	        fclose(pFile);
	    }
	    else
	    {
	        printf("ERROR\n");
	    }

	    return 1;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
	Employee* auxEmpleado;

	int retorno=0;
    int len;
    int i;

        pFile = fopen(path,"wb");
	    len = ll_len(pArrayListEmployee);


	      if(pFile!= NULL && pArrayListEmployee!= NULL)
	      	{
	    	  for(i=1;i<len;i++)
	    	  {
	    		  auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);

	    		  fwrite(auxEmpleado, sizeof(Employee), 1, pFile);
	    	  }
	    	  printf("Se guardaron datos en:|binario|\n");
	    	  fclose(pFile);
	      	}





	return retorno;
}

