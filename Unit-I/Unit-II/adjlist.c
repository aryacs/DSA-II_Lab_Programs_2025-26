#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_USERS 100
#define MAX_FRIENDS 50
struct Node {
    int user_id;
    struct Node* next;
};
struct Graph {
    char users[MAX_USERS][30];
    struct Node* adj_list[MAX_USERS];
    int num_users;
};

// Create new friend connection node
struct Node* create_node(int user_id) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->user_id = user_id;
    new_node->next = NULL;
    return new_node;
}

// Add bidirectional friendship (undirected social graph)
void add_friend(struct Graph* graph, int user1, int user2) {
    // Add user2 to user1's friend list
    struct Node* new_friend = create_node(user2);
    new_friend->next = graph->adj_list[user1];
    graph->adj_list[user1] = new_friend;
    
    // Add user1 to user2's friend list (undirected)
    new_friend = create_node(user1);
    new_friend->next = graph->adj_list[user2];
    graph->adj_list[user2] = new_friend;
    
    printf("Added friendship: %s <-> %s\n", 
           graph->users[user1], graph->users[user2]);
}

// Print adjacency list representation
void print_social_network(struct Graph* graph) {
    printf("\n=== Social Network (Adjacency List) ===\n");
    for (int i = 0; i < graph->num_users; i++) {
        printf("%s's friends: ", graph->users[i]);
        struct Node* friend = graph->adj_list[i];
        while (friend != NULL) {
            printf("%s ", graph->users[friend->user_id]);
            friend = friend->next;
        }
        printf("\n");
    }
}

// Check if two users are friends
int are_friends(struct Graph* graph, int user1, int user2) {
    struct Node* friend = graph->adj_list[user1];
    while (friend != NULL) {
        if (friend->user_id == user2) return 1;
        friend = friend->next;
    }
    return 0;
}

// Get degree (number of friends)
int get_degree(struct Graph* graph, int user) {
    int count = 0;
    struct Node* friend = graph->adj_list[user];
    while (friend != NULL) {
        count++;
        friend = friend->next;
    }
    return count;
}

int main() {
    struct Graph social_network = { .num_users = 6 };
    
    // Initialize users
    strcpy(social_network.users[0], "Alice");
    strcpy(social_network.users[1], "Bob");
    strcpy(social_network.users[2], "Charlie");
    strcpy(social_network.users[3], "Diana");
    strcpy(social_network.users[4], "Eve");
    strcpy(social_network.users[5], "Frank");
    
    // Build social connections
    add_friend(&social_network, 0, 1);  // Alice-Bob
    add_friend(&social_network, 0, 2);  // Alice-Charlie
    add_friend(&social_network, 1, 3);  // Bob-Diana
    add_friend(&social_network, 2, 4);  // Charlie-Eve
    add_friend(&social_network, 3, 5);  // Diana-Frank
    add_friend(&social_network, 4, 5);  // Eve-Frank
    
    print_social_network(&social_network);
    
    // Query examples
    printf("\n--- Network Analysis ---\n");
    printf("Are %s and %s friends? %s\n", 
           social_network.users[0], social_network.users[5], 
           are_friends(&social_network, 0, 5) ? "YES" : "NO");
    
    printf("%s has %d friends\n", 
           social_network.users[0], get_degree(&social_network, 0));
    
    return 0;
}