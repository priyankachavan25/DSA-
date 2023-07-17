//example code that performs insertion on a Binary Search Tree (BST) using random numbers as input and saves the resulting BST in a separate file:#include <stdio.h>
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

void inorderTraversal(struct Node* root, FILE* fp) {
    if (root != NULL) {
        inorderTraversal(root->left, fp);
        fprintf(fp, "%d ", root->data);
        inorderTraversal(root->right, fp);
    }
}

int main() {
    int length, range;
    printf("Enter the length of numbers: ");
    scanf("%d", &length);
    printf("Enter the range of numbers: ");
    scanf("%d", &range);

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

    // Open file for writing the BST
    FILE* bstFile = fopen("bst.txt", "w");

    // Perform inorder traversal and save the BST to file
    inorderTraversal(root, bstFile);

    // Close the file
    fclose(bstFile);

    free(numbers);

    return 0;
}

