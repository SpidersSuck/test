#include <iostream> 
#include <random> 

using namespace std;
void insert();
void printTree();
bool contains();
void remove();
template <class T>
class AVLNode {
public:
    T data;
    AVLNode<T>* pointLeft;
    AVLNode<T>* pointRight;
    int height;

    AVLNode(T key) { 
        pointLeft = NULL;
        pointRight = NULL;
        data = key;
        height = 0;
    }

    ~AVLNode() {
        delete pointLeft;
        delete pointRight;
    }
};
