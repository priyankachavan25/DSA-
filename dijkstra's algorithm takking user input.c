#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAX_NODES 100
#define INF INT_MAX

// Structure to represent a graph node
struct Node {
    int vertex;  //node number
    int weight;//integer representing the weight of the edge connecting this node to its adjacent node.
    struct Node* next;
};

// Function to create a new graph node
struct Node* createNode(int vertex, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(struct Node** graph, int src, int dest, int weight) {
    struct Node* newNode = createNode(dest, weight);
    newNode->next = graph[src];
    graph[src] = newNode;
}

// Function to initialize the distance array
void initializeDistances(int distances[], int numNodes, int startNode) {
    for (int i = 0; i < numNodes; i++) {
        if (i == startNode)
            distances[i] = 0;
        else
            distances[i] = INF;
    }
}

// Function to find the index of the node with minimum distance
int findMinDistanceNode(int distances[], int visited[], int numNodes) {
    int minDistance = INF;
    int minIndex = -1;
    for (int i = 0; i < numNodes; i++) {
        if (visited[i] == 0 && distances[i] < minDistance) {
            minDistance = distances[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to print the shortest path from startNode to destNode
void printPath(int parent[], int destNode) {
    if (parent[destNode] == -1) {
        printf("%d ", destNode);
        return;
    }
    printPath(parent, parent[destNode]);
    printf("%d ", destNode);
}

// Function to implement Dijkstra's algorithm
void dijkstra(struct Node** graph, int numNodes, int startNode) {
    int distances[MAX_NODES];
    int visited[MAX_NODES];
    int parent[MAX_NODES];

    // Initialize distances, visited array, and parent array
    initializeDistances(distances, numNodes, startNode);

    for (int i = 0; i < numNodes; i++) {
        visited[i] = 0;
        parent[i] = -1;
    }

    // Find the shortest path for all nodes
    for (int i = 0; i < numNodes - 1; i++) {
        int currentNode = findMinDistanceNode(distances, visited, numNodes);
        visited[currentNode] = 1;

        // Update the distances of adjacent nodes
        struct Node* temp = graph[currentNode];
        while (temp != NULL) {
            int neighbor = temp->vertex;
            int weight = temp->weight;
            if (visited[neighbor] == 0 && distances[currentNode] != INF && distances[currentNode] + weight < distances[neighbor]) {
                distances[neighbor] = distances[currentNode] + weight;
                parent[neighbor] = currentNode;
            }
            temp = temp->next;
        }
    }

    // Print the shortest paths and distances
    for (int i = 0; i < numNodes; i++) {
        printf("Shortest Path from %d to %d: ", startNode, i);
        printPath(parent, i);
        printf("\nDistance: %d\n\n", distances[i]);
    }
}

int main()
{
    int numNodes,numEdges;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);

    struct Node* graph[numNodes];

    // Initialize the graph
    for (int i = 0; i < numNodes; i++) {
        graph[i] = NULL;
    }

    // Add edges to the graph
    printf("Enter the edges with their weights:\n");
    for (int i = 0; i < numEdges; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }

    int startNode;
    printf("Enter the starting node: ");
    scanf("%d", &startNode);

    dijkstra(graph, numNodes, startNode);

    return 0;
}
