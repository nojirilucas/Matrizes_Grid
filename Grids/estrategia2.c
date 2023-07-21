#include "estrategia2.h"

// Função igual ao fmin
int min(int a, int b){
    return (a < b) ? a : b;
}

int Energia_minima(int lin, int col, int grid[][MAX]){
    int ultima_pos[MAX][MAX];         // Matriz para armazenar os valores mínimos necessários
    ultima_pos[lin - 1][col - 1] = 1; // Define o valor da última posição como 1

    // Preenche os valores da última coluna
    for (int i = lin - 2; i >= 0; i--){
        ultima_pos[i][col - 1] = ultima_pos[i + 1][col - 1] - grid[i][col - 1];
        if (ultima_pos[i][col - 1] <= 0)
            ultima_pos[i][col - 1] = 1;
    }

    // Preenche os valores da última linha
    for (int j = col - 2; j >= 0; j--){
        ultima_pos[lin - 1][j] = ultima_pos[lin - 1][j + 1] - grid[lin - 1][j];
        if (ultima_pos[lin - 1][j] <= 0)
            ultima_pos[lin - 1][j] = 1;
    }

    // Preenche os valores das outras posições
    for (int i = lin - 2; i >= 0; i--){
        for (int j = col - 2; j >= 0; j--){
            int caminho_menor = min(ultima_pos[i + 1][j], ultima_pos[i][j + 1]);
            ultima_pos[i][j] = caminho_menor - grid[i][j];
            if (ultima_pos[i][j] <= 0)
                ultima_pos[i][j] = 1;
        }
    }

    return ultima_pos[0][0]; // Retorna o valor necessário para a posição (0,0) do grafo
}