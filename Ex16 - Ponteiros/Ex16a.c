/*--------------------------------------------------
 * Ex16a - Ponteiro de ponteiro
 * Autor: Fabrício Ribeiro
 * Para compilar: make
 * Para limpar: make clean
 *--------------------------------------------------*/

#include <stdio.h>

int main(int argc, char *argv[]) {
   
    int x, *p, **q;

    x = 10; // x recebe 10

    p = &x; // p recebe o endereço de x

    q = &p; // q recbe o endereço de p

    printf("O valor de x = %d e o valor de x referenciado = %d\n", x, **q);

    return 0;
}

