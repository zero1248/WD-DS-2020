/*
*********************************************************************************************************
*
* file name:   linked_stack.h
* creator:     Isaac
* date:        20190905
* description: linked stack
*
*********************************************************************************************************
*/

#ifndef __LINKED_STACK_H__
#define __LINKED_STACK_H__

#include "linked_list_wd.h"

const int max_stack_length = 100;

typedef ElemType_LinkList ElemType_LStack;
//typedef char ElemType_LStack;
// typedef int ElemType_LStack;


extern void DestroyStack_LS(LinkList &);
extern bool StackEmpty_LS(LinkList &);
extern bool StackFull_LS(LinkList &);
extern bool StackPush_LS(LinkList &, ElemType_LStack);
extern bool StackPop_LS(LinkList &, ElemType_LStack &);
extern bool StackGetTop_LS(LinkList &, ElemType_LStack &);




#endif // __LINKED_STACK_H__
