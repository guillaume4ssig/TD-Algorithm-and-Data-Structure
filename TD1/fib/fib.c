#include "fib.h"
#include <stdlib.h>

int FibonacciNaive(int n){
    if(n==0||n==1){
        return n;}
    else{
        return FibonacciNaive(n-1)+FibonacciNaive(n-2);}
}

int FibonacciDyn(int n){
    if (n <= 1)
        return n;

    int DP_Fib[n + 1];  // tableau statique dans la fonction
    DP_Fib[0] = 0;
    DP_Fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        DP_Fib[i] = DP_Fib[i - 1] + DP_Fib[i - 2];
    }

    return DP_Fib[n];
}