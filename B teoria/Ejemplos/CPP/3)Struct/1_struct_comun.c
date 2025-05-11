#include <stdio.h>

//--Creo PLANTILLA de mi struct--
struct EjemploPuntero {
  int numero;
  char frase[11];
};

int main() {
    //--Variables--
    struct EjemploPuntero miEjemplo;

    //--Asigno Valores--
    strcpy(miEjemplo.frase, "Hola Mundo");
    miEjemplo.numero=20;
 
    //--Imprimo valores en pantalla--
    printf("Variable 'numero': %d\n", miEjemplo.numero);
    printf("Variable 'Frase' : %s\n", miEjemplo.frase);

    return 0;
}