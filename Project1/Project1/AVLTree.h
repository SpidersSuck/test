#include "AVLNode.h"

using namespace std;

/*********************constructer/destructor/retreive node **********************************/
template <class T>
class AVLTree
{
    AVLNode<T>* root;

public:
    AVLTree() {
        root = NULL;
    }

    void insert(T data) {
        this->root = insert(this->root, data);
    }

    int height() {
        return retreiveHeight(this->root);
    }

    bool contains(T data) {
        return search(this->root, data);
    }

    bool validate() {
        return isTreeBalanced(this->root);
    }

    ~AVLTree() {
        delete root;
    }

private: 

    int retreiveHeight(AVLNode<T>* apex) {
        return (apex == NULL) ? 0 : apex->height;
    }

    int stabalizeApex(AVLNode<T>* apex) {
        return (apex == NULL) ? 0 : retreiveHeight(apex->pointLeft) - retreiveHeight(apex->pointRight);
    }
    /*****************************************************************************************************/

    /**************************************************** Right Rotation **********************************/

    AVLNode<T>* RotationR(AVLNode<T>* apex)
    {
        AVLNode<T>* leftApex = apex->pointLeft;
        AVLNode<T>* temp = leftApex->pointRight;

        leftApex->pointRight = apex;
        apex->pointLeft = temp;

        leftApex->height = max(retreiveHeight(leftApex->pointLeft), retreiveHeight(leftApex->pointRight)) + 1;
        apex->height = max(retreiveHeight(apex->pointLeft), retreiveHeight(apex->pointRight)) + 1;

        return leftApex;
    }

    /*****************************************************************************************************/

    /**************************************************** Left Rotation **********************************/
    AVLNode<T>* RotationL(AVLNode<T>* apex)
    {
        AVLNode<T>* rightApex = apex->pointRight;
        AVLNode<T>* tmp = rightApex->pointLeft;

        rightApex->pointLeft = apex;
        apex->pointRight = tmp;

        apex->height = max(retreiveHeight(apex->pointLeft), retreiveHeight(apex->pointRight)) + 1;
        rightApex->height = max(retreiveHeight(rightApex->pointLeft), retreiveHeight(rightApex->pointRight)) + 1;

        return rightApex;
    }

    /*****************************************************************************************************/

    /**************************************************** insertion **************************************/
    AVLNode<T>* insert(AVLNode<T>* cursor, T data) {
        if (cursor == NULL)
            return new AVLNode<T>(data);


        if (data < cursor->data)
            cursor->pointLeft = insert(cursor->pointLeft, data);
        else if (data > cursor->data)
            cursor->pointRight = insert(cursor->pointRight, data);
        else
            return cursor;

        cursor->height = max(retreiveHeight(cursor->pointLeft), retreiveHeight(cursor->pointRight)) + 1;
        int balance = stabalizeApex(cursor);

        if (balance > 1 && data < cursor->pointLeft->data) {
            return RotationR(cursor);
        }

        if (balance < -1 && data > cursor->pointRight->data) {
            return RotationL(cursor);
        }

        if (balance > 1 && data > cursor->pointLeft->data) {
            cursor->pointLeft = RotationL(cursor->pointLeft);
            return RotationR(cursor);
        }

        if (balance < -1 && data < cursor->pointRight->data) {
            cursor->pointRight = RotationR(cursor->pointRight);
            return RotationL(cursor);
        }

        return cursor;
    }

    /*****************************************************************************************************/

    /******************************************* recur check if tree is balanced **********************************/
    bool search(AVLNode<T>* cursor, T data) {
        if (cursor) {
            if (cursor->data == data)
                return 1;
            else
                return search(cursor->pointLeft, data) || search(cursor->pointRight, data);
        }
        return 0;
    }

    bool isTreeBalanced(AVLNode<T>* cursor) {
        if (cursor == NULL)
            return 1;
        if (abs(retreiveHeight(cursor->pointLeft) - retreiveHeight(cursor->pointRight)) <= 1)
            return isTreeBalanced(cursor->pointRight) && isTreeBalanced(cursor->pointLeft);
        return 0;
    }

    /*****************************************************************************************************/

}; 
