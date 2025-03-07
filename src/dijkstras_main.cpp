#include "dijkstras.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <limits>

int main() {
    Graph G;

    file_to_graph("src/small.txt", G);

    const int INF = numeric_limits<int>::max();

    vector<int> previous(G.numVertices, -1);
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);

    for (int i = 0; i < G.numVertices; ++i) {
        if (distances[i] == INF) {
            cout << "No path from 0 to " << i << endl;
        } else {
            vector<int> path = extract_shortest_path(distances, previous, i);
            print_path(path, distances[i]);
        }
    }

    return 0;
}