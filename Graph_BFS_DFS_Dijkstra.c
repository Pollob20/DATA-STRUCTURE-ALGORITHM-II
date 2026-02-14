#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 6

typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* adjList[V];
} Graph;

Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    for (int i = 0; i < V; i++)
        graph->adjList[i] = NULL;
    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    Node* newNode = createNode(dest, weight);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void BFS(Graph* graph, int start) {
    int visited[V] = {0};
    int queue[V], front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        Node* temp = graph->adjList[current];
        while (temp) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
}

void DFSUtil(Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    Node* temp = graph->adjList[vertex];
    while (temp) {
        if (!visited[temp->vertex])
            DFSUtil(graph, temp->vertex, visited);
        temp = temp->next;
    }
}

void DFS(Graph* graph, int start) {
    int visited[V] = {0};
    DFSUtil(graph, start, visited);
}

int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void dijkstra(Graph* graph, int src) {
    int dist[V];
    int sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = 0;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;

        Node* temp = graph->adjList[u];
        while (temp) {
            int v = temp->vertex;
            int weight = temp->weight;
            if (!sptSet[v] && dist[u] != INT_MAX &&
                dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
            temp = temp->next;
        }
    }

    printf("\nDijkstra shortest distances from %d:\n", src);
    for (int i = 0; i < V; i++)
        printf("To %d = %d\n", i, dist[i]);
}

int main() {
    Graph* graph = createGraph();

    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 2, 1);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 1, 3, 5);
    addEdge(graph, 2, 3, 8);
    addEdge(graph, 2, 4, 10);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 3, 5, 6);
    addEdge(graph, 4, 5, 3);

    printf("BFS starting from 0: ");
    BFS(graph, 0);

    printf("\nDFS starting from 0: ");
    DFS(graph, 0);

    dijkstra(graph, 0);

    return 0;
}
