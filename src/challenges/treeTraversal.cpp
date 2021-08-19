#include <iostream>
#include <vector>

using namespace std;

struct Node {
    Node *left{nullptr};
    Node *right{nullptr};
    char letter{'\0'};
};

class Tree {
public:
    Tree(std::vector<char> l) : letters(l) {
        rootNode = new Node;
    }
    void createTree();
    Node* getRoot() {return rootNode;}
    void preOrderTraversal(Node *);
    void postOrderTraversal(Node *);
    void inOrderTraversal(Node *);
    ~Tree() {delete rootNode; }
    
private:
    Node *rootNode;
    Node *tempNode;
    std::vector<char> letters;

};

void Tree::createTree() {

    rootNode->letter = letters.at(0);
    tempNode = rootNode;
    int index = 0;
    ++index;

    while(letters[index] != '\0')
    {
        if(letters[index] > tempNode->letter)
        {
            if(tempNode->right == nullptr)
            {
                tempNode->right = new Node;
                (tempNode->right)->letter = letters.at(index);
                ++index;
                tempNode = rootNode;
            }
            else
                tempNode = tempNode->right;      
        }

        if(letters[index] < tempNode->letter)
        {
            if(tempNode->left == nullptr)
            {
                tempNode->left = new Node;  
                (tempNode->left)->letter = letters.at(index);
                ++index;
                tempNode = rootNode;

            }
            else
                tempNode = tempNode->left;
        }
        
    }
}

void Tree::preOrderTraversal(Node *node)
{
    if(node == nullptr)                              // When the last node (leaf) is hit, this ends that call and it gets popped off the stack and goes back to previous node. 
        return;
    
    cout << node->letter << endl;

    preOrderTraversal(node->left);                    // Keeps going to left sub-trees, ditto for the right. 

    preOrderTraversal(node->right);

}

void Tree::postOrderTraversal(Node *node)
{
    if(node == nullptr)
        return;
    
    postOrderTraversal(node->left);

    postOrderTraversal(node->right);
    
    cout << node->letter << endl;
}

void Tree::inOrderTraversal(Node *node)
{
    if(node == nullptr)
        return;
    
    inOrderTraversal(node->left);

    cout << node->letter << endl;

    inOrderTraversal(node->right);
}
int main(int argc, char const *argv[])
{
    std::vector<char> letters= {'L', 'C', 'I', 'H', 'T', 'X', 'J', 'R', '\0'};
    Tree tree(letters);
    tree.createTree();
    // cout << tree.getRoot()->right->right->letter << endl; // Testing the tree

    // tree.preOrderTraversal(tree.getRoot());
    // tree.postOrderTraversal(tree.getRoot());
    tree.inOrderTraversal(tree.getRoot());


    return 0;
}
