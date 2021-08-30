#include "createWeightedGraph.h"

int main(int argc, char const *argv[])
{
    char letters[] {'A', 'C', 'D', 'E', 'B', 'F', 'I', 'H', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', '\0'};
    Graph graph(letters);

    graph.insertEdge('A', 'B', 5);
    graph.insertEdge('A', 'C', 5);
    graph.insertEdge('B', 'C', 4);
    graph.insertEdge('B', 'D', 3);
    graph.insertEdge('C', 'E', 7);
    graph.insertEdge('C', 'H', 7);
    graph.insertEdge('D', 'H', 11);
    graph.insertEdge('D', 'M', 14);
    graph.insertEdge('D', 'L', 13);
    graph.insertEdge('D', 'K', 16);
    graph.insertEdge('E', 'F', 4);
    graph.insertEdge('E', 'H', 5);
    graph.insertEdge('F', 'G', 9);
    graph.insertEdge('G', 'N', 12);
    graph.insertEdge('H', 'I', 3);
    graph.insertEdge('I', 'J', 4);
    graph.insertEdge('J', 'N', 3);
    graph.insertEdge('J', 'P', 8);
    graph.insertEdge('K', 'L', 5);
    graph.insertEdge('K', 'P', 4);
    graph.insertEdge('K', 'N', 7);
    graph.insertEdge('L', 'O', 4);
    graph.insertEdge('M', 'O', 5);
    graph.insertEdge('N', 'P', 7);

    int heuristics[] = {16, 17, 13, 16, 16, 20, 17, 11, 10, 8, 4, 7, 10, 7, 5, 0}; // Add for every node, estimated distance to end node. 
    
    // graph.viewNeighbors('K');
    // std::cout << graph << std::endl;
    graph.aStar(heuristics);


    return 0;
}
