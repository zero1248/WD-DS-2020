/*
*********************************************************************************************************
*
* file name:   sq_stack.cpp
* creator:     Isaac
* date:        20190413
* description: sequence stack
*
*********************************************************************************************************
*/

#include "sq_stack.h"


bool InitStack_Sq(SqStack &S){

    S.data = new ElemType_SqStack[stack_size];
    S.top = -1;

    return true;
}

bool DestroyStack_Sq(SqStack &S){

    delete[] S.data;
    S.top = -1;
    return true;
}

bool StackEmpty_Sq(SqStack S){

    if(S.top == -1)
        return true;
    else
        return false;
}

bool StackFull_Sq(SqStack S){
    if(S.top == stack_size-1)
        return true;
    else
        return false;
}

bool StackPush_Sq(SqStack &S, ElemType_SqStack e){

    if(!StackFull_Sq(S)){
        S.data[++S.top] = e;
        return true;
    }
    else
        return false;
}

bool StackPop_Sq(SqStack &S, ElemType_SqStack &e){

    if(!StackEmpty_Sq(S)){
        e = S.data[S.top--];
        return true;
    }
    else
        return false;
}

bool StackGetTop_Sq(SqStack S, ElemType_SqStack &e){

    if(!StackEmpty_Sq(S)){
        e = S.data[S.top];
        return true;
    }
    else
        return false;
}




