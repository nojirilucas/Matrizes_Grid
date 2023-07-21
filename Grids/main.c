#include "estrategia1.h"
#include "estrategia2.h"

int main(int argc, char **argv) {
    struct rusage buff;

    if (argc < 3) {
        printf("Uso: ./tp2 <estrategia> entrada.txt\n");
        return 1;
    }

    getrusage(RUSAGE_SELF,&buff);
    printf("|---------------------------------------|\n");
    printf("|\tTempo = %lf segundos\t|\n", (double) buff.ru_utime.tv_sec + (double) buff.ru_utime.tv_usec / (double) 1000000);
    printf("|---------------------------------------|\n");
    printf("|\tUso de memória  = %ld Kb\t|\n", buff.ru_maxrss);
    printf("|---------------------------------------|\n\n\n");

    return tp2(argc, argv);
}