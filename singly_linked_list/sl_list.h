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

typedef char ElemType_LinkList;
//typedef int ElemType_SlList;

typedef enum{
    no_headnode = 0,
    has_headnode = 1
}HeadNode;

typedef enum{
    singly = 0,            // 单链表
    doubly = 1,            // 双链表
    singly_circular = 2,   // 循环单链表
    doubly_circular = 3   // 循环双链表
}ListType;


class LinkList{

public:

    // 构造/析构
    LinkList(HeadNode head, ListType listtype);
    ~LinkList();
    // 基本操作
    bool HeadInsert(const ElemType_LinkList &e);  // 头插
    bool TailInsert(const ElemType_LinkList &e);  // 尾插
    bool Insert(int i, const ElemType_LinkList &e);  // 指定位置插入
    bool GetElem(int i, ElemType_LinkList &e);  // 按序号查找结点值
    bool LocateElem(int &i, ElemType_LinkList e);  // 按值查找表结点
    bool DeleteNode(int i);        // 按序号删除结点
    int GetListLength();           // 获取表长
    void ClearList();  // 删除除头结点外的所有结点
    // 其他操作
    void PrintList();  // 打印整个链表
    bool Generate_Test_Set(int line);   // 生成 char 型测试数据的链表
    bool Generate_Test_Set(int s, int e);  // 生成 int 型测试数据的链表

private:



    struct LNode{
        ElemType_LinkList  data;
        struct LNode  *prior;
        struct LNode  *next;
        LNode(const ElemType_LinkList &e): data(e), prior(NULL), next(NULL){}
    };

    HeadNode _has_HeadNode = has_headnode; // 默认使用头结点
    ListType _list_type = singly;          // 默认普通单链表
    LNode *_head; //头指针
    LNode *_tail; //尾指针

    bool CreatList();
    bool CreatList(HeadNode head = has_headnode, ListType listtype = singly);


    void DestroyList();
    bool GetNode(int i, LNode* &p); // 获取指定位置结点（1）
    LNode* GetNode(int i);          // 获取指定位置结点（2）
    bool isEmpty();

};




#endif //__SL_LIST_H__
