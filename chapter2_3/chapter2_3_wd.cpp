/*
*********************************************************************************************************
*
* file name:   chapter2_3_wd.cpp
* creator:     Isaac
* date:        20190418
* description: 《王道 数据结构》2.3
*
*********************************************************************************************************
*/
#include <iostream>
#include "chapter2_3_wd.h"
#include "linked_list_wd.h"


using namespace std;

// 1. 设计一个递归算法，删除不带头结点的单链表 L 中所有值为 x 的结点
void Delete_x(LinkList::LNode* &p, ElemType_LinkList x){

    LinkList::LNode *q;
    if(p == NULL){  // 返回条件
        return;
    }
    if(p -> data == x){
        q = p;
        p = p -> next;
        delete q;
        Delete_x(p, x);
    }
    else{
        Delete_x(p -> next, x);
    }
}


// 2.在带头结点的单链表 L 中，删除所有值为 x 的结点，并释放其空间，值为 x 的结点不唯一
// 递归方法
void Delete_x2(LinkList::LNode* &p, ElemType_LinkList x){

    LinkList::LNode *q;

    if(p -> next == NULL){  // 返回条件
        return;
    }
    if(p -> next -> data == x){
        q = p -> next;
        p -> next = q -> next;
        delete q;
        Delete_x(p, x);
    }
    else{
        Delete_x(p -> next, x);
    }
}
// 非递归方法
void Delete_x3(LinkList::LNode* &p, ElemType_LinkList x){

    LinkList::LNode* q = p -> next;
    LinkList::LNode* pre = p;
    while(q){
        if(q -> data == x){
            pre -> next = q -> next;
            delete q;
            q = pre -> next;
        }
        else{
            q = q -> next;
            pre = pre -> next;
        }
    }
}


// 3.设 L 为带头结点的单链表，编写算法实现从尾到头反向输出每个结点的值

// 使用递归方式实现。书上的答案是不带头结点的写法
void Reverse_Print(LinkList::LNode* &p){

    if(p -> next == NULL){
        return;
    }
    Reverse_Print(p->next);
    cout << p -> next -> data;

// 书上的方法，有问题
//    if(p -> next != NULL){
//        Reverse_Print(p->next);
//    }
//    cout << p -> data;
}


// 4.编写在带头结点的单链表 L 中删除一个最小值结点的高效算法（假设最小值唯一）
bool Delete_Min(LinkList::LNode* &p){

    if(p -> next == NULL)
        return false;
    LinkList::LNode* q = p -> next;
    LinkList::LNode* pre_q = p;

    LinkList::LNode* p_min = p -> next;
    LinkList::LNode* pre_min = p;

    while(q){
        if(q -> data < p_min -> data){
            p_min = q;
            pre_min = pre_q;
        }
        pre_q = q;
        q = q -> next;
    }
    pre_min -> next = p_min -> next; //删除
    delete p_min;

    return true;
}


// 5.将带头结点的单链表就地逆置

// 方法一：头插法重新建立链表（因为不重新分配内存，因此也是原地算法）。O(n)
bool Reverse_List(LinkList::LNode* &p){

    if(p -> next == NULL){
        return false;
    }

    LinkList::LNode* work = p -> next;
    LinkList::LNode* q = work;
    p -> next = NULL;
    while(work){
        work = work -> next;
        q -> next = p -> next;
        p -> next = q;
        q = work;
    }
    return true;
}
// 方法二：使相邻元素的指向翻转。O(n)
bool Reverse_List2(LinkList::LNode* &p){

    if(p -> next == NULL){
        return false;
    }
    LinkList::LNode* work = p -> next;
    LinkList::LNode* q = work -> next;
    LinkList::LNode* pre;
    work -> next = NULL;  // 处理第一个结点
    while(q){
        pre = work;
        work = q;
        q = q -> next;
        work -> next = pre;
    }
    p -> next = work;  // 处理最后一个结点
    return true;
}

// 方法三：类似冒泡法，多轮交换相邻元素。O(n^2)
bool Reverse_List3(LinkList::LNode* &p){

    if(p -> next == NULL){
        return false;
    }
    LinkList::LNode* work = p -> next;
    LinkList::LNode* q = NULL;  // 哨兵指针
    ElemType_LinkList e;
    while(p -> next != q){
        while(work -> next != q){
            e = work -> data;
            work -> data = work -> next -> data;
            work -> next -> data = e;
            work = work -> next;
        }
        q = work;
        work = p -> next;  // 一轮循环结束，哨兵前移
    }
    return true;
}


// 6.使带头结点的单链表 L 递增有序
void Sort(LinkList &L){

    L.Insertion_Sort();
//    L.Bubble_Sort();  // 兼容带头结点和不带头结点
//    L.Selection_Sort();  // 兼容带头结点和不带头结点
}


// 7.带头结点的无序单链表，删除表中所有介于给定两值之间的元素
void RangeDelete(LinkList::LNode* p, ElemType_LinkList min, ElemType_LinkList max){

    if(p -> next == NULL)
        return;

    LinkList::LNode* q = p -> next;
    LinkList::LNode* pre = p;

    while(q){
        if(q -> data > min && q -> data < max){
            p = q;   // p 不是引用形参，可以作为临时变量用
            pre -> next = q -> next;
            q = q -> next;
            delete p;
        }
        else{
            pre = q;
            q = q -> next;
        }

    }
}

// 8.给定两个单链表，找出公共结点


// 9.递增输出单链表数据，并释放空间，不允许使用数组作为辅助空间


//10.将带头结点的单链表 A 按节点序号的奇偶性分解为 A、B 两个带头结点的单链表


//11.同 10. 但是 B 逆序


//12.删除重复元素


//13.两个递增次序的单链表归并为一个递减次序的单链表，且用原先两个链表的结点存放，不新增结点


//14.从递增有序的两个单链表 A、B 的公共元素产生单链表 C，不破坏 A、B 结点


//15.将递增有序的 A、B 链表的交集存放在 A 链表中


//16.判断 B 单链表是否是 A 单链表的连续子序列


//17.判断带头结点的循环双链表是否对称


//18.将循环单链表 h1 链接到循环单链表 h2 之后，链接后仍保持循环链表的形式


//19.结点值均为正整数的带头结点的循环单链表，反复找出其中值最小的结点输出后删除，
//   最后删除表头结点


//20.带头结点的非循环双链表，除数据域和指针域，还有一个访问频度域 freq，
//   实现 Locate(L, x) 函数，使每在链表中进行一次该运算，值为 x 的结点的 freq 增 1，
//   并使结点保持访问平度非增的顺序排列，且最近访问的结点排在相同频度结点的前面（靠近表头）


//21.带头结点的单链表，只给出头指针 list，不改变链表的前提下查找倒数第 k 个位置的结点，
//   输出 data 值，并返回 1，否则只返回 0


//22.用带头结点的单链表保存单词，当两个单词有相同后缀时可共享后缀存储空间，找出两个单词
//   所在单链表的的共同后缀的起始位置。已给定两个单词的头指针。


//23.删除单链表中多余的绝对值相等的结点，只保留第一次出现的结点







