#include "graph.h"
#include <iostream>
#include <fstream>

Graph parseGraphFromFile(const std::string& filename) {
    std::ifstream infile(filename);
    int V, E;
    infile >> V >> E;

    Graph g(V);
    int v, w;
    for (int i = 0; i < E; ++i) {
        infile >> v >> w;
        g.addEdge(v, w);
    }

    return g;
}

int main() {
    std::string filename = "data/graph.txt";
    Graph g = parseGraphFromFile(filename);

    g.greedyColoring();
    g.printColors();

    return 0;
}
