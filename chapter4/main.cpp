/*
*********************************************************************************************************
*
* file name:   main.cpp
* creator:     Isaac
* date:        20190403
* description: test the data sturcture module(chapter4)
*
*********************************************************************************************************
*/

#include <iostream>
#include "BinTree.h"
#include "BinNode.h"

using namespace std;

template <class T>
void visit(BTNode<T>* p );

int main(){

    BinTree<int> Tree;
    BTNode<int> *p, *q, *r;

    p = Tree.insertRoot(123);
    q = Tree.insertLC(Tree.Root(), 234);
    r = Tree.insertRC(Tree.Root(), 345);


    cout << p->data << endl << q->data << endl << r->data << endl;

    Tree.InOrder(visit);




    return 0;
}



template <class T>
void visit(BTNode<T>* p ){

    cout << p->data << " ";

}


