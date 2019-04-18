/*
*********************************************************************************************************
*
* file name:   binary_tree.cpp
* creator:     Isaac
* date:        20190413
* description: binary tree
*
*********************************************************************************************************
*/

export template<typename T>
BTNode<T> *BinTree<T>::InsertRoot(const T &e){

    _root = new BTNode<T>(e);
    _size = 1;

    return _root;
}


template<typename T>
BTNodePos BinTree<T>::InsertLC(BTNodePos p, const T &e){

    p -> lc = new BTNode<T>(e, this);
    _size++;

    return p -> lc;
}


template<typename T>
BTNodePos BinTree<T>::InsertRC(BTNodePos p, const T &e){

    p -> rc = new BTNode<T>(e, this);
    _size++;

    return p -> rc;
}

//
//template<typename T>
//BTNodePos BinTree<T>::AttachLC(BTNodePos p, BinTree<T>* &T){
//
//
//}
//
//
//template<typename T>
//BTNodePos BinTree<T>::AttachRC(BTNodePos p, BinTree<T>* &T){
//
//
//}



template<typename T>
int BinTree<T>::remove(BTNodePos p){

    return 0;
}

//void call(){
//    BinTree<int> Tree;
//    Tree.InsertRoot(123);
//
//}


