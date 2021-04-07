#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
float ingresarNumero(float dato)
{
    printf("\ningresar un numero: ");
    fflush(stdin);
    scanf("%f",&dato);

    return dato;

}
float sumaNumeros(float primerOperador , float segundoOperador)
{
   int auxuliar=0;
   auxuliar=primerOperador+segundoOperador;
   return auxuliar;

}
float restarNumeros(float primerOperador , float segundoOperador)
{
   int auxuliar=0;
   auxuliar=primerOperador-segundoOperador;
   return auxuliar;

}
float multiplicarNumeros( float primerOperador , float segundoOperador)
{
   int auxuliar=0;
   auxuliar=primerOperador*segundoOperador;
   return auxuliar;

}
float divisionNumeros( float operadorUno , float operadorDos)
{
   float respuesta=0;
   respuesta=operadorUno/operadorDos;
   return respuesta;

}

float factorial(float numero)
{

	 float resultado = 1;
	 int i;


	 for (i=1;i<=numero;i++)
	 {
	    resultado = resultado * i;
	 }

	return resultado;

}



