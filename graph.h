#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
public:
    Graph(int V);
    void addEdge(int v, int w);
    void greedyColoring();
    void printColors() const;

private:
    int V;
    std::vector<std::vector<int>> adj;
    std::vector<int> color;
};

#endif // GRAPH_H
