#include <stdio.h>
#include <string.h>
#include "avl_bst.h"
#include "tests.h"

int check_files(const char* input_path, const char* output_path) {
    FILE *fin = fopen(input_path, "r");
    FILE *fout = fopen(output_path, "r");

    if (!fin || !fout) {
        printf("Error opening files.\n");
        if (fin) fclose(fin);
        if (fout) fclose(fout);
        return 0;
    }

    struct Node* root = NULL;
    int n;

    if (fscanf(fin, "%d", &n) != 1) {
        printf("Invalid input format.\n");
        fclose(fin);
        fclose(fout);
        return 0;
    }

    for (int i = 0; i < n; i++) {
        int val;
        if (fscanf(fin, "%d", &val) != 1) {
            printf("Invalid input format.\n");
            fclose(fin);
            fclose(fout);
            return 0;
        }
        root = insert(root, val);
    }

    int q;
    if (fscanf(fin, "%d", &q) != 1) {
        printf("Invalid input format.\n");
        fclose(fin);
        fclose(fout);
        return 0;
    }

    int all_correct = 1;

    for (int i = 0; i < q; i++) {
        int query;
        if (fscanf(fin, "%d", &query) != 1) {
            printf("Invalid input format.\n");
            all_correct = 0;
            break;
        }

        struct Node* found = search(root, query);
        char expected[8];
        char result[8];

        if (fscanf(fout, "%s", expected) != 1) {
            printf("Mismatch: output file missing lines.\n");
            all_correct = 0;
            break;
        }

        if (found)
            strcpy(result, "YES");
        else
            strcpy(result, "NO");

        if (strcmp(result, expected) != 0)
            all_correct = 0;
    }

    fclose(fin);
    fclose(fout);

    return all_correct;
}


void check_all_tests() {
    for (int i = 1; i <= 10; i++) {
        char input_path[64], output_path[64];
        sprintf(input_path, "./tests/test%02d.txt", i);
        sprintf(output_path, "./tests/test%02d-output.txt", i);

        int result = check_files(input_path, output_path);
        printf("Test %02d: %s\n", i, result ? "Correct" : "Incorrect");
    }
}
