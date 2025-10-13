#include <stdlib.h>
#include "sort.h"
#include "utils.h"

void selection_sort(int *arr, int n)
{
    // selection sort iterative
}

void insertion_sort(int *arr, int n)
{
    // insertion sort iterative
}

void bubble_sort(int *arr, int n)
{
    // bubble sort iterative
}

void merge(int *arr, int *tmp, int l, int m, int r)
{
    // merge function
}

void mergesort_rec(int *arr, int *tmp, int l, int r)
{
    // recursive steps of merge sort
}

void merge_sort(int *arr, int n)
{
    if (!arr || n <= 1)
        return;
    int *tmp = (int *)malloc((size_t)n * sizeof(int));
    if (!tmp)
        return;
    mergesort_rec(arr, tmp, 0, n - 1);
    free(tmp);
}
int partition(int *arr, int l, int r)
{
    // partition function
}

void quick_sort_rec(int *arr, int l, int r)
{
    // recursive steps of quick sort
}

void quick_sort(int *arr, int n)
{
    if (!arr || n <= 1)
        return;
    quick_sort_rec(arr, 0, n - 1);
}