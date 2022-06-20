#include <iostream>
#include <memory>
#include <vector>

struct Node {
    Node *left{nullptr};
    Node *right{nullptr};
    int x, y;
};

class KdTree {
public:
    void createTree(std::vector<);
    Node* getRoot() {return rootNode;}
    ~KdTree() {delete rootNode; }
    
private:
    Node *rootNode;
    Node *tempNode;
};

// void KdTree::createTree()