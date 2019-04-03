#ifndef __SL_LIST_H__
#define __SL_LIST_H__


typedef char ElemType_SLlist;

typedef struct LNode{
    ElemType_SLlist  data;
    struct LNode  *next;
}LNode, *SLinklist;

bool InitList_SL(SLinklist*);
bool CreatList_SL(SLinklist, ElemType_SLlist);
bool DestroyList_SL(SLinklist);
bool ClearList_SL(SLinklist);
bool ListEmpty_SL(SLinklist);
int ListLength_SL(SLinklist);
bool GetElem_SL(SLinklist, int, ElemType_SLlist*);
bool PriorElem_SL(SLinklist, ElemType_SLlist, ElemType_SLlist*);
bool NextElem_SL(SLinklist, ElemType_SLlist, ElemType_SLlist*);
bool ListInsert_SL(SLinklist, int, ElemType_SLlist);
bool ListDelete_SL(SLinklist, int, ElemType_SLlist*);
bool PrintList_SL(SLinklist);

#endif //__SL_LIST_H__
