#include <stdio.h>
#include <time.h>
#include "prime.h"

int main() {
    int n = 100000000;
    // printf("Entrez un nombre: ");
    // scanf("%d", &n);

    clock_t debut = clock();
    // int totalPrimes = compterPrimes(n);
    int totalPrimes = compterPrimesEfficient(n);
    clock_t fin = clock();
    double tempsExecution = (double)(fin - debut) / CLOCKS_PER_SEC;
    printf("Nombre de nombres premiers inférieurs à %d : %d\n", n, totalPrimes);
    printf("Temps d'exécution : %.6f secondes\n", tempsExecution);

    return 0;
}