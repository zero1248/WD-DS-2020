/*
*********************************************************************************************************
*
* file name:   sl_list.h
* creator:     Isaac
* date:        20190412
* description: singly link list
*
*********************************************************************************************************
*/
#ifndef __SL_LIST_H__
#define __SL_LIST_H__

#include <iostream>

using namespace std;


//typedef int ElemType_SlList;
typedef char ElemType_SlList;


class SLinkList{

public:

    // 构造/析构
    SLinkList();
    ~SLinkList();
    // 基本操作
    bool HeadInsert(const ElemType_SlList &e);  // 头插
    bool TailInsert(const ElemType_SlList &e);  // 尾插
    bool Insert(int i, const ElemType_SlList &e);  // 指定位置插入
    bool GetElem(int i, ElemType_SlList &e);
    bool LocateElem(int &i, ElemType_SlList e);
    bool DeleteNode(int i);
    int GetListLength();
    // 其他操作
    void PrintList();

private:

    struct SLNode{
        ElemType_SlList  data;
        struct SLNode  *next;
        SLNode(const ElemType_SlList &e): data(e),next(NULL){}
    };

    SLNode *head; //头指针
    SLNode *tail; //尾指针

    bool CreatList();
    void ClearList();
    bool GetNode(int i, SLNode* &p);
    SLNode* GetNode(int i);
    bool isEmpty();

};



#endif //__SL_LIST_H__
