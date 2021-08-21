#include <iostream>
#include <unordered_set>
#include <set>
#include <map>
#include <vector>


class Vertex {
public:
    friend std::ostream &operator<<(std::ostream &os, const Vertex &v);
    Vertex(char c) : ID_(c) {}
    bool operator==(const Vertex &rhs) const {
        return (this->ID_ == rhs.ID_);
    }
    bool operator<(const Vertex &rhs) const {
        return (this->ID_ < rhs.ID_);
    }

    char ID_;
    std::vector<std::pair<Vertex, int>> neighbors;
    void insertEdge(char c, int weight);
};

class Graph {
public:
    friend std::ostream &operator<<(std::ostream &os, const Graph &g);
    Graph(); 
    Graph(char c[]);
    void insertVertex(char c);
    void insertEdge(char ID1, char ID2, int weight);

protected:
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
    // auto it1 = vertices_.find(c1);
    // auto it2 = vertices_.find(c2);
    // auto p1 = std::make_pair(*it1, w);

    // it1->neighbors.pop_back();
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
    char letters[] {'A', 'C', 'D', 'E', 'B', '\0'};
    Graph graph(letters);
    std::cout << graph << std::endl;

    return 0;
}


