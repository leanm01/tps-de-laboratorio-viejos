#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/*1. Ingresar 1er operando (A=x)
  2. Ingresar 2do operando (B=y)
  3. Calcular todas las operaciones
  a) Calcular la suma (A+B)
  b) Calcular la resta (A-B)
  c) Calcular la division (A/B)
  d) Calcular la multiplicacion (A*B)
  e) Calcular el factorial (A!)*/



int main()
{
    float primerOperador=0;
    float segundoOperador=0;
    float sumaResultado;
    float restaResultado;
    float multiplicacionResultado;
    float divisionResultado;
    char respuesta='s';
    int  dato;
    float factorialPrimerOperando;


    while(respuesta=='s')//menu de opciones
    {
        printf("\n Ingrese un numero del 1-5 :\n");
        printf("1-Para ingrese el primer operando :%.2f\n",primerOperador);// primer numero
        printf("2-Para ingresar segundo numero :%.2f\n",segundoOperador);// segundo numero
        printf("3-Para calcular las operaciones :\n");
        printf("4-Para informar los resultados :\n");
        printf("5-Salir :\n");
        fflush(stdin);
        scanf("%d", &dato);


    switch(dato)
    {
        case 1:
        primerOperador=ingresarNumero(primerOperador);
        break;

        case 2:
        segundoOperador=ingresarNumero(segundoOperador);
        break;

        case 3:// calcula los operadores que ingresa el usuario
        sumaResultado=sumaNumeros(primerOperador,segundoOperador);

        restaResultado=restarNumeros(primerOperador,segundoOperador);

        multiplicacionResultado=multiplicarNumeros(primerOperador,segundoOperador);

        divisionResultado=divisionNumeros(primerOperador,segundoOperador);

        factorialPrimerOperando=factorialPrimerOperador(primerOperador);

        break;

        case 4:// muestra los calculos ingresados

        printf("la suma de los operadores es: %.2f\n",sumaResultado);

        printf("la resta de los operadores es: %.2f\n",restaResultado);

        printf("la multiplicacion de los operadores es: %.2f\n",multiplicacionResultado);

        printf("la division de los operadores es: %.2f\n",divisionResultado);

        printf("el factorial del primer operador es: %.2f\n",factorialPrimerOperando);
        default:

        break;

        case 5:// cierra el programa
        respuesta='n';
        break;

   }

}
        return 0;
}








/*
printf("la suma del primer operando y el segundo operando es :%.2f \n",sumaNumeros(primerOperador,segundoOperador));
printf("la resta del primer operando y el segundo operando es :%.2f \n",restarNumeros(primerOperador,segundoOperador));
printf("la multiplicacion del primer operando y el segundo operando es :%.2f \n",multiplicarNumeros(primerOperador,segundoOperador));

if(segundoOperador!=0)
{
printf("la division del primer operando y el segundo operando es :%.2f\n",divisionNumeros(primerOperador,segundoOperador));
}
else
{
printf("no se puede dividir por 0\n");
}*/




