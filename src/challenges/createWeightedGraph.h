#pragma once

#include <iostream>
#include <unordered_set>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <queue>

class Vertex {
public:
    friend std::ostream &operator<<(std::ostream &os, const Vertex &v);
    friend bool operator==(const std::pair<Vertex, int> & v1, const std::pair<Vertex, int> & v2);
    friend bool operator==(const std::pair<Vertex*, int> &v1, const std::pair<Vertex*, int> & v2);
    Vertex(char c) : ID_(c) {}
    bool operator==(const Vertex &rhs) const {
        return (this->ID_ == rhs.ID_);
    }
    bool operator<(const Vertex &rhs) const {
        return (this->ID_ < rhs.ID_);
    }

    char ID_;
    std::map<Vertex*, int> neighbors;
    bool visited{false};   
};

class Graph {
public:
    friend std::ostream &operator<<(std::ostream &os, const Graph &g);
    friend std::ostream &operator<<(std::ostream &os, const Vertex* &v);
    Graph(); 
    Graph(char c[]);
    void insertVertex(char c);
    void insertEdge(char ID1, char ID2, int weight);
    void insertEdges(char ID1[], char ID2[], std::vector<int> weights);
    void viewNeighbors(char c);
    void depthFirstTraversal();
    void breadthFirstTraversal();
    

    std::unordered_map<char, Vertex*> vertices_;
    std::stack<Vertex*> depthStack;
    std::queue<Vertex*> breadthQueue;
};

