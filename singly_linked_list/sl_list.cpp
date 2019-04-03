#include <cstdio>
#include <cstdlib>
#include "sl_list.h"


///**************************singly linked list******************************/
//
//    SLinklist list_test;
//
//    InitList_SL(&list_test);
//    CreatList_SL(list_test, '1');
//    CreatList_SL(list_test, '2');
//    CreatList_SL(list_test, '3');
//    CreatList_SL(list_test, '4');
//    CreatList_SL(list_test, '5');
//    PrintList_SL(list_test);
//
///**************************singly linked list******************************/



//Only initialization need to pass pointer of pointer

/**********************************************************************/
/*
 * creat a head node of singly linked list
 * Parameters: a pointer of singly linked list
 * Returns: status
 */
/**********************************************************************/
bool InitList_SL(SLinklist* L){

	(*L) = (SLinklist)malloc(sizeof(LNode));
	(*L)->next = NULL;

	return true;
}

/**********************************************************************/
/*
 * creat a new node of singly linked list in turn
 * Parameters: an exist singly linked list
 * Returns: status
 */
/**********************************************************************/
bool CreatList_SL(SLinklist L, ElemType_SLlist e){

    SLinklist p;

    p = (SLinklist)malloc(sizeof(LNode));
    p->data = e;
    p->next = L->next;
    L->next = p;

    return true;
}

bool DestroyList_SL(SLinklist L){

    return true;
}

bool ClearList_SL(SLinklist L){

    return true;
}

bool ListEmpty_SL(SLinklist L){

    return true;
}

int ListLength_SL(SLinklist L){
    return true;
}

bool GetElem_SL(SLinklist L, int i, ElemType_SLlist* e){
    return true;
}

bool PriorElem_SL(SLinklist L, ElemType_SLlist cur_e, ElemType_SLlist* pre_e){
    return true;
}

bool NextElem_SL(SLinklist L, ElemType_SLlist cur_e, ElemType_SLlist* next_e){
    return true;
}

bool ListInsert_SL(SLinklist L, int i, ElemType_SLlist e){

    int j = 0;

    for(j=0; j<i; j++){


    }
    return true;
}

bool ListDelete_SL(SLinklist L, int i, ElemType_SLlist* e){
    return true;
}

/**********************************************************************/
/*
 * print a singly linked list
 * Parameters: an exist squence linear list
 * Returns: status
 */
/**********************************************************************/
bool PrintList_SL(SLinklist L){
    SLinklist p = L->next;
    while(p ){

        printf("%c",p->data);
        p = p->next;
    }

    return true;
}
