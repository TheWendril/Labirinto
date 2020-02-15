#include <stdio.h>
#include <stdlib.h>
#include <time.h>   
#include <unistd.h>

void preencher_matriz(char **matriz, int tam)
{
    for(int i = 0; i < tam; i++)
    {
        for(int j = 0; j < tam; j++)
        {
            if(j % 2 == 0 && i % 2 == 0)
                matriz[i][j] = '+';
            else if(j % 2 == 1 && i % 2 == 0)
                matriz[i][j] = '-';
            else 
                if(j % 2 == 1)
                matriz[i][j] = ' ';
                else
                matriz[i][j] = '|';
                
        }
    }
}


void imprimir_arquivo(char **matriz, int tam)
{
    FILE * arquivo = fopen("labirinto.txt", "w");

int j;
    for(int i = 0; i < tam; i++)
    {
        for(j = 0; j < tam; j++)
        {
            fprintf(arquivo, "%2.1c", matriz[i][j]);
        }
        fprintf(arquivo, "%c", '\n');
    }
    fprintf(arquivo, "%c", '\n');
fclose(arquivo);
}


void generate(char** matriz, int tam)
{
srand(time(NULL));
int a;
int bit = 0;
//1 = esq
//2 = cima
//3 = dir
//4 = baixo

    for(int i = 1; i < tam - 1; i++)
    {
        for(int j = 1; j < tam - 1; j++)
        {
        
                if((matriz[i + 1][j] == '-' || matriz[i + 1][j] == '|') && (matriz[i + 1][j] == '-' || matriz[i - 1][j] == '|') || (matriz[i][j + 1] == '-' || matriz[i][j + 1] == '|') && (matriz[i][j - 1] == '-' || matriz[i][j - 1] == '|'))
                {
                    do
                    {
                     a = rand() % 4 + 1;

                        if(a == 1 && j - 1 != 0)
                        {
                            matriz[i][j - 1] = ' ';
                            bit = 1;
                        }
                        else
                        {
                            do
                            {
                                a = rand() % 4 + 1;
                            }while(a == 1);
                        }

                        if(a == 2 && i - 1 != 0)
                        {
                            matriz[i - 1][j] = ' ';
                            bit = 1;
                        }
                        else
                            a = rand() % 2 + 3;

                        if(a == 3 && j + 1 != tam - 1)
                        {
                            matriz[i][j + 1] = ' ';
                            bit = 1;
                        }
                        else
                            a = 4;

                        if(a == 4 && i + 1 != tam - 1)
                        {
                            matriz[i + 1][j] = ' ';
                            bit = 1;
                        }
                    }while(bit == 0);  
                }
        }
    }


    for(int i = 2; i < tam - 2; i += 2)
    {
        for(int j = 2; j < tam - 2; j += 2)
        {
            if(matriz[i - 1][j] == ' ' && matriz[i + 1][j] == ' ' && matriz[i][j + 1] == ' ' && matriz[i][j - 1] == ' ')
            {
                a = rand() % 4 + 1;

                if(a == 1)
                    matriz[i][j - 1] = '-';
                else if(a == 2)
                    matriz[i + 1][j] = '|';
                else if(a == 3)
                    matriz[i][j + 1] = '-';
                else if(a == 4)
                    matriz[i - 1][j] = '|';
            }
        }
    }


}

void cruz(char** matriz, int tam)
{
        for(int i = 0; i < tam - 1; i++)
    {
        if( i % 2 == 0)
            matriz[i][tam / 2] = '-';
        else
            matriz[i][tam / 2] = '|';
    }
        for(int j = 0; j < tam - 1; j++)
        matriz[tam / 2][j] = '|';
}

void imprimir_matriz(char** matriz, int tam)
{
int i, j;

    for(i = 0; i < tam; i++)
    {
        for(j = 0; j < tam; j++)
        {
            printf("%2.1c", matriz[i][j]);
        }
        puts("");
    }
}



void imprimir_arquivo2(char** matriz, int tam)
{
    FILE * arquivo = fopen("labirinto.txt", "a");

int j;
    for(int i = 0; i < tam; i++)
    {
        for(j = 0; j < tam; j++)
        {
            fprintf(arquivo, "%2.1c", matriz[i][j]);
        }
        fprintf(arquivo, "%c", '\n');
    }
    fprintf(arquivo, "%c", '\n');

fclose(arquivo);
}

void percorrer(char** matriz, int i, int j, int tam)
{

    if(matriz[i][j - 1] == ' ')
    {
        matriz[i][j] = '#';
        imprimir_matriz(matriz, tam);
        sleep(1);
        system("clear");
        percorrer(matriz, i, j - 1, tam);
    }
    if(matriz[i][j + 1] == ' ')
    {
        matriz[i][j] = '#';
        imprimir_matriz(matriz, tam);
        sleep(1);
        system("clear");
        percorrer(matriz, i, j + 1, tam);
    }
    if(matriz[i - 1][j] == ' ')
    {
        matriz[i][j] = '#';
        imprimir_matriz(matriz, tam);
        sleep(1);
        system("clear");
        percorrer(matriz, i - 1, j, tam);
    }
    if(matriz[i + 1][j] == ' ')
    {
        matriz[i][j] = '#';
        imprimir_matriz(matriz, tam);
        sleep(1);
        system("clear");
        percorrer(matriz, i + 1, j, tam);
    }


    if(matriz[tam - 2][tam - 1] == '/' || matriz[tam - 2][tam - 1] == '#')
    {
        imprimir_arquivo2(matriz, tam);
        _Exit(0);
    }
        
    imprimir_matriz(matriz, tam);
    sleep(1);
    system("clear");
    matriz[i][j] = '/';
}