/*
*********************************************************************************************************
*
* file name:   BinNode_implementation.cpp
* creator:     Isaac
* date:        20190929
* description: binary tree node member functioin
*
*********************************************************************************************************
*/

#ifndef __BINNODE_IMPLEMENTATION_H__
#define __BINNODE_IMPLEMENTATION_H__



// 将 e 作为当前结点的左孩子插入二叉树
template <typename T>
BTNode<T>* BTNode<T>::insertAsLC(T const &e){

    return lc = new BTNode (e, this);
}

// 将 e 作为当前结点的右孩子插入二叉树
template <typename T>
BTNode<T>* BTNode<T>::insertAsRC(T const &e){

    return rc = new BTNode (e, this);
}





#endif // __BINNODE_IMPLEMENTATION_H__
