#include <stdio.h>

/* Metodo que recibe un puntero a un entero y
*  suma un 1 al valor donde apunta dicho
*  putnero
*/
void incrementarValor(int *valor) {
  *valor = *valor + 1;
}

int main() {
  int numero = 10; 

  printf("Valor inicial: %d\n", numero);
  incrementarValor(&numero);  //LLamo a la funcion y le paso la DIRECCION DE MEMORIA de "numero"
  printf("Valor después de incrementar: %d\n", numero);

  return 0;
}
