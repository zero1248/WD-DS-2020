#include <iostream>
//#include "binary_tree.cpp"
#include "binary_tree.h"

using namespace std;

int main(){

//    BinTree<int> Tree;
//    BTNode<int> *p, *q;
    BinTree<int> Tree;
    BTNode<int> *p;
    p = Tree.InsertRoot(123);
//    q = Tree.InsertLC(p, 2);

    cout << p->data << endl;
//    cout << p->data << endl << q->data << endl;





    return 0;
}
