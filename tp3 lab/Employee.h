#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete();

void printEmployee(Employee*);

////////////////////////////////////////////////////////ID
int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

/////////////////////////////////////////////////////////NOMBRE
int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

//////////////////////////////////////////////////////////////////////////HORAS TRABAJADAS
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/////////////////////////////////////////////////////////////SUELDO
int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
/////////////////////////////////////////////////////////////////////////////////ENCONTRAR POR ID
int employee_findById(LinkedList* pArrayListEmployee, int id, int* pIndex);
////////////////////////////////////////////////////////////////////////////////ORDENAMIENTO
int employee_sortID(void* employeeUno, void* employeeDos);
int employee_sortName(void* employeeUno, void* employeeDos);

#endif // employee_H_INCLUDED
