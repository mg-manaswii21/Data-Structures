#include <stdio.h>
#include <stdlib.h>

// Assuming these are already defined in your GraphsAdjacencyListDirectedGraph.c file
struct node {
    int vertex;
    struct node *next;
};
typedef struct node *GNODE;
GNODE graph[20] = {NULL};

// 1. Function to print the adjacency list
void print(int *N) {
    for (int i = 0; i < *N; i++) {
        if (graph[i] != NULL) {
            printf("%d =>", i);
            GNODE temp = graph[i];
            while (temp != NULL) {
                printf("\t%d", temp->vertex);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}

// Helper function used by insertVertex (assumed based on your screenshot)
void addAtEnd(int src, int dest) {
    GNODE newNode = (GNODE)malloc(sizeof(struct node));
    newNode->vertex = dest;
    newNode->next = NULL;
    if (graph[src] == NULL) {
        graph[src] = newNode;
    } else {
        GNODE temp = graph[src];
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
}

// 2. Function to insert a new vertex
void insertVertex(int *N) {
    int numEdges, source, dest;
    int newVertex = *N;

    // Read edges FROM existing vertices TO the new vertex
    scanf("%d", &numEdges);
    for (int i = 0; i < numEdges; i++) {
        scanf("%d", &source);
        if (source < 0 || source >= newVertex) {
            printf("Invalid vertex.\n");
        } else {
            addAtEnd(source, newVertex);
        }
    }

    // Read edges FROM the new vertex TO existing vertices
    scanf("%d", &numEdges);
    for (int i = 0; i < numEdges; i++) {
        scanf("%d", &dest);
        if (dest < 0 || dest >= newVertex) {
            printf("Invalid vertex.\n");
        } else {
            addAtEnd(newVertex, dest);
        }
    }

    // Increment total vertices and display success
    (*N)++;
    printf("After inserting vertex the adjacency list is :\n");
    print(N);
}
