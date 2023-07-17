#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Function to perform Depth-First Search (DFS)
void dfs(int vertex, int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices, bool visited[MAX_VERTICES], FILE *file) {
    visited[vertex] = true;
    fprintf(file, "%d ", vertex);
    printf("%d ", vertex);

    for (int i = 0; i < numVertices; i++) {
        if (adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            dfs(i, adjacencyMatrix, numVertices, visited, file);
        }
    }
}

// Function to perform Breadth-First Search (BFS)
void bfs(int vertex, int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices, bool visited[MAX_VERTICES], FILE *file) {
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[vertex] = true;
    queue[rear++] = vertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        fprintf(file, "%d ", currentVertex);
        printf("%d ", currentVertex);

        for (int i = 0; i < numVertices; i++) {
            if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

// Function to read adjacency matrix from file
void readAdjacencyMatrix(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    FILE *file = fopen("adjacency_matrix.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file for reading.\n");
        return;
    }

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            fscanf(file, "%d", &adjacencyMatrix[i][j]);
        }
    }

    fclose(file);
}

// Function to read adjacency list from file
void readAdjacencyList(int adjacencyList[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    FILE *file = fopen("adjacency_list.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file for reading.\n");
        return;
    }

    for (int i = 0; i < numVertices; i++) {
        int vertex;
        fscanf(file, "%d:", &vertex);
        while (true) {
            int adjacentVertex;
            fscanf(file, "%d", &adjacentVertex);
            if (adjacentVertex == -1) {
                break;
            }
            adjacencyList[vertex][adjacentVertex] = 1;
        }
    }

    fclose(file);
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = {0}; // Adjacency matrix
    int adjacencyList[MAX_VERTICES][MAX_VERTICES] = {0};  // Adjacency list

    printf("Enter the edges (vertex1 vertex2):\n");
    for (int i = 0; i < numEdges; i++) {
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);

        // Update adjacency matrix
        adjacencyMatrix[vertex1][vertex2] = 1;
        adjacencyMatrix[vertex2][vertex1] = 1;

        // Update adjacency list
        adjacencyList[vertex1][vertex2] = 1;
        adjacencyList[vertex2][vertex1] = 1;
    }

    // Save adjacency matrix to a file
    FILE *matrixFile = fopen("adjacency_matrix.txt", "w");
    if (matrixFile == NULL) {
        printf("Failed to open the file for writing.\n");
        return 1;
    }
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            fprintf(matrixFile, "%d ", adjacencyMatrix[i][j]);
            printf("%d ", adjacencyMatrix[i][j]);
        }
        fprintf(matrixFile, "\n");
        printf("\n");
    }
    fclose(matrixFile);
    printf("Adjacency matrix saved to 'adjacency_matrix.txt'\n");

    // Save adjacency list to a file
    FILE *listFile = fopen("adjacency_list.txt", "w");
    if (listFile == NULL) {
        printf("Failed to open the file for writing.\n");
        return 1;
    }
    for (int i = 0; i < numVertices; i++) {
        fprintf(listFile, "%d:", i);
        printf("%d:", i);
        for (int j = 0; j < numVertices; j++) {
            if (adjacencyList[i][j] == 1) {
                fprintf(listFile, " %d", j);
                printf(" %d", j);
            }
        }
        fprintf(listFile, " -1\n");
        printf(" -1\n");
    }
    fclose(listFile);
    printf("Adjacency list saved to 'adjacency_list.txt'\n");

    // Read adjacency matrix from file
    readAdjacencyMatrix(adjacencyMatrix, numVertices);

    // Read adjacency list from file
    readAdjacencyList(adjacencyList, numVertices);

    // Perform DFS and store traversal output to a file
    FILE *dfsFile = fopen("dfs_output.txt", "w");
    if (dfsFile == NULL) {
        printf("Failed to open the file for writing.\n");
        return 1;
    }
    printf("\nDFS Traversal:\n");
    bool visited[MAX_VERTICES] = {false};
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            dfs(i, adjacencyMatrix, numVertices, visited, dfsFile);
        }
    }
    fclose(dfsFile);
    printf("DFS traversal saved to 'dfs_output.txt'\n");

    // Perform BFS and store traversal output to a file
    FILE *bfsFile = fopen("bfs_output.txt", "w");
    if (bfsFile == NULL) {
        printf("Failed to open the file for writing.\n");
        return 1;
    }
    printf("\nBFS Traversal:\n");
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            bfs(i, adjacencyMatrix, numVertices, visited, bfsFile);
        }
    }
    fclose(bfsFile);
    printf("BFS traversal saved to 'bfs_output.txt'\n");

    return 0;
}
