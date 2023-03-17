#ifndef CAMINHOGULOSO_H 
#define CAMINHOGULOSO_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void ImprimeAleatoria(int N, int **matriz);
void menu(int **matriz, int N);
void Contador(int N, int **matriz);
int** lerArquivo(int *tamanho);
void tokenizar(char *str, int **matriz, int contadorLinha);
int primeiraLinha(char *str);

#endif