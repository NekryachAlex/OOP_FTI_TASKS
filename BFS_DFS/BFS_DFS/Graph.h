#pragma once
#include "Edge.h"
#include "Vertex.h"
#include <vector>
#include <unordered_map>


class Graph final {
public:
    using Map = typename std::unordered_multimap<Vertex,Edge, Edge::EdgeHashFunction>;
    using iterator = typename Map::const_iterator;
    Graph() = default;
    
    Graph(const std::unordered_multimap<Vertex,Edge, Edge::EdgeHashFunction>& _graph) : edges(_graph) {};

    void AddEdge(const Edge& edge);

    std::pair<iterator, iterator> getNeighbor(const Vertex& startingVertex) const;

private:
    Map edges;
};
