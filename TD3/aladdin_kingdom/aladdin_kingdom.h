#ifndef ALADDIN_KINGDOM
#define ALADDIN_KINGDOM
#include <stdbool.h>

// Structures
struct Node {
    int data;
    struct Node* next;
};

struct List {
    struct Node* head;
};

struct Graph {
    int vertices;
    struct List* array;
};

// Fonctions
struct Node* createNode(int data);
struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void DFS(struct Graph* graph, int vertex, bool visited[], int* visitedCity);
int KingdomCounter(struct Graph* graph);
int Graph_BFS_distance(struct Graph* g, int A, int B, int N);
#endif