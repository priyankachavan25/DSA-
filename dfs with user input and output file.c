/*#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

struct Graph {
    int vertices;
    bool adjMatrix[MAX_NODES][MAX_NODES];
};

struct Stack {
    int top;
    int capacity;
    int* array;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

bool isStackEmpty(struct Stack* stack) {
    return (stack->top == -1);
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

void dfs(struct Graph* graph, int startVertex, FILE* outputFile) {
    bool visited[MAX_NODES] = { false };

    struct Stack* stack = createStack(graph->vertices);
    push(stack, startVertex);
    visited[startVertex] = true;

    while (!isStackEmpty(stack)) {
        int currentVertex = pop(stack);
        fprintf(outputFile, "%d\n", currentVertex);

        int i;
        for (i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[currentVertex][i] && !visited[i]) {
                push(stack, i);
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

    for (i = 0; i < edges; i++) {
        printf("Enter edge %d (src dest): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startVertex;
    printf("Enter the starting vertex for DFS traversal: ");
    scanf("%d", &startVertex);

    FILE* outputFile = fopen("dfs_output.txt", "w");
    if (outputFile == NULL) {
        printf("Failed to open output file.\n");
        return 1;
    }

    dfs(graph, startVertex, outputFile);
    fclose(outputFile);

    printf("DFS traversal completed. The results are stored in 'dfs_output.txt'.\n");

    return 0;
}
*/

/*In this code, the user is prompted to enter the number of vertices, number of edges, and the edges themselves. The graph is then created and the Depth-First Search (DFS) traversal is performed starting from a specified vertex. The DFS traversal results are stored in a file named "dfs_output.txt". You can modify the code to fit your requirements or enhance it further.*/


/* or without using bool data type*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct Graph {
    int vertices;
    int adjMatrix[MAX_NODES][MAX_NODES];
};

struct Stack {
    int top;
    int capacity;
    int* array;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

int isStackEmpty(struct Stack* stack) {
    return (stack->top == -1);
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

void dfs(struct Graph* graph, int startVertex, FILE* outputFile) {
    int visited[MAX_NODES] = { 0 };

    struct Stack* stack = createStack(graph->vertices);
    push(stack, startVertex);
    visited[startVertex] = 1;

    while (!isStackEmpty(stack)) {
        int currentVertex = pop(stack);
        fprintf(outputFile, "%d\n", currentVertex);

        int i;
        for (i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[currentVertex][i] && !visited[i]) {
                push(stack, i);
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

    for (i = 0; i < edges; i++) {
        printf("Enter edge %d (src dest): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startVertex;
    printf("Enter the starting vertex for DFS traversal: ");
    scanf("%d", &startVertex);

    FILE* outputFile = fopen("dfs_output.txt", "w");
    if (outputFile == NULL) {
        printf("Failed to open output file.\n");
        return 1;
    }

    dfs(graph, startVertex, outputFile);
    fclose(outputFile);

    printf("DFS traversal completed. The results are stored in 'dfs_output.txt'.\n");

    return 0;
}
