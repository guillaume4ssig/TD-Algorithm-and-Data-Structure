#include <stdio.h>
#include <time.h>
#include "fib.h"

int main() {
    int n = 1000;
    // printf("Entrez un entier n : ");
    // scanf("%d", &n);

    clock_t debut = clock();
    int result = FibonacciNaive(n);
    // int result = FibonacciDyn(n);
    clock_t fin = clock();
    double tempsExecution = (double)(fin - debut) / CLOCKS_PER_SEC;

    printf("Fibonacci(%d) = %d\n", n, result);
    printf("Temps d'exécution : %.6f secondes\n", tempsExecution);
    return 0;
}