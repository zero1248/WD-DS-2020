/*
*********************************************************************************************************
*
* file name:   linked_list_wd.h
* creator:     Isaac
* date:        20190418
* description: 按照《王道》的方式实现链表（使用类，但是链表结点为 public 属性）
*
*********************************************************************************************************
*/
#ifndef __LINKED_LIST_WD_H__
#define __LINKED_LIST_WD_H__

#include <iostream>

using namespace std;

typedef char ElemType_LinkList;
//typedef int ElemType_LinkList;

typedef enum{
    no_headnode = 0,
    has_headnode = 1
}HeadNode;

typedef enum{
    singly = 0,            // 单链表
    doubly = 1,            // 双链表
    singly_circular = 2,   // 循环单链表
    doubly_circular = 3    // 循环双链表
}ListType;

class LinkList{

public:

	struct LNode {// 链表结点定义
        ElemType_LinkList  data;
        struct LNode  *prior;
        struct LNode  *next;
        LNode(const ElemType_LinkList &e): data(e), prior(NULL), next(NULL){}
    };

    LNode *_head; //头指针
    LNode *_tail; //尾指针

    // 构造/析构
    LinkList(HeadNode head, ListType listtype);
    ~LinkList();
    // 基本操作
    bool Head_Insert(const ElemType_LinkList &e);  // 头插
    bool Tail_Insert(const ElemType_LinkList &e);  // 尾插
    bool Insert(int i, const ElemType_LinkList &e);  // 指定位置插入
    bool Get_Elem(int i, ElemType_LinkList &e);  // 按序号查找结点值
    bool Locate_Elem(int &i, ElemType_LinkList e);  // 按值查找表结点
    bool Delete_Node(int i);        // 按序号删除结点
    int Get_List_Length();           // 获取表长
    void Clear_List();  // 删除除头结点外的所有结点
    // 其他操作
    void Print_List();  // 打印整个链表
    bool Generate_Test_Set(int line);   // 生成 char 型测试数据的链表
    bool Generate_Test_Set(int s, int e);  // 生成 int 型测试数据的链表
    void Bubble_Sort();
    void Selection_Sort();
    void Insertion_Sort();


private:

    HeadNode _has_HeadNode = has_headnode; // 默认使用头结点
    ListType _list_type = singly;          // 默认单向非循环链表

    bool Creat_List(HeadNode head = has_headnode, ListType listtype = singly); // 构造
    void Destroy_List();  // 析构
    bool Get_Node(int i, LNode* &p); // 获取指定位置结点（1）
    LNode* Get_Node(int i);          // 获取指定位置结点（2）
    bool is_Empty();

}; // class LinkList




#endif //__LINKED_LIST_WD_H__
