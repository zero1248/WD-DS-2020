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
void visit1(BTNode<T>* p);

int main(){

    BinTree<int> Tree;
    BTNode<int> *p, *q, *r;

    p = Tree.insertRoot(1);
    q = Tree.insertLC(Tree.Root(), 2);
    r = Tree.insertRC(Tree.Root(), 3);


    cout << p->data << endl << q->data << endl << r->data << endl;

    Tree.PreOrder(visit1);
    cout << endl;
    Tree.InOrder(visit1);
    cout << endl;
    Tree.PostOrder(visit1);
    cout << endl;
    

    cout << rand();


    return 0;
}


template <class T>
void visit1(BTNode<T>* p){

    cout << p->data << " ";

}


