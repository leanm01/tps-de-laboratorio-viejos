#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#include "Employee.h"
#include "Controller.h"

Employee* employee_new()
{
		Employee* new= (Employee*)malloc(sizeof(Employee));
        return new ;

}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* this = employee_new();

    if(this != NULL)
    {
           if(   employee_setId(this,atoi(idStr))!= -1  &&
        		 employee_setNombre(this,nombreStr) != -1 &&
        		 employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr)) != -1 &&
				 employee_setSueldo(this,atoi(sueldoStr)) != -1  )
                {
                      return this;
                }
    }
    return NULL;
}

/////////////////////////////////////////////////////////////////ELIMINAR
void employee_delete(Employee* this)
{
	free(this);
}

//////////////////////////////////////////////////////////////// ID

int employee_setId(Employee* this,int id)
{
	//this->id=id; //version simple
	int retorno=0;
	if(id>0 && this!=NULL)
		{
			this->id=id;
			retorno=1;
		}
	return retorno;
}


int employee_getId(Employee* this,int* id)
{

	int retorno=0;
	if(id!=NULL && this!=NULL)
	 	 {
			*id=this->id;
			retorno=1;
	 	 }
	return retorno;
}
/////////////////////////////////////////////////////////////////////// NOMBRE
int employee_setNombre(Employee* this,char* nombre)
{

	int retorno=0;
    if(nombre>0 && this!=NULL)
		{
			strcpy(this->nombre,nombre);
			retorno=1;
		}
		return retorno;


}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno=0;
	if(nombre!=NULL && this!=NULL)
		{
			strcpy(nombre,this->nombre);
			retorno=1;
		}
	return retorno;



}
//////////////////////////////////////////////////////////////////////////////HORAS TRABAJADAS
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{

	int retorno=0;
	if(horasTrabajadas>0 && this!=NULL)
			{
			    this->horasTrabajadas=horasTrabajadas;
				retorno=1;
			}
	return retorno;



}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{

	    int retorno=0;
		if(horasTrabajadas!=NULL && this!=NULL)
			{
				*horasTrabajadas=this->horasTrabajadas;
				retorno=1;
			}
		return retorno;



}
///////////////////////////////////////////////////////////////////////////////// SUELDO
int employee_setSueldo(Employee* this,int sueldo)
{


	int retorno=0;
	if(sueldo>0 && this!=NULL)
			{
			    this->sueldo=sueldo;
				retorno=1;
			}
	return retorno;



}
int employee_getSueldo(Employee* this,int* sueldo)
{

      int retorno=0;
	  if(sueldo!=NULL && this!=NULL)
			{
				*sueldo=this->sueldo;
				 retorno=1;
			}
	 return retorno;



}
int controller_FindId(LinkedList* pArrayListEmployee,int idUser)
{
	Employee* pEmpleado = NULL;
	int len = ll_len(pArrayListEmployee);

	int auxId;

	if(pArrayListEmployee !=NULL && idUser>0)
	{

		for(int i=0;i<len;i++)
		{
			    pEmpleado = ll_get(pArrayListEmployee,i);
				employee_getId(pEmpleado, &auxId);

				if(idUser==auxId)
				{
					return i;
				}
		}
	}

	return -1;
}
int employee_sortID(void* employeeUno, void* employeeDos)
{
    int retorno;
	int auxUno;
	int auxDos;

    employee_getId(employeeUno,&auxUno);
    employee_getId(employeeDos,&auxDos);

        if(auxUno > auxDos)
        {
        	retorno = 1;
        }
        else if(auxUno == auxDos)
        {
        	retorno = 0;
        }
        else
        {
        	retorno = -1;
        }

    return retorno;
}
int employee_sortName(void* employeeUno, void* employeeDos)
{
    int retorno;
    char auxUno[51];
	char auxDos[51];

    employee_getNombre(employeeUno,auxUno);
    employee_getNombre(employeeDos,auxDos);

      if(strcmp(auxUno,auxDos)>0)
        {
        	retorno = 1;
        }
        else if(strcmp(auxUno,auxDos)==0)
         {
        	retorno = 0;
         }
         else
          {
        	 retorno = -1;
          }

    return retorno;
}
