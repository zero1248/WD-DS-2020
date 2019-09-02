/*
*********************************************************************************************************
*
* file name:   chapter2_3_wd.h
* creator:     Isaac
* date:        20190418
* description: 《王道 数据结构》2.3
*
*********************************************************************************************************
*/
#ifndef __CHAPTER2_3_WD_H__
#define __CHAPTER2_3_WD_H__

#include "linked_list_wd.h"

extern void Delete_x(LinkList::LNode* &p, ElemType_LinkList x);
extern void Delete_x2(LinkList::LNode* &p, ElemType_LinkList x);
extern void Delete_x3(LinkList::LNode* &p, ElemType_LinkList x);
extern void Reverse_Print(LinkList::LNode* &p);
extern bool Delete_Min(LinkList::LNode* &p);
extern bool Reverse_List(LinkList::LNode* &p);
extern bool Reverse_List2(LinkList::LNode* &p);
extern bool Reverse_List3(LinkList::LNode* &p);
extern void Sort(LinkList &L);
extern void RangeDelete(LinkList::LNode* p, ElemType_LinkList min, ElemType_LinkList max);

#endif // __CHAPTER2_3_WD_H__
