#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_VERTICES 10
char* cities[MAX_VERTICES] = {"Downtown", "Airport", "Mall", "Hospital", "University", "Suburb1", "Suburb2"};
int num_cities = 7;
int adj_matrix[MAX_VERTICES][MAX_VERTICES];  // 0=unconnected, value=distance(km)
// Initialize matrix with infinity (no direct road)
void init_matrix() {
    for (int i = 0; i < num_cities; i++)
        for (int j = 0; j < num_cities; j++)
            adj_matrix[i][j] = (i == j) ? 0 : INT_MAX / 2;
}

// Add bidirectional road (undirected graph)
void add_road(int from, int to, int distance) {
    adj_matrix[from][to] = distance;
    adj_matrix[to][from] = distance;  // Undirected
    printf("Added road: %s <-> %s (%d km)\n", cities[from], cities[to], distance);
}

// Print adjacency matrix
void print_matrix() {
    printf("\nCity Road Network (Adjacency Matrix - Distances in km):\n");
    printf("     | ");
    for (int j = 0; j < num_cities; j++) printf("%-10s", cities[j]);
    printf("\n");
    
    for (int i = 0; i < num_cities; i++) {
        printf("%-10s| ", cities[i]);
        for (int j = 0; j < num_cities; j++) {
            if (adj_matrix[i][j] == INT_MAX / 2) printf("INF       ");
            else printf("%-10d", adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// Check if direct road exists
int has_direct_road(int from, int to) {
    return adj_matrix[from][to] != INT_MAX / 2;
}

// Display all roads
void print_roads() {
    printf("\nAll Roads:\n");
    for (int i = 0; i < num_cities; i++) {
        for (int j = i + 1; j < num_cities; j++) {  // Avoid duplicates
            if (has_direct_road(i, j)) {
                printf("%s <-> %s: %d km\n", cities[i], cities[j], adj_matrix[i][j]);
            }
        }
    }
}

int main() {
    init_matrix();
    
    // Model city road network
    add_road(0, 1, 15);  // Downtown-Airport
    add_road(0, 2, 5);   // Downtown-Mall
    add_road(0, 3, 8);   // Downtown-Hospital
    add_road(1, 4, 12);  // Airport-University
    add_road(2, 5, 10);  // Mall-Suburb1
    add_road(3, 6, 7);   // Hospital-Suburb2
    add_road(4, 5, 6);   // University-Suburb1
    
    print_matrix();
    print_roads();
    
    // Query example
    int from, to;
    printf("\nCheck direct road? From city (0-%d): ", num_cities-1);
    scanf("%d", &from);
    printf("To city: ");
    scanf("%d", &to);
    
    if (has_direct_road(from, to)) {
        printf("Direct road exists: %s -> %s (%d km)\n", 
               cities[from], cities[to], adj_matrix[from][to]);
    } else {
        printf("No direct road between %s and %s\n", cities[from], cities[to]);
    }
    return 0;
}