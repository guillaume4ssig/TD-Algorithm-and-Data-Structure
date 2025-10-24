#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "utils.h"

int main(void)
{
    // implement main here
    // create array example using malloc

    int n = 1000;
    int *tableau = malloc(n * sizeof(int));
    FILE *f = fopen("../valeurs_unsorted.txt", "r");
    for (int i = 0; i < n; i++)
        fscanf(f, "%d", &tableau[i]);
    fclose(f);

    // use sorting algorithms and compare runtime
    clock_t debut, findebut;
    double tempsExecution;

    int *copie = malloc(n * sizeof(int));

    // Selection Sort
    copy_array(tableau, copie, n);
    debut = clock();
    selection_sort(copie, n);
    findebut = clock();
    tempsExecution = ((double)(findebut - debut)) / CLOCKS_PER_SEC;
    printf("Selection Sort: %.6f sec, sorted? %s\n", tempsExecution,
        is_sorted_nondecreasing(copie, n) ? "yes" : "no");

    // Insertion Sort
    copy_array(tableau, copie, n);
    debut = clock();
    insertion_sort(copie, n);
    findebut = clock();
    tempsExecution = ((double)(findebut - debut)) / CLOCKS_PER_SEC;
    printf("Insertion Sort: %.6f sec, sorted? %s\n", tempsExecution,
        is_sorted_nondecreasing(copie, n) ? "yes" : "no");

    // Bubble Sort
    copy_array(tableau, copie, n);
    debut = clock();
    bubble_sort(copie, n);
    findebut = clock();
    tempsExecution = ((double)(findebut - debut)) / CLOCKS_PER_SEC;
    printf("Bubble Sort: %.6f sec, sorted? %s\n", tempsExecution,
        is_sorted_nondecreasing(copie, n) ? "yes" : "no");

    // Merge Sort
    copy_array(tableau, copie, n);
    debut = clock();
    merge_sort(copie, n);
    findebut = clock();
    tempsExecution = ((double)(findebut - debut)) / CLOCKS_PER_SEC;
    printf("Merge Sort: %.6f sec, sorted? %s\n", tempsExecution,
        is_sorted_nondecreasing(copie, n) ? "yes" : "no");

    // Quick Sort
    copy_array(tableau, copie, n);
    debut = clock();
    quick_sort(copie, n);
    findebut = clock();
    tempsExecution = ((double)(findebut - debut)) / CLOCKS_PER_SEC;
    printf("Quick Sort: %.6f sec, sorted? %s\n", tempsExecution,
        is_sorted_nondecreasing(copie, n) ? "yes" : "no");

    free(tableau);
    free(copie);
    return 0;
}
