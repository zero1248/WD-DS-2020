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
#include "BinNode.h"

using namespace std;


template<typename T> // 二叉树模板
class BinTree{

public:
    // 构造/析构
    BinTree(): _size(0), _root(NULL){}
    ~BinTree(){
    //    if(_size > 0){
    //         destroy(_root);
    //         // remove(_root);
    //    }
    }

    // 基本操作

    BTNode<T>* InsertRoot(const T &e); // 树中插入根结点
    BTNode<T>* InsertLC(BTNode<T>* p, const T &e); // e 作为 x 的左孩子插入
    BTNode<T>* InsertRC(BTNode<T>* p, const T &e); // e 作为 x 的右孩子插入
//    BTNode<T>* AttachLC(BTNode<T>* p, BinTree<T>* &T); // T 作为 x 的左子树插入
//    BTNode<T>* AttachRC(BTNode<T>* p, BinTree<T>* &T); // T 作为 x 的右子树插入

    BTNode<T>* Root() const{  // 获取二叉树根结点
        return _root;
    }

    int Size() const{  // 获取二叉树规模
        return _size;
    }

    bool isEmpty() const{ // 判空
        return !_root;
    }

    BTNode<T>* Parent(BTNode<T>* cur) const{ // 返回某结点的父结点
        return (_root == NULL || _root == cur) ? NULL : Parent(_root, cur);
    }

    BTNode<T>* LeftChild(BTNode<T>* cur) const{ // 返回某结点的左结点
        return (cur == NULL) ? NULL : cur->lc;
    }

    BTNode<T>* RightChild(BTNode<T>* cur) const{ // 返回某结点的右结点
        return(cur == NULL) ? NULL : cur->rc;
    }

    int Height(){ // 返回树的高度  // todo: 函数体
        return Height(_root);
    }






    

    int remove(BTNode<T>* p);

private:

    BTNode<T>* _root; // 根结点
    int _size;   // 树的规模

};

#include "BinTree.h"

#endif // __BINARY_TREE_H__
