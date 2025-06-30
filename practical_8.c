#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a tree node
struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
    int height; // For AVL Tree
};

// Function to create a new tree node
struct TreeNode* createNode(int key) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1; // For AVL Tree
    return newNode;
}

// Function to calculate the height of a node
int height(struct TreeNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to calculate the balance factor of a node
int getBalance(struct TreeNode* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Function to perform a right rotation
struct TreeNode* rightRotate(struct TreeNode* y) {
    struct TreeNode* x = y->left;
    struct TreeNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + fmax(height(y->left), height(y->right));
    x->height = 1 + fmax(height(x->left), height(x->right));

    return x;
}

// Function to perform a left rotation
struct TreeNode* leftRotate(struct TreeNode* x) {
    struct TreeNode* y = x->right;
    struct TreeNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + fmax(height(x->left), height(x->right));
    y->height = 1 + fmax(height(y->left), height(y->right));

    return y;
}

// Function to insert a key into a BST or AVL Tree
struct TreeNode* insert(struct TreeNode* root, int key) {
    // Perform standard BST insertion
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else // Duplicate keys are not allowed
        return root;

    // Update height of the current node
    root->height = 1 + fmax(height(root->left), height(root->right));

    // Get the balance factor and perform rotations if needed
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    // Right Right Case
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    // Left Right Case
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to find the node with the minimum key value
struct TreeNode* minValueNode(struct TreeNode* node) {
    struct TreeNode* current = node;

    // Find the leftmost leaf node
    while (current->left != NULL)
        current = current->left;

    return current;
}

// Function to delete a key from a BST or AVL Tree
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL)
        return root;

    // Perform standard BST delete
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct TreeNode* temp = minValueNode(root->right);

        // Copy the inorder successor's data to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }

    // If the tree had only one node, then return
    if (root == NULL)
        return root;

    // Update height of the current node
    root->height = 1 + fmax(height(root->left), height(root->right));

    // Get the balance factor and perform rotations if needed
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to perform inorder traversal of the tree
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Function to free the memory allocated for the tree
void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct TreeNode* root = NULL;

    // Insert elements into the tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print the inorder traversal of the tree
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Delete elements from the tree
    root = deleteNode(root, 20);
    root = deleteNode(root, 30);

    // Print the updated inorder traversal of the tree
    printf("Inorder traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

    // Free the memory allocated for the tree
    freeTree(root);

    return 0;
}
