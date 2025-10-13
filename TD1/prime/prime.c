#include "prime.h"
#include <stdlib.h>

bool estPremier(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int compterPrimes(int n) {
    int compteur = 0;
    for (int i = 2; i < n; i++) {
        if (estPremier(i)) compteur++;
    }
    return compteur;
}

int compterPrimesEfficient(int n) {
    if (n < 2) return 0;

    bool *estPremier = (bool*) malloc(n * sizeof(bool));
    for (int i = 0; i < n; i++) estPremier[i] = true;

    estPremier[0] = false;
    estPremier[1] = false;

    for (int i = 2; i * i < n; i++) {
        if (estPremier[i]) {
            for (int j = i * i; j < n; j += i) {
                estPremier[j] = false;
            }
        }
    }

    int compteur = 0;
    for (int i = 2; i < n; i++) {
        if (estPremier[i]) compteur++;
    }

    free(estPremier);
    return compteur;
}