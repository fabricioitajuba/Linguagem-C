/*--------------------------------------------------
 * Ex16 - Ponteiros
 * Autor: Fabrício Ribeiro
 * Para compilar: make
 * Para limpar: make clean
 *--------------------------------------------------*/

#include <stdio.h>

int main(int argc, char *argv[]) {
   
    int x, y, *p;

    x = 10; // x recebe 10

    p = &x; // p recebe o endereço de x

    y = *p; // y recbe o valor de x

    printf("O valor de x = %d e o valor de y = %d\n", x, y);

    return 0;
}

