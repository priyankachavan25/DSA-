//example code that performs a key search in a Binary Search Tree (BST) with random inputs and saves the search result in separate files:

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

void inorderTraversal(struct Node* root, FILE* fp) {
    if (root != NULL) {
        inorderTraversal(root->left, fp);
        fprintf(fp, "%d ", root->data);
        inorderTraversal(root->right, fp);
    }
}

int main() {
    int length, range, key;
    printf("Enter the length of numbers: ");
    scanf("%d", &length);
    printf("Enter the range of numbers: ");
    scanf("%d", &range);
    printf("Enter the key to search: ");
    scanf("%d", &key);

    int* numbers = (int*)malloc(length * sizeof(int));
    FILE* randomFile = fopen("random.txt", "w");

    // Generate random numbers and write them to file
    for (int i = 0; i < length; i++) {
        numbers[i] = rand() % (range + 1);
        fprintf(randomFile, "%d ", numbers[i]);
    }

    fclose(randomFile);

    struct Node* root = NULL;

    // Insert numbers into the BST
    for (int i = 0; i < length; i++) {
        root = insert(root, numbers[i]);
    }

    // Search for the key in the BST
    struct Node* result = search(root, key);

    // Open a file for writing the search result
    FILE* searchFile = fopen("search.txt", "w");

    // If the key is found, write "Found" to the file; otherwise, write "Not Found"
    if (result != NULL) {
        fprintf(searchFile, "Found");
    } else {
        fprintf(searchFile, "Not Found");
    }

    // Close the file
    fclose(searchFile);

    free(numbers);

    return 0;
}

/*In this code, random numbers are generated and saved to a file named random.txt using the fprintf function. The numbers from the file are then inserted into the BST. The user is prompted to enter a key to search in the BST, and the search function is called to perform the search operation. The search result, either "Found" or "Not Found", is saved in a file named search.txt using the fprintf function.

Make sure to create an empty file named random.txt in the same directory as the code before running it.*/
