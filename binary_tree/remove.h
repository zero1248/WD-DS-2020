/*
*********************************************************************************************************
*
* file name:   remove.h
* creator:     Isaac
* date:        20190928
* description: 二叉树析构，实现了对二叉树结点的数据域是指针的情况的析构（本文件内代码参考自邓俊辉老师《数据结构（C++版）》示例代码）
* 
*********************************************************************************************************
*/


#ifndef __REMOVE_H__
#define __REMOVE_H__



/**********************************************************************/
/*
 * 删除二叉树中删除 p 结点及其后代
 * Parameters: 删除结点的位置
 * Returns: 被删除结点的数量
 */
/**********************************************************************/
template <typename T>
int BinTree<T>::remove(BTNode<T>* x){

    // todo: FromParentTo ( *x ) = NULL; //切断来自父节点的指针
    // todo: updateHeightAbove ( x->parent ); //更新祖先高度
    int n = removeAt ( x ); //删除子树x
    _size -= n; // 更新规模
    return n; // 返回删除节点总数
    
}

/**********************************************************************/
/*
 * 删除二叉树中 p 结点及其后代
 * Parameters: 删除结点的位置
 * Returns: 返回被删除节点的数值
 */
/**********************************************************************/
template <typename T>
static int removeAt(BTNode<T>* x){
    if ( !x ) return 0; // 递归基：空树
    int n = 1 + removeAt ( x->lc ) + removeAt ( x->rc ); // 递归释放左、右子树
    // 释放被摘除节点，并返回删除节点总数
    release ( x->data );   // ! 数据域也有可能是开辟了内存的指针，因此需要先释放，如果 x->data 是普通变量，就什么都不做即可
    release ( x ); 
    return n; 
    // 
    
}

template <typename T> 
void release ( T x ) { 
    Cleaner<T>::clean ( x ); 
}

// Cleaner 类，对于普通变量什么也不做
template <typename T> struct Cleaner {
   static void clean ( T x ) { //相当于递归基
   }
};

// Cleaner 类，对于指针类型，递归释放
template <typename T> struct Cleaner<T*> {
   static void clean ( T* x ) {
      if ( x ) { delete x; } //如果其中包含指针，递归释放
   }
};


#endif __REMOVE_H__
