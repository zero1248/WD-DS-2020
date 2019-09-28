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


template<typename T>  // 二叉树结点模板
struct BTNode{
    T data;
    BTNode<T> *parent; // 父结点
    BTNode<T> *lc, *rc; // 左右孩子
    // height; // 记录结点所处的高度

    BTNode():  // 构造函数1，实例化时不指定参数，默认为空
        data(0),
        parent(NULL),
        lc(NULL),
        rc(NULL){}

    // 构造函数2，实例化时可指定参数
    BTNode(const T &e, BTNode<T>* p = NULL, BTNode<T>* l = NULL, BTNode<T>* r = NULL):
        data(e),
        parent(p),
        lc(l),
        rc(r){}

    BTNode<T>* insertAsLC(T const &e); //作为当前节点的左孩子插入新节点
    BTNode<T>* insertAsRC(T const &e); //作为当前节点的右孩子插入新节点

    // 先序遍历
    void PreOrder(void(*visit)(BTNode<T>*));
    // 中序遍历
    void InOrder(void(*visit)(BTNode<T>*));
    // 后序遍历
    void PostOrder(void(*visit)(BTNode<T>*));
    // 层次遍历
    void LevelOrder(void(*visit)(BTNode<T>*));
};

#include "BinNode_implementation.h"
#include "BinNode_traversal.h"

#endif // __BINNODE_H__

