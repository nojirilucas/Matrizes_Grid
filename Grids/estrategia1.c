#include "estrategia1.h"

int* maiorCaminho(int lin, int col, int grid[][MAX]){
    int *array;
    int i = 0, j = 0;
    int aux = 1;
    int soma = grid[i][j];
    //printf("\n");
    array = malloc(sizeof(int));
    
    while (i < lin - 1 || j < col - 1){
        if (i == lin - 1){
            j++;
        }else if (j == col - 1){
            i++;
        }else{
            if (grid[i + 1][j] > grid[i][j + 1]){
                i++;
            }else{
                j++;
            }
        }
        
        soma += grid[i][j];
        array [aux - 1] = grid[i][j];
        aux++;
        array = realloc(array, aux * sizeof(int));
        
        //printf("\n caminho: %d,{%d,%d}",grid[i][j],i,j);
    }
    
    return array;
}

int verifica(int* array){
    // int array[] = {-1,4,0,-2,0};  Array de exemplo
    int size = sizeof(array) / sizeof(array[0]);  // Tamanho do array
    int x = 1;  // Valor inicial de x
    int inicial_ideal = 1;

    int i;
    for (i = 0; i < size;) {
        x = x + array[i];  // Calcula o resultado somando x ao elemento atual
        if (x < 1) {
            // Se o resultado for menor que 1, atualiza o valor de x para que o resultado seja maior ou igual a 1
             inicial_ideal += 1 - x;
             x = inicial_ideal;
             i = 0;
        }else{
            i++;
        }
    }
    return inicial_ideal;
}
