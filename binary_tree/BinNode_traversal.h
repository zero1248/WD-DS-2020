/*
*********************************************************************************************************
*
* file name:   BinNode_traversal.h
* creator:     Isaac
* date:        20190929
* description: binary tree node traversal
*
*********************************************************************************************************
*/

#ifndef __BINNODE_TRAVERSAL_H__
#define __BINNODE_TRAVERSAL_H__


#include "BinNode.h"

// 先序遍历，递归版
template<typename T>
void TravPre_R(BTNode<T>* p, void(*visit)(BTNode<T>*)){

    if(!p)  // 返回条件
        return;
    visit(p); // 递归访问根结点
    TravPre_R(p->lc, visit); // 递归访问左子树
    TravPre_R(p->rc, visit); // 递归访问右子树
}

// 中序遍历，递归版
template<typename T>
void TravIn_R(BTNode<T>* p, void(*visit)(BTNode<T>*)){

    if(!p)  // 返回条件
        return;
    TravIn_R(p->lc, visit); // 递归访问左子树
    visit(p); // 递归访问根结点
    TravIn_R(p->rc, visit); // 递归访问右子树
}

// 后序遍历，递归版
template<typename T>
void TravPost_R(BTNode<T>* p, void(*visit)(BTNode<T>*)){

    if(!p)  // 返回条件
        return;
    TravPost_R(p->lc, visit); // 递归访问左子树
    TravPost_R(p->rc, visit); // 递归访问右子树
    visit(p); // 递归访问根结点
}

// 先序遍历
template<typename T>
void BTNode<T>::PreOrder(void(*visit)(BTNode<T>*)){

    TravPre_R(this, visit);


}




// 中序遍历
template<typename T>
void BTNode<T>::InOrder(void(*visit)(BTNode<T>*)){

    TravIn_R(this, visit);

}




// 后序遍历
template<typename T>
void BTNode<T>::PostOrder(void(*visit)(BTNode<T>*)){

    TravPost_R(this, visit);

}




// 层次遍历
template<typename T>
void BTNode<T>::LevelOrder(void(*visit)(BTNode<T>*)){

    TravLevel(this, visit);

}








#endif // __BINNODE_TRAVERSAL_H__


