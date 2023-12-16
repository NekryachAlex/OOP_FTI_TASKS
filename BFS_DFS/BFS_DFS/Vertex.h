#pragma once
#include <string>

class Vertex final 
{
public:

    Vertex() = default;

    Vertex(const std::string& _name) : name(_name) {};
    
    static size_t VertexHashFunction(const Vertex& vertex)
    {
        size_t hash = std::hash<std::string>()(vertex.getName());
        return hash;

    };

    bool operator==(const Vertex& other) const 
    {
        return name == other.name;
    }

    const std::string& getName() const 
    {
        return name;
    };

    bool operator<(const Vertex& vertex) const 
    {
        return name < vertex.name;
    }

private:
    std::string name;
};