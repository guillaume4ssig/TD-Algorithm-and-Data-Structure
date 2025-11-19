#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aladdin_kingdom.h"

//Task 1
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->array = (struct List*)malloc(vertices * sizeof(struct List));

    for (int i = 0; i < vertices; i++) {
        graph->array[i].head = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void DFS(struct Graph* graph, int vertex, bool visited[], int* visitedCity){
    visited[vertex] = true;
    (*visitedCity)++;

    struct Node* currentNode = graph->array[vertex].head;
    while (currentNode) {
        int adjacentVertex = currentNode->data;
        if (!visited[adjacentVertex]) {
            DFS(graph, adjacentVertex, visited, visitedCity);
        }
        currentNode = currentNode->next;
    }
}

int KingdomCounter(struct Graph* graph) {
    bool* visited = calloc(graph->vertices, sizeof(bool));
    int count = 0;
    int visitedCity = 0;

    while (visitedCity < graph->vertices) {
        int start = -1;

        for (int i = 0; i < graph->vertices; i++) {
            if (!visited[i]) {
                start = i;
                break;
            }
        }

        DFS(graph, start, visited, &visitedCity);
        count++;
    }

    free(visited);
    return count;
}

//Task 2
int Graph_BFS_distance(struct Graph* g, int A, int B, int N) {
    bool visited[N];
    int queue[N];
    int front = 0, rear = 0;
    int distance = 0;

    for (int i = 0; i < g->vertices; i++)
        visited[i] = false;

    visited[A] = true;
    queue[rear++] = A;

    while (front != rear) {
        int levelSize = rear - front;

        for (int i = 0; i < levelSize; i++) {
            int s = queue[front++];

            if (s == B)
                return distance;

            struct Node* adj = g->array[s].head;
            while (adj != NULL) {
                if (!visited[adj->data]) {
                    visited[adj->data] = true;
                    queue[rear++] = adj->data;
                }
                adj = adj->next;
            }
        }
        distance++;
    }

    return -1;
}