/*--------------------------------------------------
 * Ex16b - Lendo uma string usando ponteiro
 * Autor: Fabrício Ribeiro
 * Para compilar: make
 * Para limpar: make clean
 *--------------------------------------------------*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
   
    char *p1, s[80];

    do{
        p1 = s;
        gets(s); //Lê uma string

        //Imprime o equivalente decimal de cada caractere
        while(*p1){
            printf(" %d", *p1++);
        }

    }while(strcmp(s, "fim"));

    return 0;
}

