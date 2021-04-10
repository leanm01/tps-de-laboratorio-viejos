/*
 Alumno: Merino leandro

 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"




int main()
{
	setbuf(stdout, NULL);



	float primerOperador=0;
    float segundoOperador=0;
    float sumaResultado;
    float restaResultado;
    float multiplicacionResultado;
    float divisionResultado;
    char respuesta='s';
    int  dato;
    float factorialPrimerOperando;
    float factorialSegundoOperando;


    while(respuesta=='s')//menu de opciones
    {


    	printf("\n-----Ingrese un numero del 1-5 para acceder a estas opciones----- :\n");
        printf("1-ingrese el primer operando :%.2f\n",primerOperador); // primer numero a ingresar
        printf("2-ingresar segundo numero :%.2f\n",segundoOperador); // segundo numero a ingresar
        printf("3-Para calcular las operaciones :\n");
        printf("4-Para informar los resultados :\n");
        printf("5-Salir :\n");
        fflush(stdin);
        scanf("%d", &dato);


    switch(dato)
    {
        case 1:
        	primerOperador=ingresarNumero(primerOperador);// ingresa el primer numero

        	break;

        case 2:
        	segundoOperador=ingresarNumero(segundoOperador);//ingresa el primer numero

        	break;

        case 3:// calcula los operadores que ingresa el usuario
        	sumaResultado=sumaNumeros(primerOperador,segundoOperador);

        	restaResultado=restarNumeros(primerOperador,segundoOperador);

        	multiplicacionResultado=multiplicarNumeros(primerOperador,segundoOperador);

        	divisionResultado=divisionNumeros(primerOperador,segundoOperador);

        	factorialPrimerOperando=factorial(primerOperador);

        	factorialSegundoOperando=factorial(segundoOperador);



        	break;

        case 4:// muestra los calculos ingresados

        	printf("la suma de los operadores es: %.2f\n",sumaResultado);

        	printf("la resta de los operadores es: %.2f\n",restaResultado);

        	printf("la multiplicacion de los operadores es: %.2f\n",multiplicacionResultado);

        	if(primerOperador!=0)
        	{
        		printf("la division de los operadores es: %.2f\n",divisionResultado);
        	}
        	else
        	{
        		printf("ERROR....No se puede dividir por 0\n");
        	}

        	if(primerOperador>=15)
        	{
        	printf("ERROR...el numero es demasiado grande\n");
        	}else
            {
            printf("el primer operador en factorial es: %.2f \n",factorialPrimerOperando);
            }

        	if(segundoOperador>=15)
        	{
        	 printf("ERROR...el numero es demasiado grande\n");
        	}else
        	{
        	 printf("el segundo operador en factorial es: %.2f \n",factorialSegundoOperando);
        	}

        	system("pause");
        	break;


        case 5:
        	respuesta='n';
        	break;

   }

}
        return 0;
}

