#include <stdio.h>
#include <stdlib.h>
#include "laboratorio.h"
#include <strings.h>
#include <ctype.h>
#include <conio.h>
int informes()
{
    int respuesta;

    printf(" INFORMES    \n\n");
    printf("1-Listado empleados\n");
    printf("2-Total y promedio salarios\n");
    printf("\nIngresar opcion: ");
    scanf("%d", &respuesta);

    return respuesta;
}
int cargarUnEmpleado(eEmpleados* empleados,int len)
{

        int i;
        int auxIndice;

        for(i=0;i<len;i++)
           {
             if(empleados[i].isEmpty==1)
             {
                auxIndice=i;

                break;

             }

           }
        printf("\n ingrese el nombre del empleado: ");
        fflush(stdin);
        scanf("%[^\n]",empleados[auxIndice].nombre);

        printf("\n ingrese el apellido del empleado: ");
        fflush(stdin);
        scanf("%[^\n]",empleados[auxIndice].apellido);

        printf("\n ingrese el salario del empleado: ");
        fflush(stdin);
        scanf("%f",&empleados[auxIndice].salario);

        printf("\n ingrese el sector del empleado: ");
        fflush(stdin);
        scanf("%d",&empleados[auxIndice].sector);


        empleados[auxIndice].id =crearNuevoId();
        empleados[auxIndice].isEmpty=0;

      return 1;

}
 int crearNuevoId(void)//solo util para esta funcion
{
    static int id=0;

    id=id+1;


    return id;

}



int encontrarEmpleadoPorId(eEmpleados* empleados, int len, int id)
{
    int indice=-1;

    if (len>=0)
    {
        for (int i=0;i<len;i++)
        {
            if (empleados[i].id==id && empleados[i].isEmpty==0)
            {
                indice=i;
                break;

            }
        }
    }
    return indice;
}


int mostrarEmpleados(eEmpleados* empleados, int len)
{

  if (len>=0)
    {
        printf("\n%15s%15s%15s%15s%15s","-ID-","-NOMBRE-","-APELLIDO-","-SALARIO-","-SECTOR-\n");

        for (int i=0;i<len;i++)
        {
            if(empleados[i].isEmpty==0)
            {

               printf("%13d%15s%14s%16.2f%12d\n",empleados[i].id,empleados[i].nombre,empleados[i].apellido,empleados[i].salario,empleados[i].sector);

            }
        }

    }
  return 0;
}

int inicializadorLista(eEmpleados* empleados, int len)
{
  if (len>=0)
    {
        for (int i=0;i<len;i++)
        {
           empleados[i].isEmpty=1;
        }
    }
  return 0;
}

int modificarEmpleados(eEmpleados* empleados,int len)
{
      int retorno=-1;
      int auxId;
      int auxIndice;
      int i;
      char auxChar;
      mostrarEmpleados(empleados,len);
      if(len>=0)
      {
         printf("\n ingrese el id del empleado que quiere modificar:");
         scanf("%d",&auxId);

         for(i=0;i<len;i++)
           {
             if(empleados[i].id==auxId)
             {
                auxIndice=i;
                break;

             }

           }
        // printf("\n  -el id es :%d \n - el nombre es: %s \n - el apellido es :%s \n - el salario es: %.2f \n - el sector es: %d \n \n ",empleados[auxId].id, empleados[auxId].nombre , empleados[auxId].apellido , empleados[auxId].salario ,empleados[auxId].sector);

         printf("quiere modificarlo? ingrese s----n:");
         fflush(stdin);
         scanf("%c",&auxChar);
         if(auxChar=='s')
         {

            printf("\n cambiar el nombre del empleado: ");
            fflush(stdin);
            scanf("%[^\n]",empleados[auxIndice].nombre);

            printf("\n cambiar el apellido del empleado: ");
            fflush(stdin);
            scanf("%[^\n]",empleados[auxIndice].apellido);

            printf("\n cambiar el salario del empleado: ");
            fflush(stdin);
            scanf("%f",&empleados[auxIndice].salario);

            printf("\n cambiar el sector del empleado: ");
            fflush(stdin);
            scanf("%d",&empleados[auxIndice].sector);


        }
      }

     return retorno;
}
int eliminarEmpleado(eEmpleados* empleados,int len)
{
    int retorno=-1;
    int id;
    int buscarId;
    char salida;
    mostrarEmpleados(empleados,len);

    printf("Ingresar id del empleado: ");
    scanf("%d", &id);

    buscarId = encontrarEmpleadoPorId(empleados, len, id);

    if (buscarId!=-1)
    {
        printf("id %d-%s, %s\n\n", empleados[buscarId].id, empleados[buscarId].nombre, empleados[buscarId].apellido);
        printf("quieres continuar?  s----n: ");
        salida=getche();
        printf("\n");
        system("pause");

        if (tolower(salida)=='s')
        {
            empleados[buscarId].isEmpty=1;
            retorno=0;
        }
        else
        {
            printf("\n Cancelando operacion\n\n");
        }

    }
    else
    {

        printf("No existe ese id\n");
    }

    return retorno;

}
void TotalPromedio(eEmpleados* empleados, int len)
{
    int contador=0 ;
    int contadorDePromedio=0;
    int salarioPromedio=0;
    int salario=0;

    for (int i=0;i<len;i++)
        {
            if (empleados[i].isEmpty==0)
            {
                salario= salario + empleados[i].salario;
                contador++;
            }

        }

        salarioPromedio = salario / contador;

      for (int i=0;i<len;i++)
        {
            if (empleados[i].salario >= salarioPromedio && empleados[i].isEmpty==0)
            {
                contadorDePromedio++;
            }

        }

    printf("El salario promedio es: %d\n\n\n",salarioPromedio);
    printf("Los empleados que superan el limite del promedio son: %d\n\n\n",contadorDePromedio);

}
void ordenamientoEmpleados(eEmpleados* empleados,int len)
{
    int i;
    int j;
    eEmpleados auxEmpleado;

    for(i=0;i<len-1;i++)
    {
        for(j=i+1;j<len;j++)
        {
          if(strcmp(empleados[i].apellido,empleados[j].apellido)/*|| empleados[i].sector>empleados[j].sector*/ )
            {

                auxEmpleado=empleados[i];
                empleados[i]=empleados[j];
                empleados[j]=auxEmpleado;


            }
        }
    }

}
