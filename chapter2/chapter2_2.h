/*
*********************************************************************************************************
*
* file name:   chapter.h
* creator:     Isaac
* date:        20190403
* description: ������ ���ݽṹ��2.2
*
*********************************************************************************************************
*/

#ifndef __CHAPTER2_2_H__
#define __CHAPTER2_2_H__
#include "sq_list.h"

extern bool Del_Min(SqList&, ElemType_SqList&);
extern bool Reverse(SqList&); //���鷭ת
extern bool Delete_x(SqList&, ElemType_SqList);
extern bool Delete_s_t1(SqList&, ElemType_SqList, ElemType_SqList);
extern bool Delete_s_t2(SqList&, ElemType_SqList, ElemType_SqList);
extern bool Delete_Same(SqList&);
extern bool Merge(SqList, SqList, SqList&);
extern bool Add(SqList&, SqList); //�� B �ӵ� A ֮��
extern bool Reverse(SqList&, int, int);  //���ַ�ת
extern bool Exchange_m_n(SqList&, int, int);
extern bool SearchExchangeInsert(SqList&, ElemType_SqList);
extern bool Shifting(SqList&, int);
extern ElemType_SqList M_Search(SqList, SqList);
extern ElemType_SqList Majority(SqList L);
extern int Find_Miss_Min(SqList&);




#endif // __CHAPTER2_2_H__
