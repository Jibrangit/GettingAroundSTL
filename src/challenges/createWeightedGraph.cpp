#include "createWeightedGraph.h"

bool operator==(const std::pair<Vertex, int> & v1, const std::pair<Vertex, int> & v2) {
    return ((v1.first == v2.first) && (v1.second == v2.second));
}

bool operator==(const std::pair<Vertex*, int> &v1, const std::pair<Vertex*, int> & v2) {
    return (*(v1.first) == *(v2.first));
}


Graph::Graph(char c[]) {
    int index{};
    while(c[index] != '\0') {
        auto v = new Vertex(c[index]);
        auto p = std::make_pair(c[index], v);
        vertices_.insert(p);
        ++index;
    }
}

void Graph::insertVertex(char c) {
    auto v = new Vertex(c);
    auto p = std::make_pair(c, v);

    vertices_.insert(p);
}

void Graph::insertEdge(char c1, char c2, int w) {
    auto it1 = vertices_.find(c1);
    auto it2 = vertices_.find(c2);

    auto p1 = std::make_pair(it1->second, w);
    auto p2 = std::make_pair(it2->second, w);

    it1->second->neighbors.insert(p2);
    it2->second->neighbors.insert(p1);
}

void Graph::viewNeighbors(char c) {
    auto it = vertices_.find(c);
    for(const auto &elem : it->second->neighbors) 
        std::cout << *elem.first << " " << elem.second << std::endl;
    
}

std::ostream &operator<<(std::ostream &os, const Vertex &v) {
    os << v.ID_;
    return os;
}

std::ostream &operator<<(std::ostream &os, const Graph &g) {
    for(const auto &elem : g.vertices_) {
        os << elem.first << " ";
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const Vertex* &v) {
    os << v->ID_;
    return os;
}


void Graph::depthFirstTraversal() {
    depthStack.push(vertices_.at('A'));
    depthStack.top()->visited = true;
    std::cout << depthStack.top()->ID_ << " ==> ";

    while(!depthStack.empty()) {
        auto it = depthStack.top()->neighbors.begin();
        while((it!= (depthStack.top()->neighbors.end())))
        {
            if(it->first->visited)                          // Didnt put as AND in the while as iterator end() behavior is undefined
                std::advance(it, 1);
            else
                break;
        }
        if(it == ((depthStack.top()->neighbors).end())) {
            depthStack.pop();

        }
        else {
            depthStack.push(it->first);
            depthStack.top()->visited = true;
        }
        if(!depthStack.empty()) 
            std::cout << depthStack.top()->ID_ << " ==> ";
    }

}

void Graph::breadthFirstTraversal() {
    breadthQueue.push(vertices_.at('A'));
    breadthQueue.front()->visited = true;
    std::cout << breadthQueue.front()->ID_ << " ==> ";


    while(!breadthQueue.empty()) {
        auto it = breadthQueue.front()->neighbors.begin();
        while(it != breadthQueue.front()->neighbors.end()) {
            if(it->first->visited)
                std::advance(it, 1);
            else {
                it->first->visited = true;
                breadthQueue.push(it->first);
            }
        }
        
        if(it == breadthQueue.front()->neighbors.end())
            breadthQueue.pop();
        

        if(!breadthQueue.empty())
            std::cout << breadthQueue.front()->ID_ << " ==> ";
    }
}
int main(int argc, char const *argv[])
{
    char letters[] {'A', 'C', 'D', 'E', 'B', 'F', 'I', 'H', 'G', '\0'};
    Graph graph(letters);
    // std::cout << graph << std::endl;
    graph.insertEdge('A', 'B', 9);
    graph.insertEdge('A', 'C', 5);
    graph.insertEdge('A', 'D', 2);
    graph.insertEdge('B', 'E', 6);
    graph.insertEdge('B', 'C', 1);
    graph.insertEdge('C', 'D', 2);
    graph.insertEdge('C', 'F', 7);
    graph.insertEdge('C', 'G', 4);
    graph.insertEdge('D', 'G', 5);
    graph.insertEdge('F', 'I', 1);
    graph.insertEdge('G', 'H', 3);

    // graph.viewNeighbors('H');


    ///////////////////////////////////// D E P T H  F I R S T  T R A V E R S A L ////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    // graph.depthFirstTraversal();
    graph.breadthFirstTraversal();



    return 0;
}


