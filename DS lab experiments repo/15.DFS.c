#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Graph represented using adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX_VERTICES];
int visited[MAX_VERTICES];

// Function to create a new adjacency list node
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

// Function to sort the adjacency list for each vertex
// This ensures smaller numbered nodes are visited first
void sortAdjList(int V) {
    for (int i = 0; i < V; i++) {
        if (adjList[i] == NULL) continue;
        
        Node *outer, *inner;
        for (outer = adjList[i]; outer != NULL; outer = outer->next) {
            for (inner = outer->next; inner != NULL; inner = inner->next) {
                if (outer->vertex > inner->vertex) {
                    int temp = outer->vertex;
                    outer->vertex = inner->vertex;
                    inner->vertex = temp;
                }
            }
        }
    }
}

// Recursive DFS function
void DFS(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    Node* temp = adjList[vertex];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFS(adjVertex);
        }
        temp = temp->next;
    }
}

int main() {
    int V, E, u, v, startNode;

    // Input number of vertices and edges
    if (scanf("%d %d", &V, &E) != 2) return 0;

    // Initialize adjacency list and visited array
    for (int i = 0; i < V; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    // Input edges
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Sort lists to satisfy the "smaller node first" rule
    sortAdjList(V);

    // Input starting node
    scanf("%d", &startNode);

    // Perform DFS
    DFS(startNode);
    printf("\n");

    return 0;
}
