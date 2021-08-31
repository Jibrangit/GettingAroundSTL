#include "createWeightedGraph.h"

bool operator==(const std::pair<Vertex, int> & v1, const std::pair<Vertex, int> & v2) {
    return ((v1.first == v2.first) && (v1.second == v2.second));
}

bool operator==(const std::pair<Vertex*, int> &v1, const std::pair<Vertex*, int> & v2) {
    return (*(v1.first) == *(v2.first));
}

Graph::~Graph() {

    auto it = vertices_.begin();
    while(it != vertices_.end()) {
        delete it->second;
        std::advance(it, 1);
    }
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

    ///////////////////////////////////// D E P T H  F I R S T  T R A V E R S A L ////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////


void Graph::depthFirstTraversal() {
    depthStack.push(vertices_.at('A'));
    depthStack.top()->visited = true;
    std::cout << depthStack.top()->ID_ << " ==> ";

    while(!depthStack.empty()) {
        auto it = depthStack.top()->neighbors.begin();
        while((it!= (depthStack.top()->neighbors.end())))
        {
            if(it->first->visited)                          // Didnt put as 'AND' in the 'while' as iterator end() behavior is undefined.
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


///////////////////////////////////// B R E A D T H  F I R S T  T R A V E R S A L ////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////

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


///////////////////////////////////// D I J K S T R A ////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////

/** @brief : operators needed for sorting and accessing nodes held in the sets**/

bool operator==(const Node &n1, const Node &n2) {
    return (n1.curr_node->ID_ == n2.curr_node->ID_);
}

bool operator<(const Node &n1, const Node &n2) {
    if(n1.shortest_distance_to_start == n2.shortest_distance_to_start)
        return (n1.curr_node->ID_ < n2.curr_node->ID_);
    else
        return (n1.shortest_distance_to_start < n2.shortest_distance_to_start);
}

void Graph::updateSetElement(char c, int d, Vertex* v=nullptr, int h=-1) {
    auto it = unvisited.begin();
    while(it != unvisited.end()) {
        if(it->curr_node->ID_ == c) {
            auto p = *it;
            p.shortest_distance_to_start = d;

            if(v != nullptr)
                p.prev_node = v;

            if(h > 0)
                p.heuristic = h;

            unvisited.erase(*it);
            unvisited.emplace(p);

            
            break;
        }
        std::advance(it, 1);
    }
    if(it == unvisited.end()) 
        std::cerr << "No vertex found with given character! " << std::endl;
}
//=============================================================================================================//

Node Graph::accessSetElement(char c) {
    auto it = unvisited.begin();
    while(it != unvisited.end()) {
        if(it->curr_node->ID_ == c) {
            return *it;
        }
        std::advance(it, 1);
    }
    if(it == unvisited.end()) {
        auto it2 = visited_nodes.begin();
        while(it2 != visited_nodes.end()) {
        if(it2->curr_node->ID_ == c) {
            return *it2;
        }
        std::advance(it2, 1);
    }
    if(it2 == visited_nodes.end())
        std::cerr << "Requested Node could not be found! " << std::endl;
    }
}

void Graph::removeSetElement(char c) {

    auto it = unvisited.begin();
    while(it != unvisited.end()) {
        if(it->curr_node->ID_ == c) {
            unvisited.erase(*it);
            break;
        }
        std::advance(it, 1);
    }
    if(it == unvisited.end())
        std::cerr << "Requested element could not be removed!" << std::endl;
}

void Graph::printPath(char c) {
    std::cout << "Path to " << c << std::endl;
    auto n = accessSetElement(c);
    std::cout << n.curr_node->ID_  << " <== ";
    std::cout << n.prev_node->ID_  << " <== ";
    while(n.prev_node->ID_ != 'A') {
        n = accessSetElement(n.prev_node->ID_);
        std::cout << n.prev_node->ID_  << " <== ";
    }
    std::cout << std::endl;
    
}

void Graph::Dijkstra() {

    // Adding all nodes to unvisited map, initializing initial distance from start with a very large number.
    auto it = vertices_.begin();
    while(it != vertices_.end()) {
        unvisited.emplace(it->second, 100000);
        std::advance(it, 1);
    }

    // Update 'A' which is the start node to have 0 distance and prev_vertex equal to itself.
    updateSetElement('A', 0, vertices_.at('A'));             

    Vertex* v = unvisited.begin()->curr_node;
    int dist_from_start{};

    while(!unvisited.empty()) {

        // Calculate distance of neighbors from start vertex (distance of current node from start + distance of neighbor from current node)
        for(const auto &elem : v->neighbors) {
            dist_from_start = elem.second + unvisited.begin()->shortest_distance_to_start; 
            auto currentNeighbor = accessSetElement(elem.first->ID_);
            // If the calculated distance is less than the shortest distance stored in the node, update that node with the distance and its parent node.
            if(dist_from_start < currentNeighbor.shortest_distance_to_start)
                updateSetElement(currentNeighbor.curr_node->ID_, dist_from_start, v); 
        }

        // After exploring all neighbors, add vertex to visited list, and remove the node from unvisited set. 
        v->visited = true;
        visited_nodes.insert(*(unvisited.begin()));
        unvisited.erase(*unvisited.begin());

        // Update current_node
        v = unvisited.begin()->curr_node;

        // std::cout << "[ ";
        // for(const auto &elem : unvisited)
        //     std::cout << elem.curr_node->ID_ << " ";
        // std::cout << "]" <<  std::endl;
        
    }

    // std::cout << "SHORTEST DISTANCE OF EVERY NODE FROM START : " << std::endl;
    // for(const auto &elem : visited_nodes)
    //     std::cout << "[A" << " ==> " << elem.curr_node->ID_ << "] : " << elem.shortest_distance_to_start << std::endl;

    printPath('H');
}



///////////////////////////////////// A  S T A R ////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////

/** @brief : In this case the cost at every node is the shortest distance to start until that node, same as Dijkstra, but additionally the heuristic, which here is randomly assigned.
 * In a grid that heuristic would be the distance to that end node. Here, its just an estimate.
 * */

void Graph::aStar(int heuristics[]) {
    // Adding all nodes to unvisited map, initializing initial distance from start with a very large number.
    auto it = vertices_.begin();
    int idx{};
    while(it != vertices_.end()) {
        unvisited.emplace(it->second, 100000, heuristics[idx]);
        std::advance(it, 1);
        ++idx;
    }

    // Update 'A' which is the start node to have 0 distance and prev_vertex equal to itself.
    updateSetElement('A', 0, vertices_.at('A'));             

    Vertex* v = unvisited.begin()->curr_node;
    int dist_from_start{};

    while(!unvisited.empty()) {

        // Calculate distance of neighbors from start vertex (distance of current node from start + distance of neighbor from current node)
        for(const auto &elem : v->neighbors) {
            dist_from_start = elem.second + unvisited.begin()->shortest_distance_to_start; 
            auto currentNeighbor = accessSetElement(elem.first->ID_);
            // If the calculated distance is less than the shortest distance stored in the node, update that node with the distance and its parent node.
            if(dist_from_start < currentNeighbor.shortest_distance_to_start)
                updateSetElement(currentNeighbor.curr_node->ID_, dist_from_start, v); 
        }

        // After exploring all neighbors, add vertex to visited list, and remove the node from unvisited set. 
        v->visited = true;
        visited_nodes.insert(*(unvisited.begin()));
        unvisited.erase(*unvisited.begin());

        // Update current_node
        v = unvisited.begin()->curr_node;

        // std::cout << "[ ";
        // for(const auto &elem : unvisited)
        //     std::cout << elem.curr_node->ID_ << " ";
        // std::cout << "]" <<  std::endl;
        
    }

}