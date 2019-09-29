/*
*********************************************************************************************************
*
* file name:   BinNode_traversal.h
* creator:     Isaac
* date:        20190929
* description: binary tree node traversal
* 参考邓俊辉老师代码
*********************************************************************************************************
*/

#ifndef __BINNODE_TRAVERSAL_H__
#define __BINNODE_TRAVERSAL_H__


#include "BinNode.h"
#include <stack>
#include <queue>

using namespace std;


//从当前结点出发，沿左子树不断深入，直至没有左子树的结点；沿途结点遇到后立即访问
template<typename T>
static void visitAlongLeftBranch(BTNode<T>* p, void(*visit)(BTNode<T>*), stack<BTNode<T>*> &S){

    while(p){
        visit(p); // 访问当前结点
        if(p -> rc) // 遇到右孩子就压栈
            S.push(p -> rc);
        p = p -> lc; // 持续访问左分支直至为空
    }

}


//从当前结点出发，沿左子树不断深入，将遇到的结点都压入栈中，直至没有左子树的结点
template <typename T>
static void goAlongLeftBranch(BTNode<T>* p, stack<BTNode<T>*> &S) {
    while(p){
       S.push(p);
       p = p->lc;
    } //当前节点入栈后随即向左侧分支深入，迭代直到无左孩子
}


//在以 S 栈顶结点为根的子树中，找到最高左侧可见叶结点
template <typename T>
static void gotoHLVFL ( stack<BTNode<T>*> &S ) { //沿途所遇结点依次入栈

   while ( BTNode<T>* p = S.top() ) //自顶而下，反复检查当前结点（即栈顶）
      if ( p -> lc ) { //尽可能向左
         if ( p -> rc ) S.push ( p->rc ); //若有右孩子，优先入栈
         S.push ( p->lc ); //然后才转至左孩子
      }
      else //实不得已
         S.push ( p->rc ); //才向右
   S.pop(); //返回之前，弹出栈顶的空结点
}


// 先序遍历，递归版
template<typename T>
static void TravPre_R(BTNode<T>* p, void(*visit)(BTNode<T>*)){

    if(!p)  // 返回条件
        return;
    visit(p); // 递归访问根结点
    TravPre_R(p->lc, visit); // 递归访问左子树
    TravPre_R(p->rc, visit); // 递归访问右子树
}


// 先序遍历，迭代版（方法一），使用栈
template<typename T>
static void TravPre_I1(BTNode<T>* p, void(*visit)(BTNode<T>*)){

    stack<BTNode<T>*> S; // 使用 C++ STL 中的 stack
    if(p)  // 返回条件
        S.push(p); // 根结点压栈
    while(!S.empty()){
        p = S.top();
        S.pop();
        visit(p);
        if(p -> rc) // 右孩子（如果有）先入栈
            S.push(p -> rc);
        if(p -> lc) // 左孩子（如果有）后入栈
            S.push(p -> lc);
    }
}


// 先序遍历，迭代版（方法二），使用栈
template<typename T>
static void TravPre_I2(BTNode<T>* p, void(*visit)(BTNode<T>*)){

    stack<BTNode<T>*> S; // 使用 C++ STL 中的 stack
    if(p)  // 返回条件
        S.push(p); // 根结点压栈
    while(1){
        visitAlongLeftBranch(p, visit, S);
        if( S.empty()) // 栈空则遍历完成
            break;
        p = S.top(); // 出栈下一批结点
        S.pop();
    }
}


// 中序遍历，递归版
template<typename T>
static void TravIn_R(BTNode<T>* p, void(*visit)(BTNode<T>*)){

    if(!p)  // 返回条件
        return;
    TravIn_R(p->lc, visit); // 递归访问左子树
    visit(p); // 递归访问根结点
    TravIn_R(p->rc, visit); // 递归访问右子树
}


// 中序遍历，迭代版（方法一），使用栈
template<typename T>
static void TravIn_I1(BTNode<T>* p, void(*visit)(BTNode<T>*)){

    stack<BTNode<T>*> S; // 使用 C++ STL 中的 stack
    while(1){
        goAlongLeftBranch(p, S); // 从当前结点出发，沿左子树逐批入栈
        if(S.empty()) // 栈空则遍历完成
            break;
        p = S.top(); // 出栈一个结点
        S.pop();
        visit(p); // 访问出栈结点
        p = p->rc; // 转向出栈结点的右子树
    }
}


// 中序遍历，迭代版（方法二），使用栈
template<typename T>
static void TravIn_I2(BTNode<T>* p, void(*visit)(BTNode<T>*)){

    stack<BTNode<T>*> S; // 使用 C++ STL 中的 stack
    while(1){
        if(p){
            S.push(p); // 根结点入栈
            p = p -> lc; // 深入遍历左子树
        }
        else if(!S.empty()){ // 尚未访问的最低祖先结点出栈
            p = S.top();  // 访问该祖先结点
            S.pop();
            visit(p);
            p = p -> rc; // 遍历其右子树
        }
        else{
            break; // 遍历完成
        }
    }
}


// 中序遍历，迭代版（方法三），使用栈，回溯法，需要用到父结点（相当于使用了三叉链表）
template<typename T>
static void TravIn_I3(BTNode<T>* p, void(*visit)(BTNode<T>*)){

    bool backtrack = false;
    while(1){
        if(!backtrack && p->lc) // 若有左子树且不是刚刚回溯
            p = p -> lc;  // 深入遍历左子树
        else{ // 否则，无左子树或刚刚回溯（相当于无左子树）
            visit(p); // 访问该结点
            if(p -> rc){ // 若其右子树非空
                p = p -> rc; // 深入右子树继续遍历
                backtrack = false; // 关闭回溯标志
            }
            else{ // 若其右子树为空
                if( !( p = p->succ() ) ) // 回溯（含抵达末结点时的退出返回）
                    break;
                backtrack = true; // 设置回溯标志
            }
        }
    }
}


// 中序遍历，迭代版（方法四），需要用到父结点（相当于使用了三叉链表）
template<typename T>
static void TravIn_I4(BTNode<T>* p, void(*visit)(BTNode<T>*)){

    while(1){
        if(p -> lc) // 若有左子树
            p = p -> lc; // 深入遍历左子树
        else{ // 否则
            visit(p); // 访问当前结点，同时
            while( !(p->rc) ){ // 不断在无右分支处
                if( !(p = p->succ()) )  // 回溯至直接后继（在没有后继的末结点处，直接退出）
                    return;
                else{ // 访问新的当前结点
                    visit(p); // （直至有右分支处）转向非空的右子树
                }
            }
            p = p -> rc;
        }
    }
}


// 后序遍历，递归版
template<typename T>
static void TravPost_R(BTNode<T>* p, void(*visit)(BTNode<T>*)){

    if(!p)  // 返回条件
        return;
    TravPost_R(p->lc, visit); // 递归访问左子树
    TravPost_R(p->rc, visit); // 递归访问右子树
    visit(p); // 递归访问根结点
}


// 后序遍历，迭代版，需要借助栈
template<typename T>
static void TravPost_I(BTNode<T>* p, void(*visit)(BTNode<T>*)){

    stack<BTNode<T>*> S; // 使用 C++ STL 中的 stack
    if(p) // 根结点入栈
        S.push(p);
    while(!S.empty()){
        if(S.top() != p->parent) // 若栈顶非当前结点之父（则必为其右兄），此时
            gotoHLVFL(S); // 在以其右兄为根之树中，找到 HLVFL（相当于递归深入其中）
        p = S.top(); // 弹出并访问栈顶（即前一结点之后继）
        S.pop();
        visit(p);
    }
}


// 层次遍历，借助队列
template<typename T>
static void TravLevel(BTNode<T>* p, void(*visit)(BTNode<T>*)){

    queue<BTNode<T>*> Q;  // 使用 C++ STL 中的 queue
    Q.push(p);  // 根结点入队
    while(!Q.empty()){ // 反复迭代，直到队列变空
        p = Q.front(); // 取出队首结点
        Q.pop();
        visit(p); // 访问取出的结点
        if(p -> lc) // 有左孩子就入队
            Q.push(p -> lc);
        if(p -> rc) // 有右孩子就入队
            Q.push(p -> rc);
    }
}



// 先序遍历
template<typename T>
void BTNode<T>::PreOrder(void(*visit)(BTNode<T>*)){

    // TravPre_R(this, visit); // 递归版本
    TravPre_I1(this, visit);   // 迭代版本 1
    // TravPre_I2(this, visit); // 迭代版本 2
}


// 中序遍历
template<typename T>
void BTNode<T>::InOrder(void(*visit)(BTNode<T>*)){

    // TravIn_R(this, visit); // 递归版本
    // TravIn_I1(this, visit); // 迭代版本 1
    // TravIn_I2(this, visit); // 迭代版本 2
    // TravIn_I3(this, visit); // 迭代版本 3
    TravIn_I4(this, visit); // 迭代版本 4
}



// 后序遍历
template<typename T>
void BTNode<T>::PostOrder(void(*visit)(BTNode<T>*)){

    // TravPost_R(this, visit); // 递归版本
    TravPost_I(this, visit); // 迭代版本
}




// 层次遍历
template<typename T>
void BTNode<T>::LevelOrder(void(*visit)(BTNode<T>*)){

    TravLevel(this, visit);
}








#endif // __BINNODE_TRAVERSAL_H__


