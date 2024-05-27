#include "graph.h"
#include <iostream>
#include <algorithm>

Graph::Graph(int V) : V(V), adj(V), color(V, -1) {}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::greedyColoring() {
    color[0] = 0;

    std::vector<bool> available(V, false);

    for (int u = 1; u < V; ++u) {
        for (int i : adj[u])
            if (color[i] != -1)
                available[color[i]] = true;

        int cr;
        for (cr = 0; cr < V; ++cr)
            if (!available[cr])
                break;

        color[u] = cr;

        for (int i : adj[u])
            if (color[i] != -1)
                available[color[i]] = false;
    }
}

void Graph::printColors() const {
    for (int u = 0; u < V; ++u)
        std::cout << "Vertex " << u << " --->  Color " << color[u] << std::endl;
}
