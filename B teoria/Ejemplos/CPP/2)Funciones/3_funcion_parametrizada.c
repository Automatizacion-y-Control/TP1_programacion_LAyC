#include <stdio.h>

/*
* Funcion o Metodo que imprime un argumento que se le pasa por parametro
*/
void funcionParametrizada(int numero){
    printf("Argumento pasado por parametro: %d\n",numero);
}

int main()
{
    int num=3;
    funcionParametrizada(2);   //LLamo a la funcion y le paso un 2
    funcionParametrizada(num); //LLamo a la funcion y le paso num
    return 0;
}
