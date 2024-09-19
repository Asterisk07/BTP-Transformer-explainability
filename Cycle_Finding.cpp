#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

struct Edge {
    int u, v, weight;
};

// Function to print the negative cycle
void printCycle(int start, vector<int>& parent) {
    vector<int> cycle;
    int curr = start;
    
    // To avoid duplicates, trace back for the length of the cycle
    for (int i = 0; i < parent.size(); i++) {
        curr = parent[curr];
    }

    // Now, trace back the entire cycle
    int cycle_start = curr;
    cycle.push_back(cycle_start);
    curr = parent[cycle_start];
    while (curr != cycle_start) {
        cycle.push_back(curr);
        curr = parent[curr];
    }
    cycle.push_back(cycle_start);

    // Print the cycle in reverse order
    // cout << "Negative cycle: ";
    for (int i = cycle.size() - 1; i >= 0; i--) {
        cout << cycle[i] + 1 << " ";  // convert back to 1-based index for output
    }
    cout << endl;
}

bool bellmanFord(int n, int m, vector<Edge>& edges, int source) {
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);

    dist[source] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }

    // Check for negative weight cycle
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int weight = edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            // A negative cycle is detected
            cout << "YES" << endl;
            printCycle(v, parent);
            return true;
        }
    }

    cout << "NO" << endl;
    return false;
}

int main() {
    int n, m;  // n = number of vertices, m = number of edges
    cin >> n >> m;

    vector<Edge> edges(m);
    
    // Input edges
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        edges[i].u--;  // Convert 1-based to 0-based index
        edges[i].v--;  // Convert 1-based to 0-based index
    }

    int source = 0;  // Starting vertex (0-based)

    bellmanFord(n, m, edges, source);

    return 0;
}
