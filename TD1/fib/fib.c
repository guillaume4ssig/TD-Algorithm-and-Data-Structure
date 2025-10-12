#include <stdio.h>
#includes <time.h>

int FibonacciNaive(int n){
    if(n==0||n==1){
        return n;}
    else{
        return FibonacciNaive(n-1)+FibonacciNaive(n-2);}
}

int Fibonacci(int n){

}



int main(){
    clock_t start, end;
    double seconds;

    start = clock();

    printf("%i", FibonacciNaive(10));
}