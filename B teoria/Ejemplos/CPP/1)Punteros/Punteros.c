#include <stdio.h>

int main() {
  //--Declaración de una variable entera y un puntero a entero--
  int numero = 10;
  int *ptrNumero = &numero;

  //--Imprimiendo el valor de la variable y la dirección de memoria--
  printf("1A) Valor de la variable: %d\n", numero);
  printf("1B) Dirección de memoria de la variable: %p\n\n", ptrNumero);

  //--Modificando el valor de la variable "numero" a través del puntero--
  *ptrNumero = 20;

  //--Imprimiendo el valor de la variable y la dirección de memoria nuevamente--
  printf("2A) Valor de la variable (modificado): %d\n", numero);
  printf("2B) Dirección de memoria de la variable: %p\n\n", ptrNumero);

  //--Diferencia entre usar el * y no usarlo en la variable *ptrNumero--
  *ptrNumero=30;
  ptrNumero=10; //Esto esta mal

  //--Imprimiendo el valor de la variable y la dirección de memoria nuevamente--
  printf("3A) Valor de la variable (modificado): %d\n", numero);
  printf("3B) Dirección de memoria de la variable: %p\n\n", ptrNumero);

  return 0;
}