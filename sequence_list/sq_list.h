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

// ��ʱû��д��̬���������ĺ�����ֱ�ӿ������ڴ沢�������ݣ�Ȼ����վ��ڴ漴��

extern bool InitList_Sq(SqList&);  // ��ʼ��һ��˳���
extern bool DestroyList_Sq(SqList&);  // ����һ��˳��������ڴ�ռ䣩
extern bool ClearList_Sq(SqList&);  // ���һ��˳���
extern bool ListEmpty_Sq(SqList&);  // ˳����п�
extern int ListLength_Sq(SqList&);  // ��ȡ��
extern bool GetElem_Sq(SqList&, int, ElemType_SqList&); // ��ȡָ��λ��Ԫ��
extern int LocateElem_Sq(SqList &, ElemType_SqList); // ��λĳԪ���״γ��ֵ�λ��
extern bool PriorElem_Sq(SqList&, ElemType_SqList, ElemType_SqList&);  // ��ȡָ��Ԫ�ص�ǰһ��Ԫ��
extern bool NextElem_Sq(SqList&, ElemType_SqList, ElemType_SqList&);   // ��ȡָ��Ԫ�صĺ�һ��Ԫ��
extern bool ListInsert_Sq(SqList&, int, ElemType_SqList);  // ��ָ��λ�ò���Ԫ��
extern bool ListDelete_Sq(SqList&, int, ElemType_SqList&); // ɾ��ָ��λ��Ԫ��

// ��������
extern bool PrintList_Sq(SqList&);  // ��ӡ����˳���
extern bool Generate_Test_Set(SqList&, int);  // ���� char �Ͳ��Լ�
extern bool Bubble_Sort(SqList&);  // ð������
extern bool Binary_Search(SqList, ElemType_SqList, int&);  // ���ֲ���
extern bool Generate_Test_Set(SqList&, int, int); // ���� int �Ͳ��Լ�

#endif //__SQ_LIST_H__
