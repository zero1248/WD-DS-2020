/*
*********************************************************************************************************
*
* file name:   sq_list.h
* creator:     Isaac
* date:        20190403
* description: sequence list
*
*********************************************************************************************************
*/
#ifndef __SQ_LIST_H__
#define __SQ_LIST_H__

#define LIST_INIT_SIZE  100  // initial assigned amount of linear list storage space
#define LIST_INCREMENT  10   // assigned increment of linear list storage space

//typedef char ElemType_SqList;
typedef int ElemType_SqList;


typedef struct{
	ElemType_SqList  *data;       //storage space base address
	int length;      //current length
	int listsize;    //current assigned storage capacity
}SqList;

extern bool InitList_Sq(SqList&);
extern bool DestroyList_Sq(SqList&);
extern bool ClearList_Sq(SqList&);
extern bool ListEmpty_Sq(SqList&);
extern int ListLength_Sq(SqList&);
extern bool GetElem_Sq(SqList&, int, ElemType_SqList&);
extern bool PriorElem_Sq(SqList&, ElemType_SqList, ElemType_SqList&);
extern bool NextElem_Sq(SqList&, ElemType_SqList, ElemType_SqList&);
extern bool ListInsert_Sq(SqList&, int, ElemType_SqList);
extern bool ListDelete_Sq(SqList&, int, ElemType_SqList&);


extern bool PrintList_Sq(SqList&);
extern bool Generate_Test_Set(SqList&, int);  // 生成 char 型测试集
extern bool Bubble_Sort(SqList&);
extern bool Binary_Search(SqList, ElemType_SqList, int&);
extern bool Generate_Test_Set(SqList&, int, int); // 生成 int 型测试集

#endif //__SQ_LIST_H__
