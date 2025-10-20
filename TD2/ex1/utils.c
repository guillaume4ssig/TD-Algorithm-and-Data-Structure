#include "utils.h"

bool is_sorted_nondecreasing(int *arr, int n) // return true if sorted
{
    for (int i = 1; i<n ; i++){
        if (arr[i] < arr[i-1])
            return 0;
    }
    return 1;
}

int min_int(int a, int b) // return smallest value between a and b
{
    if (a < b) return a;
    return b;
}