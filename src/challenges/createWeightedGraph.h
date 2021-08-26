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
#include <forward_list>

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

struct Node {
    Node(Vertex *v) {
        curr_node = v;
    }
    Node(Vertex *v, int dist) {
        curr_node = v;
        shortest_distance_to_start = dist;
    }
    bool operator==(const Node &rhs) {
        return (this->curr_node->ID_ == rhs.curr_node->ID_);
    }
    bool operator==(char c) {
        return (this->curr_node->ID_ == c);
    }
    Vertex *curr_node;
    Vertex *prev_node;
    int shortest_distance_to_start;
};

class Graph {
public:
    friend std::ostream &operator<<(std::ostream &os, const Graph &g);
    friend std::ostream &operator<<(std::ostream &os, const Vertex* &v);
    friend bool operator==(const std::pair<Node, int> &v1, const std::pair<Node, int> &v2);
    friend bool operator<(const std::pair<Node, int> &v1, const std::pair<Node, int> &v2);
    friend bool operator==(const Node &n1, const Node &n2);
    friend bool operator<(const Node &n1, const Node &n2);
    Graph(); 
    Graph(char c[]);
    ~Graph();
    void insertVertex(char c);
    void insertEdge(char ID1, char ID2, int weight);
    void insertEdges(char ID1[], char ID2[], std::vector<int> weights);
    void viewNeighbors(char c);
    void depthFirstTraversal();
    void breadthFirstTraversal();
    void Dijkstra();
    void updateSetElement(char curr_vertex, int shortest_dist, Vertex* v);
    Node accessSetElement(char c);
    void removeSetElement(char c);
    void printPath(char c);
    

    std::unordered_map<char, Vertex*> vertices_;
    std::stack<Vertex*> depthStack;
    std::queue<Vertex*> breadthQueue;
    std::set<Node> visited_nodes;
    std::set<Node> unvisited;
};

