/*
*********************************************************************************************************
*
* file name:   BinNode.h
* creator:     Isaac
* date:        20190928
* description: binary tree node
* 
*********************************************************************************************************
*/

#ifndef __BINNODE_H__
#define __BINNODE_H__

#include <iostream>

using namespace std;

template<typename T>  // 二叉树结点模板
struct BTNode{
    T data;
    // BTNode<T> *parent;  // 父结点
    BTNode<T> *lc, *rc; // 左右孩子

    BTNode():  // 构造函数1，实例化时不指定参数，默认为空
        data(0),
        parent(NULL),
        lc(NULL),
        rc(NULL){}

    // 构造函数2，实例化时可指定参数
    BTNode(const T &e, BTNode<T> *p = NULL, BTNode<T> *l = NULL, BTNode<T> *r = NULL):  
        data(e),
        parent(p),
        lc(l),
        rc(r){}
};


#endif // __BINNODE_H__

