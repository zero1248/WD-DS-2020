/*
*********************************************************************************************************
*
* file name:   sq_stack.h
* creator:     Isaac
* date:        20190413
* description: sequence stack
*
*********************************************************************************************************
*/
#ifndef __SQ_STACK_H__
#define __SQ_STACK_H__

const int stack_size = 100;

typedef char ElemType_SqStack;
//typedef int ElemType_SqStack;

typedef struct SqStack{

    ElemType_SqStack *data; //
    int top;   // ’ª∂•÷∏’Î

}SqStack;


extern void InitStack_Sq(SqStack &S);
extern void DestroyStack_Sq(SqStack &S);
extern bool StackEmpty_Sq(SqStack S);
extern bool StackFull_Sq(SqStack S);
extern bool StackPush_Sq(SqStack &S, ElemType_SqStack e);
extern bool StackPop_Sq(SqStack &S, ElemType_SqStack &e);
extern bool StackGetTop_Sq(SqStack S, ElemType_SqStack &e);





#endif // __SQ_STACK_H__
