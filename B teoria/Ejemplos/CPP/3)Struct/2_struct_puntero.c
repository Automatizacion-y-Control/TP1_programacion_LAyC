#include <stdio.h>

//--Creo PLANTILLA de mi struct--
struct EjemploPuntero {
  int numero;
  char frase[11];
};

int main() {
    //--Variables--
    struct EjemploPuntero miDato;         //Datos
    struct EjemploPuntero *miPunteroDato; //Puntero que va a apuntar a "miDato"

    //--Asigno Valores a "miDato"--
    strcpy(miDato.frase, "Hola Mundo");
    miDato.numero=20;
 
    //--Asigno Puntero--
    miPunteroDato=&miDato;

    //--Imprimo valores en pantalla--
    printf("Variable 'numero': %d\n", miPunteroDato->numero);
    printf("Variable 'Frase' : %s\n", miPunteroDato->frase);

    return 0;
}