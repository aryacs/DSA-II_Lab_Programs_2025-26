#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char title[100];
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with book title
struct Node* newNode(char title[]) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(node->title, title);
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Recursive in-order traversal: left -> root -> right
// Prints titles in sorted order for a BST
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s, ", root->title);
        inorder(root->right);
    }
}

// Example usage with library book categories as BST
int main() {
    // Example BST: "Fiction" < "History" < "Science"
    // Left: Fiction subtree, Right: Science subtree
    struct Node* root = newNode("History");
    root->left = newNode("Fiction");
    root->right = newNode("Science");
    root->left->left = newNode("Mystery");
    root->left->right = newNode("Romance");
    root->right->left = newNode("Physics");
    root->right->right = newNode("Biology");

    printf("Book titles in sorted order (in-order traversal):\n");
    inorder(root);
    printf("\n");
    return 0;
}