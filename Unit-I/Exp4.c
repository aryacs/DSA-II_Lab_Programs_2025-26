#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NODES 100

struct Node {
    char data[50];
    int left, right, parent;
    struct Node* node_ptr;
};

struct Node nodes[MAX_NODES];
int node_count = 0;

// Initialize node
void init_node(int idx, char* data) {
    strcpy(nodes[idx].data, data);
    nodes[idx].left = nodes[idx].right = nodes[idx].parent = -1;
    nodes[idx].node_ptr = NULL;
}

// Build tree from parent relations
void build_tree() {
    for (int i = 0; i < node_count; i++) {
        nodes[i].node_ptr = (struct Node*)i;  // Use index as pointer for simplicity
        if (nodes[i].parent != -1) {
            if (nodes[nodes[i].parent].left == -1) {
                nodes[nodes[i].parent].left = i;
            } else if (nodes[nodes[i].parent].right == -1) {
                nodes[nodes[i].parent].right = i;
            }
        }
    }
}

// In-order: left -> root -> right
void inorder(int idx) {
    if (idx == -1) return;
    inorder(nodes[idx].left);
    printf("%s ", nodes[idx].data);
    inorder(nodes[idx].right);
}

// Pre-order: root -> left -> right
void preorder(int idx) {
    if (idx == -1) return;
    printf("%s ", nodes[idx].data);
    preorder(nodes[idx].left);
    preorder(nodes[idx].right);
}

// Post-order: left -> right -> root
void postorder(int idx) {
    if (idx == -1) return;
    postorder(nodes[idx].left);
    postorder(nodes[idx].right);
    printf("%s ", nodes[idx].data);
}

// Recursive search for route
int search_route(int idx, char* target) {
    if (idx == -1) return 0;
    if (strcmp(nodes[idx].data, target) == 0) {
        printf("Found: %s\n", target);
        return 1;
    }
    if (search_route(nodes[idx].left, target) || search_route(nodes[idx].right, target)) {
        return 1;
    }
    return 0;
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    node_count = n;

    // Input: Node details (assume nodes 0 to n-1, input parent for each)
    for (int i = 0; i < n; i++) {
        char data[50];
        printf("Enter data for node %d: ", i);
        scanf("%s", data);
        init_node(i, data);
    }

    for (int i = 1; i < n; i++) {  // Root 0 has no parent
        printf("Enter parent for node %d: ", i);
        scanf("%d", &nodes[i].parent);
    }

    build_tree();  // Link children

    int query;
    do {
        printf("\n--- Menu ---\n1: In-order\n2: Pre-order\n3: Post-order\n4: Search\n0: Exit\nChoice: ");
        scanf("%d", &query);

        switch (query) {
            case 1:
                printf("In-order routes: ");
                inorder(0);
                printf("\n");
                break;
            case 2:
                printf("Pre-order routes: ");
                preorder(0);
                printf("\n");
                break;
            case 3:
                printf("Post-order routes: ");
                postorder(0);
                printf("\n");
                break;
            case 4: {
                char target[50];
                printf("Enter route to search: ");
                scanf("%s", target);
                if (!search_route(0, target)) {
                    printf("Route not found\n");
                }
                break;
            }
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (query != 0);

    return 0;
}
