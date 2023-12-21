#pragma once
#include "Vertex.h"

class Edge final 
{
private:
    Vertex firstVertex;
    Vertex secondVertex;
    unsigned long weight;

public:
    Edge(const Vertex& _firstVertex, const Vertex& _secondVertex, const unsigned long _weight = 0) :
        firstVertex(_firstVertex), secondVertex(_secondVertex), weight(_weight) {};

    unsigned long getWeight() const
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

    bool operator==(Edge& edge)
    {
        return firstVertex == edge.getFirstVertex();
    }
     
    struct EdgeHashFunction
    {
        size_t operator()(const Vertex& vertex) const
        {
            Vertex::VertexHashFunction hash;
            return  hash(vertex);
        }

    };

};