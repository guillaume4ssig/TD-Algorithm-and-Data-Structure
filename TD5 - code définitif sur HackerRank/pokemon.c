#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int ***dp;
    int n, m, k;
} DPTable;

// Crée et initialise à zéro la DPTable
DPTable* createDP(int n, int m, int k) {
    DPTable *table = malloc(sizeof(DPTable));
    table->n = n;
    table->m = m;
    table->k = k;

    table->dp = malloc(n * sizeof(int**));
    for (int i = 0; i < n; i++) {
        table->dp[i] = malloc(m * sizeof(int*));
        for (int j = 0; j < m; j++) {
            table->dp[i][j] = calloc(k+1, sizeof(int)); // Initialise à 0
        }
    }
    return table;
}

// Libère la mémoire
void freeDP(DPTable *table) {
    for (int i = 0; i < table->n; i++) {
        for (int j = 0; j < table->m; j++)
            free(table->dp[i][j]);
        free(table->dp[i]);
    }
    free(table->dp);
    free(table);
}

int countExactSumPaths(int n, int m, int grid[n][m], int k) {
    DPTable *dpTable = createDP(n, m, k);
    int ***dp = dpTable->dp;

    if (grid[0][0] <= k)
        dp[0][0][grid[0][0]] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) continue;
            for (int s = 0; s <= k; s++) {
                int prev = s - grid[i][j];
                if (prev < 0) continue;
                if (i > 0) dp[i][j][s] += dp[i-1][j][prev];
                if (j > 0) dp[i][j][s] += dp[i][j-1][prev];
            }
        }
    }

    int result = dp[n-1][m-1][k];
    freeDP(dpTable); // Libération mémoire
    return result;
}

int main() {

    /* À adapter au squelette sur Hackerrank, je pense qu'il faut faire un malloc pour crééer le tableau puis une boucle while pour ajouter les valeurs dedans */

    int grid[3][3] = {
        {1, 2, 3},
        {4, 6, 5},
        {3, 2, 1}
    };

    int n = 3, m = 3;
    int k = 12;


    int result = countExactSumPaths(n, m, grid, k);
    printf("Nombre de chemins avec somme = %d : %i\n", k, result);
    return 0;
}