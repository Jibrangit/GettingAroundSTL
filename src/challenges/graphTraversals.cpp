#include "createWeightedGraph.h"

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

    graph.viewNeighbors('H');

    graph.depthFirstTraversal();

    graph.breadthFirstTraversal();

    return 0;
}
