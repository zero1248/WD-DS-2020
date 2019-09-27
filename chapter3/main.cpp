/*
*********************************************************************************************************
*
* file name:   main.cpp
* creator:     Isaac
* date:        20190413
* description: test the data sturcture module(chapter3)
*
*********************************************************************************************************
*/
#include <iostream>
#include <iomanip>
#include "sq_stack.h"
#include "sq_queue.h"
//#include "linked_list_wd.h"
#include "linked_stack.h"
#include <typeinfo>
#include <cstdio>

using namespace std;

// test sequence stack
//int main(){
//
//    SqStack S;
//    ElemType_SqStack x;
//    InitStack_Sq(S);
//
//    StackPush_Sq(S, '1');
//    StackPush_Sq(S, '2');
//    StackPush_Sq(S, '3');
//    StackPop_Sq(S, x);
//    cout << x << endl;
//    StackGetTop_Sq(S, x);
//    cout << x << endl;
//
//    DestroyStack_Sq(S);
//
//    return 0;
//}


//// test linked stack
//int main(){
//    LinkList S(has_headnode, singly);
//    ElemType_LStack x;
//
//
//    StackPush_LS(S, '1');
//    StackPush_LS(S, '2');
//    StackPush_LS(S, '3');
//
//    StackPop_LS(S, x);
//    cout << x << endl;
//    StackGetTop_LS(S, x);
//    cout << x << endl;
//    StackPop_LS(S, x);
//    cout << x << endl;
//    if(StackPop_LS(S, x))
//        cout << x << endl;
//    else
//        cout << "error" << endl;
//    if(StackPop_LS(S, x))
//        cout << x << endl;
//    else
//        cout << "error" << endl;
//
//    DestroyStack_LS(S);
//
//    return 0;
//}


// test sequence queue
int main(){

    SqQueue Q;
    ElemType_SqQueue x;
    InitQueue_Sq(Q);

    EnQueue_Sq(Q, 123);
    EnQueue_Sq(Q, 12);
    EnQueue_Sq(Q, 1);

//    DeQueue_Sq(Q, x);
//    cout << x << endl;
//    DeQueue_Sq(Q, x);
//    cout << x << endl;
//    DeQueue_Sq(Q, x);
//    cout << x << endl;

    GetFront_Sq(Q, x);
    cout << x << endl;
    GetRear_Sq(Q, x);
    cout << x << endl;

    DestroyQueue_Sq(Q);


    return 0;
}
