/*
*********************************************************************************************************
*
* file name:   BinTree_traversal.h
* creator:     Isaac
* date:        20190929
* description: binary tree traversal
*
*********************************************************************************************************
*/

#ifndef __BINTREE_TRAVERSAL_H__
#define __BINTREE_TRAVERSAL_H__


#include "BinNode.h"

// 先序遍历，递归版
template<typename T>
static void TravIn_R(BTNode<T>* p, void(*visit)(BTNode<T>* p)){

    if(!p)  // 返回条件
        return;
    TravIn_R(p->lc, visit);
    visit(p->data);
    TravIn_R(p->rc, visit);
}



// 先序遍历
template<typename T>
void BinTree<T>::PreOrder(void(*visit)(BTNode<T>* p)){

    TravIn_R(this, visit);


}




// 中序遍历
template<typename T>
void BinTree<T>::InOrder(void(*visit)(BTNode<T>* p)){



}




// 后序遍历
template<typename T>
void BinTree<T>::PostOrder(void(*visit)(BTNode<T>* p)){



}




// 层次遍历
template<typename T>
void BinTree<T>::LevelOrder(void(*visit)(BTNode<T>* p)){



}








#endif // __BINTREE_TRAVERSAL_H__


