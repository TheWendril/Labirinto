#include <stdio.h>
#include <stdlib.h>
#include <time.h>   
#include "lab.h"

int main()
{
char **matriz;
int nivel;

    puts("Digite o nivel [1 a 10]: ");
    scanf("%d", &nivel);

nivel = nivel * 10 + 1;

    matriz = (char**) malloc(nivel * sizeof(char*));

    for(int i = 0; i < nivel; i++)
    matriz[i] =(char*) malloc(nivel * sizeof(char));

    preencher_matriz(matriz, nivel);





generate(matriz, nivel);
matriz[1][0] = ' ';
matriz[nivel - 2][nivel - 1] = ' ';
imprimir_arquivo(matriz, nivel);
imprimir_matriz(matriz, nivel);
percorrer(matriz, 1, 1, nivel);
imprimir_matriz(matriz, nivel);


}