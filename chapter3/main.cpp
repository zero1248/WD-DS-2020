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
#include <typeinfo>
#include <cstdio>

using namespace std;

int main(){

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
