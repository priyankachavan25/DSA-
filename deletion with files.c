//example code that performs deletion on a Binary Search Tree (BST) with random inputs and saves the resulting BST and different traversals in separate files:

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

struct Node* findMin(struct Node* node) {
    if (node == NULL)
        return NULL;
    else if (node->left == NULL)
        return node;
    else
        return findMin(node->left);
}

struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL)
        return root;
    else if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        } else {
            struct Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
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

void preorderTraversal(struct Node* root, FILE* fp) {
    if (root != NULL) {
        fprintf(fp, "%d ", root->data);
        preorderTraversal(root->left, fp);
        preorderTraversal(root->right, fp);
    }
}

void postorderTraversal(struct Node* root, FILE* fp) {
    if (root != NULL) {
        postorderTraversal(root->left, fp);
        postorderTraversal(root->right, fp);
        fprintf(fp, "%d ", root->data);
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

    // Open files for writing the BST and traversals
    FILE* bstFile = fopen("bst.txt", "w");
    FILE* inorderFile = fopen("inorder.txt", "w");
    FILE* preorderFile = fopen("preorder.txt", "w");
    FILE* postorderFile = fopen("postorder.txt", "w");

    // Perform inorder, preorder, and postorder traversals and save them to files
    inorderTraversal(root, inorderFile);
    preorderTraversal(root, preorderFile);
    postorderTraversal(root, postorderFile);

    // Close the files
    fclose(bstFile);
    fclose(inorderFile);
    fclose(preorderFile);
    fclose(postorderFile);

    free(numbers);

    return 0;
}
