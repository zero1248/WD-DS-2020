/*
*********************************************************************************************************
*
* file name:   binary_tree.h
* creator:     Isaac
* date:        20190413
* description: binary tree
*
*********************************************************************************************************
*/

#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <iostream>
using namespace std;

#define BTNodePos BTNode<T>*


template<typename T>
struct BTNode{
    T data;
    BTNode<T> *parent;
    BTNode<T> *lc, *rc;
    BTNode():
        data(0),
        parent(NULL),
        lc(NULL),
        rc(NULL){}

    BTNode(const T &e, BTNode<T> *p = NULL, BTNode<T> *l = NULL, BTNode<T> *r = NULL):
        data(e),
        parent(p),
        lc(l),
        rc(r){}
};

//typedef BTNode<T>* BTNodePos(T)


template<typename T>
class BinTree{

public:

    // 构造/析构
    BinTree(): _size(0), _root(NULL){}
    ~BinTree(){
//        if(_size > 0)
//            remove(_root);
    }
    // 基本操作

    BTNodePos Root() const{  // 获取二叉树根结点
        return _root;
    }
    int Size() const{  // 获取二叉树规模
        return _size;
    }
    bool isEmpty() const{ // 判空
        return !_root;
    }
    BTNodePos InsertRoot(const T &e);
    BTNodePos InsertLC(BTNodePos p, const T &e); // e 作为 x 的左孩子插入
    BTNodePos InsertRC(BTNodePos p, const T &e); // e 作为 x 的右孩子插入
//    BTNodePos AttachLC(BTNodePos p, BinTree<T>* &T); // T 作为 x 的左子树插入
//    BTNodePos AttachRC(BTNodePos p, BinTree<T>* &T); // T 作为 x 的右子树插入

    int remove(BTNodePos p);

private:

    BTNodePos _root; // 根结点
    int _size;   // 树的规模

};

#include "BinTree.h"

#endif // __BINARY_TREE_H__
