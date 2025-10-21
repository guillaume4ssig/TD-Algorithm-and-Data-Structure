#include <stdlib.h>
#include "sort.h"
#include "utils.h"

void selection_sort(int *arr, int n)
{
    // selection sort iterative
    for (int i = 0; i < n-2; i++){
        int min = i;
        for (int j = i+1; j < n-1; j++){
            if (arr[min] > arr[j]){
                min = j;
            }
        }
        swap_int(arr[min], arr[i]);
    }
    return arr;
}

void insertion_sort(int *arr, int n)
{
    // insertion sort iterative
    for (int i = 1; i < n-1; i++){
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
    return arr;
}

void bubble_sort(int *arr, int n)
{
    // bubble sort iterative
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;}
        }
    }
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