/*
*********************************************************************************************************
*
* file name:   linked_stack.cpp
* creator:     Isaac
* date:        201909005
* description: linked stack
*
*********************************************************************************************************
*/

#include "linked_stack.h"
#include "linked_list_wd.h"

using namespace std;


void DestroyStack_LS(LinkList &S){

    S.Clear_List();
}


bool StackEmpty_LS(LinkList &S){

    if(S.is_Empty())
        return true;
    else
        return false;
}


bool StackFull_LS(LinkList &S){

    if(S.Get_List_Length() == max_stack_length)
        return true;
    else
        return false;
}


bool StackPush_LS(LinkList &S, ElemType_LStack e){

    if(StackFull_LS(S))
        return false;
    S.Head_Insert(e);
    return true;
}


bool StackPop_LS(LinkList &S, ElemType_LStack &e){

    if(StackEmpty_LS(S))
        return false;
    S.Get_Elem(1, e);
    S.Delete_Node(1);

    return true;
}


bool StackGetTop_LS(LinkList &S, ElemType_LStack &e){

    if(StackEmpty_LS(S))
       	return false;
    S.Get_Elem(1, e);

    return true;
}
