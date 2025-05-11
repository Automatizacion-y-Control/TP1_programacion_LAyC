#include <stdio.h>

//--Creo PLANTILLA de mi struct--
struct EjemploPuntero {
  int numero;
  char frase[11];
};

/**
 * Metodo que recibe un puntero de tipo struct EjemploPuntero
*/
void miFuncionPuntero(struct  EjemploPuntero *miPuntero)
{
  //--Imprimo valores en pantalla--
    printf("Variable 'numero': %d\n", miPuntero->numero);
    printf("Variable 'Frase' : %s\n", miPuntero->frase);
}


int main() {
    //--Variables--
    struct EjemploPuntero miDato;  //Datos

    //--Asigno Valores a "miDato"--
    strcpy(miDato.frase, "Hola Mundo");
    miDato.numero=20;

    //--Llamo a la funcion--
    miFuncionPuntero(&miDato);

    return 0;
}