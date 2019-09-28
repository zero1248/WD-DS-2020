/*
*********************************************************************************************************
*
* file name:   BinTree.cpp
* creator:     Isaac
* date:        20190413
* description: binary tree member functioin
*
*********************************************************************************************************
*/

#ifndef __BINTREE_H__
#define __BINTREE_H__

#include <iostream>
#include "BinNode.h"

using namespace std;

/**********************************************************************/
/*
 * insert a root node into the binary tree
 * Parameters: init_data
 * Returns: _root
 */
/**********************************************************************/
template<typename T>  
BTNode<T> *BinTree<T>::InsertRoot(const T &e){

    _root = new BTNode<T>(e);
    _size = 1;

    return _root;
}


template<typename T> 
BTNode<T>* BinTree<T>::InsertLC(BTNode<T>* p, const T &e){

    p -> lc = new BTNode<T>(e, this);
    _size++;

    return p -> lc;
}


template<typename T>
BTNode<T>* BinTree<T>::InsertRC(BTNode<T>* p, const T &e){

    p -> rc = new BTNode<T>(e, this);
    _size++;

    return p -> rc;
}


// template<typename T>
// BTNode<T>* BinTree<T>::AttachLC(BTNode<T>* p, BinTree<T>* &T){


// }


// template<typename T>
// BTNode<T>* BinTree<T>::AttachRC(BTNode<T>* p, BinTree<T>* &T){


// }


//返回父节点，从结点 somenode 开始，搜索 cur 结点的父结点
BTNode<T>* Parent(BTNode<T>* somenode, BTNode<T>* cur){

    BTNode<T>* p; 
    if(cur == NULL)
        return NULL;
    
    if(somenode->lc == cur || somenode->rc == cur)  //找到则返回父结点
        return somenode;
      
    if((p = Parent(somenode->lc, cur)) != NULL)  //左子树递归查找
        return p;
    else   //右子树递归查找
        return Parent(somenode->rc, cur);
}























// 析构
template<typename T>  //删除 p 节点及其后代，返回被删除节点的数值
int BinTree<T>::destroy(BTNode<T>* p){

    return 0;
}


//void call(){
//    BinTree<int> Tree;
//    Tree.InsertRoot(123);
//
//}



#endif __BINTREE_H__



