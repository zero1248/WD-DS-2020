/*
*********************************************************************************************************
*
* file name:   sq_list.h
* creator:     Isaac
* date:        20190403
* description: head file of sqlist.cpp
*
*********************************************************************************************************
*/
#ifndef __SQ_LIST_H__
#define __SQ_LIST_H__

#define LIST_INIT_SIZE  100  // initial assigned amount of linear list storage space
#define LIST_INCREMENT  10   // assigned increment of linear list storage space

typedef char ElemType_SqLlist;

typedef struct{
	ElemType_SqLlist  *data;       //storage space base address
	int length;      //current length
	int listsize;    //current assigned storage capacity
}SqList;

bool InitList_Sq(SqList&);
bool DestroyList_Sq(SqList&);
bool ClearList_Sq(SqList&);
bool ListEmpty_Sq(SqList&);
int ListLength_Sq(SqList&);
bool GetElem_Sq(SqList&, int, ElemType_SqLlist&);
bool PriorElem_Sq(SqList&, ElemType_SqLlist, ElemType_SqLlist&);
bool NextElem_Sq(SqList&, ElemType_SqLlist, ElemType_SqLlist&);
bool ListInsert_Sq(SqList&, int, ElemType_SqLlist);
bool ListDelete_Sq(SqList&, int, ElemType_SqLlist&);
bool PrintList_Sq(SqList&);


#endif //__SQ_LIST_H__
