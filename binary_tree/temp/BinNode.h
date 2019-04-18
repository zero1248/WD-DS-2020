///*
//*********************************************************************************************************
//*
//* file name:   BinNode.h
//* creator:     Isaac
//* date:        20190413
//* description: binary tree node（清华邓俊辉老师教材结点定义）
//*
//*********************************************************************************************************
//*/
//
//#ifndef __BINNODE_H__
//#define __BINNODE_H__
//
//typedef enum{
//    RB_RED,
//    RB_BLACK
//}RBColor;  // 红黑树结点颜色
//
//template<typename T> struct BinNode{
//
//    T data; // 数据
//    BinNode<T> *parent; // 父结点
//    BinNode<T> *lc, *rc; // 左右孩子结点
//    int height; // 高度
//    int npl;    // 左式堆
//    RBColor color; // 颜色（红黑树）
//
//    // 构造函数
//    BinNode():
//        parent(NULL), lc(NULL), rc(NULL), height(0), npl(1), color(RB_RED){}
//    BinNode(T e, BinNode<T>* p=NULL, BinNode<T>* l=NULL, BinNode<T>* r=NULL, int h=0, int l=1, RBColor c=RB_RED):
//        data(e), parent(p), lc(l), rc(r), height(h), npl(l), color(c){}
//
//    // 接口函数
//    int size();
//    BinNode<T>* insertAsLC(const T&);
//    BinNode<T>* insertAsRC(const T&);
//    BinNode<T>* succ();
//    //未完待续
//
//};
//
//
//
//#endif // __BINNODE_H__
