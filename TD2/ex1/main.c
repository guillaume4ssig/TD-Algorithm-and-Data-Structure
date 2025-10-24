#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "utils.h"

int main(void)
{
    // implement main here
    // create array example using malloc

    int n = 1000;
    int *tableau = malloc(n * sizeof(int));
    FILE *f = fopen("../valeurs_sorted.txt", "r");
    for (int i = 0; i < n; i++)
        fscanf(f, "%d", &tableau[i]);
    fclose(f);


    // use searching algorithms and compare runtime
    int target = 26660;
    clock_t debut, fin;
    double tempsExecution;
    int index;

    if (is_sorted_nondecreasing(tableau, n)) {
        // Linear search
        debut = clock();
        index = linear_search(tableau, n, target);
        fin = clock();
        tempsExecution = (double)(fin - debut) / CLOCKS_PER_SEC;
        printf("Linear search : index = %d, temps = %.6f s\n", index, tempsExecution);

        // Jump search
        debut = clock();
        index = jump_search(tableau, n, target);
        fin = clock();
        tempsExecution = (double)(fin - debut) / CLOCKS_PER_SEC;
        printf("Jump search   : index = %d, temps = %.6f s\n", index, tempsExecution);

        // Binary search
        debut = clock();
        index = binary_search(tableau, n, target);
        fin = clock();
        tempsExecution = (double)(fin - debut) / CLOCKS_PER_SEC;
        printf("Binary search : index = %d, temps = %.6f s\n", index, tempsExecution);
    }
    else {
        printf("Le tableau n'est pas trié, utilisation du linear search uniquement.\n");
        debut = clock();
        index = linear_search(tableau, n, target);
        fin = clock();
        tempsExecution = (double)(fin - debut) / CLOCKS_PER_SEC;
        printf("Linear search : index = %d, temps = %.6f s\n", index, tempsExecution);
    }


    free(tableau);
    return 0;
}
