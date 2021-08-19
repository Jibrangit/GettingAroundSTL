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
            // cout << letters.at(index) << endl;
            if(tempNode->right == nullptr)
            {
                tempNode->right = new Node;
                (tempNode->right)->letter = letters.at(index);
                ++index;
                tempNode = rootNode;
            }
            else
            {
                tempNode = tempNode->right;
            }
                
        }

        if(letters[index] < tempNode->letter)
        {
            // cout << letters.at(index) << endl;
            if(tempNode->left == nullptr)
            {
                tempNode->left = new Node;  
                (tempNode->left)->letter = letters.at(index);
                ++index;
                tempNode = rootNode;

            }
            else
            {
                tempNode = tempNode->left;
            }
        }
        
    }
}
int main(int argc, char const *argv[])
{
    std::vector<char> letters= {'L', 'C', 'I', 'H', 'T', 'X', 'J', 'R', '\0'};
    Tree tree(letters);
    tree.createTree();
    cout << tree.getRoot()->right->right->letter << endl;


    return 0;
}
