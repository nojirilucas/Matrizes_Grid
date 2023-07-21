#include "grafo.h"
#include "estrategia1.h"
#include "estrategia2.h"

int File(int argc, char **argv, char *input, char *output) {
    int opt;
    // Faz a leitura da entrada digitada até -o
    while ((opt = getopt(argc, argv, "i:o:")) > 0) {
        switch (opt) {
            case 'i':
                strcpy(input, optarg);
                break;
            case 'o':
                strcpy(output, optarg);
                break;
            default:
                fprintf(stderr, "ENTRADA INCORRETA! Digite Novamente...\n");
                return -1;
        }
    }
    return 0;
}

int Leitura_input(char *input, int *teste, int lin[], int col[], int grid[][MAX][MAX]) {
    int i, j, k;
    FILE *entrada;
    entrada = fopen(input, "r"); // Faz abertura do arquivo para apenas leitura
    if (entrada == NULL) {
        return 0;
    }
    fscanf(entrada, "%d", teste);
    for (i = 0; i < *teste; i++) { // Percorre o arquivo de entrada, começando pelo número de testes
        fscanf(entrada, "%d %d", &lin[i], &col[i]);
        for (j = 0; j < lin[i]; j++) {
            for (k = 0; k < col[i]; k++) {
                fscanf(entrada, "%d", &grid[i][j][k]);
            }
        }
    }
    fclose(entrada);
    return 1;
}

void Nos(int teste, int lin[], int col[], int grid[][MAX][MAX], No nos[][MAX]) {
    int i, j, k;
    for (i = 0; i < teste; i++) { // Recebe as informações lidas do arquivo de entrada e preenche a matriz nos com os dados do grafo
        for (j = 0; j < lin[i]; j++) {
            for (k = 0; k < col[i]; k++) {
                // Cada elemento da matriz grid é convertido em um elemento correspondente da matriz nos, 
                // onde cada elemento no[i][j * col[i] + k] armazena a posição i, j e o valor de grid[i][j][k]
                nos[i][j * col[i] + k].i = j;
                nos[i][j * col[i] + k].j = k;
                nos[i][j * col[i] + k].valor = grid[i][j][k];
            }
        }
    }
}


int tp2(int argc, char **argv) {
    char input[MAX];
    int teste, lin[MAX], col[MAX], i;
    int grid[MAX][MAX][MAX];
    No nos[MAX][MAX];

    if (File(argc, argv, input, NULL) == -1) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    if (!Leitura_input("input.txt", &teste, lin, col, grid)) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    FILE *saida;
    saida = fopen("output.txt", "w");
    if (saida == NULL)
    {
        printf("Erro ao abrir o arquivo de saída.\n");
        return 1;
    }

    Nos(teste, lin, col, grid, nos);

    int estrategia = atoi(argv[1]); // verifica o valor da estratégia passada como argumento (convertida para inteiro com a função atoi).
    if (estrategia == 1) { // Se for 1, chama a função maiorCaminho para calcular o caminho de maior valor no grafo e armazena o resultado em resultado. 
                           // Em seguida, chama a função verifica para determinar o valor mínimo inicial a ser utilizado.
        for (i = 0; i < teste; i++) {
            int* resultado = maiorCaminho(lin[i], col[i], grid[i]);
            int inicial_ideal = verifica(resultado);
            //verifica(resultado);
            fprintf(saida,"Valor mínimo inicial:\n%d\n",inicial_ideal);
            free(resultado);
        }
    } else if (estrategia == 2) { // Se for 2, chama a função Energia_minima para calcular o valor mínimo inicial no grafo e escreve o resultado no arquivo de saída.
        for (i = 0; i < teste; i++) {
            int minimo = Energia_minima(lin[i], col[i], grid[i]);
            fprintf(saida,"Valor mínimo inicial:\n%d\n", minimo);
        }
    } else {
        printf("Estrategia invalida!\n");
        return 1;
    }

    fclose(saida);

    return 0;
}



