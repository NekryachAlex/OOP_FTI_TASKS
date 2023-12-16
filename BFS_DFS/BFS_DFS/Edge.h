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

    const Vertex& getFirstVertex() const
    {
        return firstVertex;
    }


    const Vertex& getSecondVertex() const 
    {
        return secondVertex;
    }

    bool operator<(const Edge& edge) const 
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