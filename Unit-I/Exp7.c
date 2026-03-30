#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char member[50];
    struct Node* left;
    struct Node* right;
};

struct Node* create_node(char* mem) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(node->member, mem);
    node->left = node->right = NULL;
    return node;
}

// Returns height if balanced, -1 if unbalanced
int is_balanced_height(struct Node* root) {
    if (root == NULL) return 0;
    
    int left_h = is_balanced_height(root->left);
    if (left_h == -1) return -1;
    
    int right_h = is_balanced_height(root->right);
    if (right_h == -1) return -1;
    
    // Check balance: |left - right| <= 1
    if (abs(left_h - right_h) > 1) return -1;
    
    return 1 + (left_h > right_h ? left_h : right_h);
}

// Wrapper function
int is_tree_balanced(struct Node* root) {
    return is_balanced_height(root) != -1;
}

struct Node* insert(struct Node* root, char* mem) {
    if (root == NULL) return create_node(mem);
    if (strcmp(mem, root->member) < 0)
        root->left = insert(root->left, mem);
    else
        root->right = insert(root->right, mem);
    return root;
}

int main() {
    struct Node* root = NULL;
    int n;
    printf("Enter number of family members: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        char mem[50];
        printf("Enter member name: ");
        scanf("%s", mem);
        root = insert(root, mem);
    }
    
    if (is_tree_balanced(root)) {
        printf("Family tree is WELL-BALANCED (sibling groups equal)\n");
    } else {
        printf("Family tree is UNBALANCED (unequal sibling distribution)\n");
    }
    
    return 0;
}