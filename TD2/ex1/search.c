#include <math.h>
#include <stdio.h>
#include "search.h"
#include "utils.h"

int linear_search(int *arr, int n, int target)
{
    // linear search, return index of target
    // return -1 if not found
    for (int i = 0; i<n ; i++){
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int jump_search(int *arr, int n, int target)
{
    // jump search on sorted array, return index
    // of target, return -1 if not found
    int jump=sqrt(n);
    for (int i = 0; i<n ; i+=jump){
        if (arr[i] == target)
            return i;
        else if (arr[i] > target)
            for (int j = i-1; j>(i-jump) ; j--)
                if (arr[j] == target)
            return j;
    }
    return -1;
}

int binary_search(int *arr, int n, int target)
{
    // binary search on sorted array, return index
    // of target, return -1 if not found
    int low = 0;
    int high = n-1;
    while (low <= high){
        int mid = (low + high) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            high = mid - 1;
        else if (arr[mid] < target)
            low = mid + 1;
    }
    return -1;
}