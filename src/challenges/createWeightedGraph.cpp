#include <iostream>
#include <unordered_set>
#include <set>
#include <map>
#include <vector>
#include <algorithm>


class Vertex {
public:
    friend std::ostream &operator<<(std::ostream &os, const Vertex &v);
    friend bool operator==(const std::pair<Vertex, int> & v1, const std::pair<Vertex, int> & v2);
    Vertex(char c) : ID_(c) {}
    bool operator==(const Vertex &rhs) const {
        return (this->ID_ == rhs.ID_);
    }
    bool operator<(const Vertex &rhs) const {
        return (this->ID_ < rhs.ID_);
    }

    char ID_;
    mutable std::map<Vertex, int> neighbors;

    
};

bool operator==(const std::pair<Vertex, int> & v1, const std::pair<Vertex, int> & v2) {
    return ((v1.first == v2.first) && (v1.second == v2.second));
}

class Graph {
public:
    friend std::ostream &operator<<(std::ostream &os, const Graph &g);

    Graph(); 
    Graph(char c[]);
    void insertVertex(char c);
    void insertEdge(char ID1, char ID2, int weight);
    void insertEdges(char ID1[], char ID2[], std::vector<int> weights);
    void viewNeighbors(char c);

    std::set<Vertex> vertices_;
};

Graph::Graph(char c[]) {
    int index{};
    while(c[index] != '\0') {
        vertices_.insert(c[index]);
        ++index;
    }
}

void Graph::insertVertex(char c) {
    vertices_.insert(c);
}

void Graph::insertEdge(char c1, char c2, int w) {
    auto it1 = vertices_.find(c1);
    auto it2 = vertices_.find(c2);
    auto p1 = std::make_pair(*it1, w);
    auto p2 = std::make_pair(*it2, w);

    if(it1 != vertices_.end())
        (*it1).neighbors.insert(p2);
    if(it2 != vertices_.end())
        (*it2).neighbors.insert(p1);
}

void Graph::viewNeighbors(char c) {
    auto it = vertices_.find(c);
    for(const auto &elem : it->neighbors) 
        std::cout << elem.first << " " << elem.second << std::endl;
    
}

std::ostream &operator<<(std::ostream &os, const Vertex &v) {
    os << v.ID_;
    return os;
}

std::ostream &operator<<(std::ostream &os, const Graph &g) {
    for(const auto &elem : g.vertices_) {
        os << elem << " ";
    }
    return os;
}

int main(int argc, char const *argv[])
{
    char letters[] {'A', 'C', 'D', 'E', 'B', 'F', 'I', 'H', 'G', '\0'};
    Graph graph(letters);
    std::cout << graph << std::endl;
    graph.insertEdge('A', 'B', 9);
    graph.insertEdge('A', 'C', 5);
    graph.insertEdge('A', 'D', 2);
    graph.insertEdge('B', 'E', 6);
    graph.insertEdge('B', 'C', 1);
    graph.insertEdge('C', 'D', 2);
    graph.insertEdge('C', 'F', 7);
    graph.insertEdge('C', 'G', 4);
    graph.insertEdge('F', 'I', 1);
    graph.insertEdge('G', 'H', 3);

    graph.viewNeighbors('A');

    return 0;
}


