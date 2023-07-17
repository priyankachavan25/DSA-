//example code in C that generates an adjacency matrix or adjacency list based on user input and saves them to separate files:

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

void saveAdjacencyMatrix(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    FILE *file = fopen("adjacency_matrix.txt", "w");
    if (file == NULL) {
        printf("Failed to open the file for writing.\n");
        return;
    }

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            fprintf(file, "%d ", adjacencyMatrix[i][j]);
            printf("%d ", adjacencyMatrix[i][j]);
        }
        fprintf(file, "\n");
        printf("\n");
    }

    fclose(file);
}

void saveAdjacencyList(int adjacencyList[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    FILE *file = fopen("adjacency_list.txt", "w");
    if (file == NULL) {
        printf("Failed to open the file for writing.\n");
        return;
    }

    for (int i = 0; i < numVertices; i++) {
        fprintf(file, "%d: ", i);
        for (int j = 0; j < numVertices; j++) {
            if (adjacencyList[i][j] == 1) {
                fprintf(file, "%d ", j);
                printf("%d ", j);
            }
        }
        fprintf(file, "\n");
        printf("\n");
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
    saveAdjacencyMatrix(adjacencyMatrix, numVertices);
    printf("Adjacency matrix saved to 'adjacency_matrix.txt'\n");

    // Save adjacency list to a file
    saveAdjacencyList(adjacencyList, numVertices);
    printf("Adjacency list saved to 'adjacency_list.txt'\n");

    return 0;
}

/*In this code, after generating the adjacency matrix and adjacency list based on user input, the saveAdjacencyMatrix and saveAdjacencyList functions are defined to save the respective data structures to files.

The saveAdjacencyMatrix function saves the adjacency matrix to a file named "adjacency_matrix.txt". It opens the file in write mode, iterates over the matrix, and writes each element to the file.

The saveAdjacencyList function saves the adjacency list to a file named "adjacency_list.txt". It opens the file in write mode, iterates over the list, and writes each vertex and its adjacent vertices to the file.

In the main function, after generating the adjacency matrix and adjacency list, the code calls the saveAdjacencyMatrix function to save the matrix to a file, and the saveAdjacencyList function to save the list to a file. It then prints a message indicating that the files have been saved.

When you run this code, it will prompt you to enter the number of vertices, the number of edges, and the edges (vertex1 and vertex2) one by one. After you provide the input, it will generate the adjacency matrix and adjacency list, save them to separate files ("adjacency_matrix.txt" and "adjacency_list.txt"), and display messages indicating the successful file saving.*/
