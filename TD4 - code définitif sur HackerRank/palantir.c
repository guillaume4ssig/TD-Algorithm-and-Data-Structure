#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF LLONG_MAX

// Very boring heap binary queue
typedef struct {
    int node;
    long long priority;
} PQItem;

typedef struct {
    PQItem *arr;
    int size;
    int capacity;
} *Queue;

Queue create_queue() {
    Queue q = malloc(sizeof(*q));
    q->size = 0;
    q->capacity = 16;
    q->arr = malloc(sizeof(PQItem) * q->capacity);
    return q;
}

static void pq_grow(Queue q) {
    q->capacity *= 2;
    q->arr = realloc(q->arr, sizeof(PQItem) * q->capacity);
}

static void swap(PQItem *a, PQItem *b) {
    PQItem t = *a;
    *a = *b;
    *b = t;
}

Queue enqueue(Queue q, int node, long long weight) {
    if (!q) q = create_queue();
    if (q->size == q->capacity) pq_grow(q);

    int i = q->size++;
    q->arr[i].node = node;
    q->arr[i].priority = weight;

    while (i > 0) {
        int parent = (i - 1) / 2;
        if (q->arr[parent].priority <= q->arr[i].priority) break;
        swap(&q->arr[parent], &q->arr[i]);
        i = parent;
    }
    return q;
}

PQItem dequeue(Queue *qp) {
    Queue q = *qp;
    PQItem nullItem = { -1, -1 };

    if (!q || q->size == 0) return nullItem;

    PQItem top = q->arr[0];
    q->arr[0] = q->arr[--q->size];

    int i = 0;
    while (1) {
        int left = i * 2 + 1, right = i * 2 + 2;
        int smallest = i;

        if (left < q->size && q->arr[left].priority < q->arr[smallest].priority)
            smallest = left;
        if (right < q->size && q->arr[right].priority < q->arr[smallest].priority)
            smallest = right;
        if (smallest == i) break;

        swap(&q->arr[i], &q->arr[smallest]);
        i = smallest;
    }
    return top;
}

// Graphs
typedef struct {
    int to;
    long long weight;
} Edge;

typedef struct {
    Edge *edges;
    int size;
    int capacity;
} AdjList;

typedef struct {
    AdjList *list;
    int n;
} Graph;

Graph *create_graph(int n) {
    Graph *g = malloc(sizeof(Graph));
    g->n = n;
    g->list = calloc(n, sizeof(AdjList));
    return g;
}

void add_edge(Graph *g, int u, int v, long long w) {
    if (g->list[u].size == g->list[u].capacity) {
        g->list[u].capacity = g->list[u].capacity == 0 ? 2 : g->list[u].capacity * 2;
        g->list[u].edges = realloc(g->list[u].edges,
                                   g->list[u].capacity * sizeof(Edge));
    }
    g->list[u].edges[g->list[u].size++] = (Edge){ v, w };
}

// Actual part that was fun
void print_path(int parent[], int src, int dst) {
    if (dst == -1) { printf("No path.\n"); return; }

    int path[200000], sz = 0;
    while (dst != -1) {
        path[sz++] = dst;
        dst = parent[dst];
    }
    for (int i = sz - 1; i >= 0; i--) {
        printf("%d", path[i]);
        if (i) printf(" ");
    }
    printf("\n");
}

void dijkstra(Graph *graph, int src, int dst) {
    int n = graph->n;

    long long dist[n];
    int parent[n];

    for (int i = 0; i < n; i++)
        dist[i] = INF, parent[i] = -1;

    dist[src] = 0;

    Queue pq = NULL;
    pq = enqueue(pq, src, 0);

    while (pq && pq->size > 0) {
        PQItem top = dequeue(&pq);
        int u = top.node;
        long long d = top.priority;

        if (u == -1) break;
        if (d != dist[u]) continue;   // SKIP outdated entries
        if (u == dst) break;          // Optional speed-up

        for (int i = 0; i < graph->list[u].size; i++) {
            int v = graph->list[u].edges[i].to;
            long long w = graph->list[u].edges[i].weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq = enqueue(pq, v, dist[v]);
            }
        }
    }

    printf("%lld\n", dist[dst]);
    print_path(parent, src, dst);
}

int main() {
    Graph *g = create_graph(5);

    add_edge(g, 0, 1, 4);
    add_edge(g, 0, 2, 1);
    add_edge(g, 2, 1, 2);
    add_edge(g, 1, 3, 1);
    add_edge(g, 2, 3, 5);
    add_edge(g, 3, 4, 3);

    dijkstra(g, 0, 4);

    // Code que je vais mettre dans le main:
    /*
    Graph *g = create_graph(N);

    dans le while:
        add_edge(g, x, y, z);

    apres le while:
        dijkstra(g, src, dst);
    */

    return 0;
}
