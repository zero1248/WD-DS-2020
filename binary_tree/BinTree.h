/*
*********************************************************************************************************
*
* file name:   BinTree.h
* creator:     Isaac
* date:        20190413
* description: binary tree
*
*********************************************************************************************************
*/

#ifndef __BINTREE_H__
#define __BINTREE_H__

#include <iostream>
#include "BinNode.h"


template<typename T> // 二叉树模板
class BinTree{

public:
    // 构造/析构
    BinTree(): _size(0), _root(NULL){}
    ~BinTree(){
       if(_size > 0){
            destroy(_root);
            // remove(_root);
       }
    }

    // 基本操作

    BTNode<T>* insertRoot(const T &e); // 树中插入根结点
    BTNode<T>* insertLC(BTNode<T>* p, const T &e); // e 作为 x 的左孩子插入
    BTNode<T>* insertRC(BTNode<T>* p, const T &e); // e 作为 x 的右孩子插入
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

    BTNode<T>* LeftChild(BTNode<T>* cur) const{ // 返回某结点的左孩子结点
        return (cur == NULL) ? NULL : cur->lc;
    }

    BTNode<T>* RightChild(BTNode<T>* cur) const{ // 返回某结点的右孩子结点
        return(cur == NULL) ? NULL : cur->rc;
    }

    int Height(){ // 返回树的高度（深度）
        return Height(_root);
    }


    BTNode<T>* Parent(BTNode<T>* somenode, BTNode<T>* cur);
    int Height(BTNode<T>* subTree);




    // 先序遍历
    void PreOrder(void(*visit)(BTNode<T>* p));
    // 中序遍历
    void InOrder(void(*visit)(BTNode<T>* p));
    // 后序遍历
    void PostOrder(void(*visit)(BTNode<T>* p));
    // 层次遍历
    void LevelOrder(void(*visit)(BTNode<T>* p));


    int remove(BTNode<T>* p);  // 删除二叉树中删除 p 结点及其后代
    void destroy(BTNode<T>* subTree); // 销毁结点，只能销毁结点，不能销毁数据域中开辟的内存

protected:

    BTNode<T>* _root; // 根结点
    int _size;   // 树的规模
    //int _height; // 树的高度

};

#include "BinTree_implementation.h"
#include "BinTree_remove.h"
#include "BinTree_traversal.h"

#endif // __BINTREE_H__
