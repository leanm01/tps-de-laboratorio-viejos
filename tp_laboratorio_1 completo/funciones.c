#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
float ingresarNumero(float dato)
{
    printf("\n ingresar un numero:");
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
 float factorialPrimerOperador(float operadorUno)
 {
  int factorial;
  int i;

  i=operadorUno;
  factorial=operadorUno;

  while(i>1)
  {
      i=i-1;
      factorial=factorial*i;

  }
  return factorial;


 }

/*
int i,aux;
aux=operadorUno;
for(i=operadorUno;i>0;i--)
{
aux=aux*(i-1);
}
return aux ;
*/
