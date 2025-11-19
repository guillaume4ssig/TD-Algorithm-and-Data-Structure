#include <stdio.h>
#include "aladdin_kingdom.h"
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

    int N, M;
    fscanf(fin, "%d %d", &N, &M);

    struct Graph* graph = createGraph(N);

    for (int i = 0; i < M; i++) {
        int U, V;
        fscanf(fin, "%d %d", &U, &V);
        addEdge(graph, U - 1, V - 1);
    }

    int A, B;
    fscanf(fin, "%d %d", &A, &B);

    int expected_kingdoms, expected_distance;
    fscanf(fout, "%d", &expected_kingdoms);
    fscanf(fout, "%d", &expected_distance);

    int res1 = KingdomCounter(graph);
    int res2 = Graph_BFS_distance(graph, A - 1, B - 1, N);

    fclose(fin);
    fclose(fout);

    return (res1 == expected_kingdoms && res2 == expected_distance);
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