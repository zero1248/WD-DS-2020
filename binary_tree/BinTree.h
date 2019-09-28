/*
*********************************************************************************************************
*
* file name:   BinTree.cpp
* creator:     Isaac
* date:        20190413
* description: binary tree member functioin
*
*********************************************************************************************************
*/

/**********************************************************************/
/*
 * insert a root node into the binary tree
 * Parameters: init_data
 * Returns: _root
 */
/**********************************************************************/
template<typename T>  
BTNode<T> *BinTree<T>::InsertRoot(const T &e){

    _root = new BTNode<T>(e);
    _size = 1;

    return _root;
}


template<typename T> 
BTNode<T>* BinTree<T>::InsertLC(BTNode<T>* p, const T &e){

    p -> lc = new BTNode<T>(e, this);
    _size++;

    return p -> lc;
}


template<typename T>
BTNode<T>* BinTree<T>::InsertRC(BTNode<T>* p, const T &e){

    p -> rc = new BTNode<T>(e, this);
    _size++;

    return p -> rc;
}


// template<typename T>
// BTNode<T>* BinTree<T>::AttachLC(BTNode<T>* p, BinTree<T>* &T){


// }


// template<typename T>
// BTNode<T>* BinTree<T>::AttachRC(BTNode<T>* p, BinTree<T>* &T){


// }


template<typename T>  //删除 p 节点及其后代，返回被删除节点的数值
int BinTree<T>::remove(BTNode<T>* p){

    return 0;
}


//void call(){
//    BinTree<int> Tree;
//    Tree.InsertRoot(123);
//
//}

