#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Define a structure for a graph
struct Graph {
    int vertices;
    struct Node** adjList;
};

// Function to create a new graph with a given number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (graph == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    graph->vertices = vertices;
    graph->adjList = (struct Node**)malloc(vertices * sizeof(struct Node*));
    if (graph->adjList == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialize adjacency lists
    for (int i = 0; i < vertices; ++i) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add an edge from dest to src
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to perform Breadth-First Search on a graph
void BFS(struct Graph* graph, int startVertex) {
    // Create an array to keep track of visited vertices
    bool* visited = (bool*)malloc(graph->vertices * sizeof(bool));
    if (visited == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialize all vertices as not visited
    for (int i = 0; i < graph->vertices; ++i) {
        visited[i] = false;
    }

    // Create a queue for BFS
    int* queue = (int*)malloc(graph->vertices * sizeof(int));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int front = 0, rear = 0;

    // Mark the current node as visited and enqueue it
    visited[startVertex] = true;
    queue[rear++] = startVertex;

    printf("Breadth-First Traversal starting from vertex %d: ", startVertex);

    while (front < rear) {
        // Dequeue a vertex from the queue and print it
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Get all adjacent vertices of the dequeued vertex
        struct Node* temp = graph->adjList[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->data;

            // If the adjacent vertex has not been visited, mark it as visited and enqueue it
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue[rear++] = adjVertex;
            }

            temp = temp->next;
        }
    }

    printf("\n");

    // Free allocated memory
    free(visited);
    free(queue);
}

// Recursive function for Depth-First Search
void DFSRecursive(struct Graph* graph, int vertex, bool* visited) {
    // Mark the current node as visited and print it
    visited[vertex] = true;
    printf("%d ", vertex);

    // Recur for all the vertices adjacent to this vertex
    struct Node* temp = graph->adjList[vertex];
    while (temp != NULL) {
        int adjVertex = temp->data;
        if (!visited[adjVertex]) {
            DFSRecursive(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

// Function to perform Depth-First Search on a graph
void DFS(struct Graph* graph, int startVertex) {
    // Create an array to keep track of visited vertices
    bool* visited = (bool*)malloc(graph->vertices * sizeof(bool));
    if (visited == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialize all vertices as not visited
    for (int i = 0; i < graph->vertices; ++i) {
        visited[i] = false;
    }

    printf("Depth-First Traversal starting from vertex %d: ", startVertex);
    DFSRecursive(graph, startVertex, visited);
    printf("\n");

    // Free allocated memory
    free(visited);
}

// Function to free the memory allocated for the graph
void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->vertices; ++i) {
        struct Node* current = graph->adjList[i];
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    free(graph->adjList);
    free(graph);
}

int main() {
    // Create a graph with 5 vertices
    struct Graph* graph = createGraph(5);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);

    // Perform BFS starting from vertex 0
    BFS(graph, 0);

    // Perform DFS starting from vertex 0
    DFS(graph, 0);

    // Free the memory allocated for the graph
    freeGraph(graph);

    return 0;
}

