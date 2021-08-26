#include <iostream>
#include <vector>
#include <map>
#include <queue>

/** @brief : Determine what are the neighbors of every index and store those pointers (posiitons in the array)
 * This creates a graph, now we can do a BFS through the graph to determine of a path exists
 * */

class Vertex {
public:
    Vertex(int* ptr) : ptr_to_index_(ptr) {}
    std::vector<int*> neighbors;
    int* ptr_to_index_;
    bool visited{false};  

    // Operators for accessing and mutating the vector of vertex pointers
    bool operator==(const Vertex &rhs) {
        return (*(this->ptr_to_index_) == *(rhs.ptr_to_index_)); 
    }
    bool operator<(const Vertex &rhs) {
        return (*(this->ptr_to_index_) < *(rhs.ptr_to_index_));
    }
};


bool areTheyNeighbors(int pos1, int pos2, int reach1, int reach2) {
    if((pos2 - reach2) < (pos1 - reach1) < (pos2 + reach2))
        return true;
    else if((pos2 - reach2) < (pos1 + reach1) < (pos2 + reach2))
        return true;
    else if((pos1 - reach1) == (pos2 - reach2))
        return true;
    else if((pos1 - reach1) == (pos2 + reach2))
        return true;
    else if((pos1 + reach1) == (pos2 - reach2))
        return true;
    else if((pos1 + reach1) == (pos2 + reach2))
        return true;
    
    else    
        return false;
}

bool breadthFirstTraversal() {
    std::queue<Vertex*> breadthQueue;
    breadthQueue.front()->visited = true;


    while(!breadthQueue.empty()) {
        auto it = breadthQueue.front()->neighbors.begin();
        while(it != breadthQueue.front()->neighbors.end()) {
            if(*(it)->visited)
                std::advance(it, 1);
            else {
                *(it)->visited = true;
                breadthQueue.push(it->first);
            }
        }
        
        if(it == breadthQueue.front()->neighbors.end())
            breadthQueue.pop();
        
    }
}

bool Solution(std::vector<int> A, std::vector<int> P, int B, int E) {
    std::vector<Vertex*> nodes;

    for(int i{}; i< A.size(); i++ ) {             
       nodes.emplace_back(&A[i]);
    }

    for(int i{}; i< A.size(); i++) {                 // Create edges between vertices if one exists [ O(n^2), I know thats bad :( ]
        for(int j{}; j < A.size(); j++) {
            if(areTheyNeighbors(P.at(i), P.at(j), A.at(i), A.at(j)))
            {
                nodes.at(i)->neighbors.emplace_back(&A[j]);
            }
                
        }
    }

    // Now that all neigbors have been added, we can search through these vector of vertices using DFS or BFS


}

int main(int argc, char const *argv[])
{
    
    return 0;
}
