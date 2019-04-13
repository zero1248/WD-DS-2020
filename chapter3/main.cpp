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
#include "sq_stack.h"

using namespace std;

int main(){

    SqStack S;
    ElemType_SqStack x;
    InitStack_Sq(S);

    StackPush_Sq(S, '1');
    StackPush_Sq(S, '2');
    StackPush_Sq(S, '3');
    StackPop_Sq(S, x);
    cout << x << endl;
    StackGetTop_Sq(S, x);
    cout << x << endl;




    DestroyStack_Sq(S);



    return 0;
}
