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
#include <cstdlib>
#include "BinTree.h"
#include "BinNode.h"


using namespace std;

template <class T>
void visit(BTNode<T>* p);

int main(){

    BinTree<int> Tree;

    // BTNode<int> *p, *q, *r;  // 测试插入函数
    // p = Tree.insertRoot(1);
    // q = Tree.insertLC(Tree.Root(), 2);
    // r = Tree.insertRC(Tree.Root(), 3);
    // cout << p->data << endl << q->data << endl << r->data << endl;

    // int j;
    // BTNode<int> *p = Tree.insertRoot(0);  // 随机生成一棵树，用于测试
    // srand((unsigned)time(NULL));
    // for(int i=1; i<10; i++){
    //     switch(j = rand()%2){
    //         case 0: p = Tree.insertLC(p, i); break;
    //         case 1: p = Tree.insertRC(p, i); break;
    //         default : break;
    //     }
    //     cout << j << " ";
    // }
    Tree.generateTestTree(10);

    Tree.PreOrder(visit);
    cout << endl;
    Tree.InOrder(visit);
    cout << endl;
    Tree.PostOrder(visit);
    cout << endl;
    Tree.LevelOrder(visit);
    cout << endl;


    return 0;
}


template <class T>
void visit(BTNode<T>* p){

    cout << p->data << " ";

}


