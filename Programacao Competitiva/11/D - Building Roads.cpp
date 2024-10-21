#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii; // Pair of (weight, city)

// Function to construct roads and find the minimum spanning tree
vector<pair<int, int>> construct_roads(int n, const vector<pair<int, pair<int, int>>>& roads) {
    vector<vector<pii>> graph(n); // Adjacency list representation of the graph
    vector<bool> visited(n, false); // Track visited cities
    vector<pair<int, int>> mst; // Minimum spanning tree

    // Build the graph
    for (const auto& road : roads) {
        int city1 = road.second.first;
        int city2 = road.second.second;
        int weight = road.first;
        graph[city1].push_back({weight, city2});
        graph[city2].push_back({weight, city1});
    }

    // Start with an arbitrary city (e.g., city 0)
    int start_city = 0;
    visited[start_city] = true;

    // Create a min-heap to store neighboring edges
    priority_queue<pii, vector<pii>, greater<pii>> edges;

    // Add neighboring edges of the start city to the heap
    for (const auto& neighbor : graph[start_city]) {
        edges.push(neighbor);
    }

    // Prim's algorithm
    while (!edges.empty()) {
        int weight = edges.top().first;
        int city = edges.top().second;
        edges.pop();

        if (!visited[city]) {
            visited[city] = true;
            mst.push_back({start_city, city});

            // Add neighboring edges of the newly visited city to the heap
            for (const auto& neighbor : graph[city]) {
                edges.push(neighbor);
            }
        }
    }

    return mst;
}

int main() {
    int n = 5; // Number of cities
    int m = 7; // Number of roads

    vector<pair<int, pair<int, int>>> roads = {
        {2, {0, 1}}, // Road between city 0 and 1 with weight 2
        {3, {1, 2}},
        {4, {1, 3}},
        {1, {2, 3}},
        {5, {2, 4}},
        {6, {3, 4}},
        {7, {0, 4}}
    };

    vector<pair<int, int>> minimum_roads = construct_roads(n, roads);

    // Output the minimum roads
    for (const auto& road : minimum_roads) {
        cout << "Road between city " << road.first << " and city " << road.second << endl;
    }

    return 0;
}
