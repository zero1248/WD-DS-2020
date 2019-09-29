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

#define IsRoot(x) ( ! ( (x).parent ) )
#define IsLChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->lc ) )
#define IsRChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->rc ) )

// 将 e 作为当前结点的左孩子插入二叉树
template <typename T>
BTNode<T>* BTNode<T>::insertAsLC(T const &e){

    return lc = new BTNode (e, this); // 同时作为父结点被新结点指向
}

// 将 e 作为当前结点的右孩子插入二叉树
template <typename T>
BTNode<T>* BTNode<T>::insertAsRC(T const &e){

    return rc = new BTNode (e, this); // 同时作为父结点被新结点指向
}

// 取当前结点的（中序）直接后继
template <typename T>
BTNode<T>* BTNode<T>::succ(){

    BTNode<T>* p = this; // 记录后继的临时变量
    if(rc){ // 若有右孩子，则直接后继必在右子树中
        p = rc;
        while(p->lc)
            p = p -> lc; // 且位于右子树中最左结点
    }
    else{ // 否则，直接后继是“将当前节点包含于其左子树中的最低祖先”
        while( (p->parent) && (p->parent->rc == p) ) // p 是右孩子时
            p = p -> parent; // 逆向地沿右向分支，不断朝左上方移动
        p = p -> parent; // 最后再朝右上方移动一步，即抵达直接后继（如果存在）
    }
    return p;
}




#endif // __BINNODE_IMPLEMENTATION_H__
