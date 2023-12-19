#pragma once
#include "Vertex.h"

class Edge final 
{
private:
    Vertex firstVertex;
    Vertex secondVertex;
    int weight;

public:
    Edge(const Vertex& _firstVertex, const Vertex& _secondVertex, const int _weight = 0) :
        firstVertex(_firstVertex), secondVertex(_secondVertex), weight(_weight) {};

    int getWeight() const 
    {
        return weight;
    }

    Vertex& getFirstVertex() 
    {
        return firstVertex;
    }


    Vertex& getSecondVertex()
    {
        return secondVertex;
    }

    bool operator<(Edge& edge)
    {
        return firstVertex < edge.getFirstVertex();
    }
     
    struct EdgeHashFunction
    {
        size_t operator()(const Vertex& vertex) const
        {
            return  Vertex::VertexHashFunction(vertex);
        }

    };

};