/*

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

struct Graph {
    int vertices;
    bool adjMatrix[MAX_NODES][MAX_NODES];
};

struct Queue {
    int front;
    int rear;
    int capacity;
    int* array;
};

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

bool isQueueEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

bool isQueueFull(struct Queue* queue) {
    return ((queue->rear + 1) % queue->capacity == queue->front);
}

void enqueue(struct Queue* queue, int item) {
    if (isQueueFull(queue)) {
        printf("Queue is full.\n");
        return;
    }

    if (isQueueEmpty(queue))
        queue->front = 0;

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
}

int dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }

    int item = queue->array[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % queue->capacity;

    return item;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    int i, j;
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = false;
        }
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = true;
    graph->adjMatrix[dest][src] = true;
}

void bfs(struct Graph* graph, int startVertex, FILE* outputFile) {
    bool visited[MAX_NODES] = { false };

    struct Queue* queue = createQueue(graph->vertices);
    enqueue(queue, startVertex);
    visited[startVertex] = true;

    while (!isQueueEmpty(queue)) {
        int currentVertex = dequeue(queue);
        fprintf(outputFile, "%d\n", currentVertex);

        int i;
        for (i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[currentVertex][i] && !visited[i]) {
                enqueue(queue, i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int vertices, edges, i, src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the edges (source destination):\n");
    FILE* inputFile = fopen("bfs_input.txt", "w");
    if (inputFile == NULL) {
        printf("Failed to open input file.\n");
        return 1;
    }

    // Store input (graph details)
    fprintf(inputFile, "%d\n%d\n", vertices, edges);
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
            fprintf(inputFile, "%d %d\n", src, dest);
            addEdge(graph, src, dest);
        } else {
            printf("Invalid edge. Ignoring...\n");
        }
    }

    fclose(inputFile);

    int startVertex;
    printf("Enter the starting vertex for BFS traversal: ");
    scanf("%d", &startVertex);

    FILE* outputFile = fopen("bfs_output.txt", "w");
    if (outputFile == NULL) {
        printf("Failed to open output file.\n");
        return 1;
    }

    bfs(graph, startVertex, outputFile);
    fclose(outputFile);

    printf("BFS traversal completed. The input and output are stored in 'bfs_input.txt' and 'bfs_output.txt' respectively.\n");

    return 0;
}

*/
/*In this code, the user is prompted to enter the number of vertices, number of edges, and the edges themselves. The graph is then created, and both the input and the BFS traversal results are stored in separate files ("bfs_input.txt" and "bfs_output.txt", respectively).

Feel free to modify the code as needed or add additional functionalities to suit your requirements.*/

//or without using bool
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct Graph {
    int vertices;
    int adjMatrix[MAX_NODES][MAX_NODES];
};

struct Queue {
    int front;
    int rear;
    int capacity;
    int* array;
};

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isQueueEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

int isQueueFull(struct Queue* queue) {
    return ((queue->rear + 1) % queue->capacity == queue->front);
}

void enqueue(struct Queue* queue, int item) {
    if (isQueueFull(queue)) {
        printf("Queue is full.\n");
        return;
    }

    if (isQueueEmpty(queue))
        queue->front = 0;

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
}

int dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }

    int item = queue->array[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % queue->capacity;

    return item;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    int i, j;
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

void bfs(struct Graph* graph, int startVertex, FILE* outputFile) {
    int visited[MAX_NODES] = { 0 };

    struct Queue* queue = createQueue(graph->vertices);
    enqueue(queue, startVertex);
    visited[startVertex] = 1;

    while (!isQueueEmpty(queue)) {
        int currentVertex = dequeue(queue);
        fprintf(outputFile, "%d\n", currentVertex);

        int i;
        for (i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[currentVertex][i] && visited[i] == 0) {
                enqueue(queue, i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int vertices, edges, i, src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the edges (source destination):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
            addEdge(graph, src, dest);
        } else {
            printf("Invalid edge. Ignoring...\n");
        }
    }

    int startVertex;
    printf("Enter the starting vertex for BFS traversal: ");
    scanf("%d", &startVertex);

    FILE* outputFile = fopen("bfs_output.txt", "w");
    if (outputFile == NULL) {
        printf("Failed to open output file.\n");
        return 1;
    }

    bfs(graph, startVertex, outputFile);
    fclose(outputFile);

    printf("BFS traversal completed. The output is stored in 'bfs_output.txt'.\n");

    return 0;
}
