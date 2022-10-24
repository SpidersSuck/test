#include "AVLTree.h"
using namespace std;


int main() {

    vector<int> order1, order2, order3;

    for (int j = 1; j < 100; j += 2) 
    {   
        order1.push_back(j); order2.push_back(j); order3.push_back(j);
    }
    shuffle(order3.begin(), 
            order3.end(),
            default_random_engine(0)
    );
    reverse(
        order2.begin(), 
        order2.end()
    ); 


    /*****************************   Tree 1   ************************************************/

    AVLTree<int>* AVLTree1 = new AVLTree<int>();
    cout << "********** AVLTree 1 ********** \n";
    for (int j : order1)
        AVLTree1->insert(j);
    cout << "Height of AVLTree1: " << AVLTree1->height() << endl;
    for (int j = 1; j <= 100; j++) {
        bool equals = AVLTree1->contains(j);
        if ((equals && j % 2 == 0) || (!equals && j % 2 == 1))
            cout << "My AVL tree implementation is wrong”\n";
        else
            cout << j <<" : " << (equals ? "odd\n" : "even\n");
    }
    cout << "AVLTree1 Validation: " << AVLTree1->validate() << endl;
    /****************************************************************************************/

    /********************************* Tree 2   ********************************************/

    cout << "********* AVLTree 2 ********** \n";
    AVLTree<int>* AVLTree2 = new AVLTree<int>();
    for (int j : order1)
        AVLTree2->insert(j);

    cout << "Height of AVLTree2: " << AVLTree2->height() << endl;
    for (int j = 1; j <= 100; j++) {
        bool equals = AVLTree2->contains(j);
        if ((!equals && j % 2 == 1) || (equals && j % 2 == 0))
            cout << "My AVL tree implementation is wrong\n";
        else
            cout << j << " : " << (equals ? "odd\n" : "even\n");
    }
    cout << "AVLTree2 Validation: " << AVLTree2->validate() << endl;

    /****************************************************************************************/

    /******************************   Tree 3   ***********************************************/

    cout << "********* AVLTree 3 **********  \n";
    AVLTree<int>* AVLTree3 = new AVLTree<int>();
    for (int j : order3)
        AVLTree3->insert(j);
    cout << "AVLTree3 Height: " << AVLTree3->height() << endl;
    for (int j = 1; j <= 100; j++) {
        bool equals = AVLTree3->contains(j);
        if ((equals && j % 2 == 0) || (!equals && j % 2 == 1))
            cout << "My AVL tree implementation is wrong\n";
        else
            cout << j << " : " << (equals ? "odd\n" : "even\n");
    }
    cout << "AVLTree3 Validation: " << AVLTree3->validate() << endl;
    return 0;
}
/****************************************************************************************/