#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

class Vertex {
public:
    Vertex(char c) : ID (c) {}
    bool operator==(const Vertex &rhs) const {    // Comparing 2 vertices, to help prevent duplication while creating the graph. 
    return (this->ID == rhs.ID);
    }
    friend void Graph::insertNeighbors(std::unordered_map <Vertex*, int> neighbors);
private:
    char ID;
    std::unordered_map <Vertex*, int> neighbors;   // Store pointer to the neighbor and weight of the edge connecting to it 
                                                   // Pointer to neighbor is the 'key' here and the distance to neighbor is the 'value' in this map. 
};

class Graph {
public:
    Graph(char c[]);
    void insertNeighbors(std::unordered_map <Vertex*, int> neighbors);

private:
    std::set <Vertex> vertices;                   // Store every unique vertex here, edge information will be stored in the vertices. 
                                                  // Implemented as set to prevent duplicate vertices getting in. 
};

Graph::Graph(char c[]) {                          // When graph is intiialized with char array, insert vertices into the graph using those characters. 
    int i{};
    while(c[i] != '\0')
    {
        vertices.emplace(c[i]);
        ++i;
    }
}

void Graph::insertNeighbors(std::unordered_map <Vertex*, int> neighbors) {


}
int main(int argc, char const *argv[])
{
    
    return 0;
}
