#include <stdio.h>

/*
* Funcion o Metodo que retorna un numero fijo
*/
int funcionConRetorno(){
    int numero=2;
    return(numero);
}

int main()
{
    int numero=0; //Creo una variable para almacenar el valor que va a devolver la funcion

    printf("Variable 'numero': %d\n",numero); // Antes de llamar a la funcion
    numero=funcionConRetorno();               // Guardo el valor que retorna la funcion en "numero"
    printf("Variable 'numero': %d\n",numero); // Despues de llamar a la funcion

    return 0;
}
