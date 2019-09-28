/*
*********************************************************************************************************
*
* file name:   BinTree_implementation.cpp
* creator:     Isaac
* date:        20190413
* description: binary tree member functioin
*
*********************************************************************************************************
*/

#ifndef __BINTREE_IMPLEMENTATION_H__
#define __BINTREE_IMPLEMENTATION_H__

#include "BinNode.h"


/**********************************************************************/
/*
 * 将 e 作为根结点插入树（前提是空树）
 * Parameters: 数据域内容
 * Returns: 根结点指针
 */
/**********************************************************************/
template<typename T>
BTNode<T>* BinTree<T>::insertRoot(const T &e){

    if(_root == NULL && _size == 0){
        _root = new BTNode<T>(e);
        _size = 1;
    }
    else
        return NULL;

    return _root;
}

/**********************************************************************/
/*
 * 将 e 作为左孩子结点插入树（前提是没有左孩子）
 * Parameters: 数据域内容
 * Returns: 左孩子的指针
 */
/**********************************************************************/
template<typename T>
BTNode<T>* BinTree<T>::insertLC(BTNode<T>* p, const T &e){

    if(p->lc == NULL){
        p -> insertAsLC(e);
        _size++;
    }
    else{
        return NULL;
    }
    return p -> lc;
}

/**********************************************************************/
/*
 * 将 e 作为右孩子结点插入树（前提是没有右孩子）
 * Parameters: 数据域内容
 * Returns: 右孩子的指针
 */
/**********************************************************************/
template<typename T>
BTNode<T>* BinTree<T>::insertRC(BTNode<T>* p, const T &e){

    if(p->rc == NULL){
        p -> insertAsRC(e);
        _size++;
    }
    else{
        return NULL;
    }
    return p -> rc;
}



// template<typename T>
// BTNode<T>* BinTree<T>::AttachLC(BTNode<T>* p, BinTree<T>* &T){


// }


// template<typename T>
// BTNode<T>* BinTree<T>::AttachRC(BTNode<T>* p, BinTree<T>* &T){


// }


//返回父节点，从结点 somenode 开始，搜索 cur 结点的父结点
template<typename T>
BTNode<T>* BinTree<T>::Parent(BTNode<T>* somenode, BTNode<T>* cur){

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

// 获取以某一结点为根结点的子树的高度（深度）
template<typename T>
int BinTree<T>::Height(BTNode<T>* subTree){

    if(subTree == NULL){  // 返回条件
        return 0;
    }
    else{
        int leftHieght = Height(subTree -> lc); // 递归访问左子树
        int rightHeight = Height(subTree -> rd); // 递归访问右子树
        return (leftHieght > rightHeight) ? leftHieght+1: rightHeight+1;
    }
}

// 销毁结点，只能销毁结点
// 数据域是指针的情况不适用
template<typename T>
void BinTree<T>::destroy(BTNode<T>* subTree){

    if(subTree != NULL){
        destroy(subTree -> lc);
        destroy(subTree -> rc);
        delete subTree;
    }
}





//void call(){
//    BinTree<int> Tree;
//    Tree.InsertRoot(123);
//
//}



#endif //__BINTREE_IMPLEMENTATION_H__
