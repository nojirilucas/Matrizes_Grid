#ifndef GRAFO_H
#define GRAFO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX 100

typedef struct no {  
    int i, j, valor;
} No;

int File(int argc, char **argv, char *input, char *output);
int Leitura_input(char *input, int *teste, int lin[], int col[], int grid[][MAX][MAX]);
void Nos(int teste, int lin[], int col[], int grid[][MAX][MAX], No nos[][MAX]);
int Percorrer_grafo(int teste, int lin, int col, int grid[][MAX][MAX]);
int tp2(int argc, char **argv);

#endif