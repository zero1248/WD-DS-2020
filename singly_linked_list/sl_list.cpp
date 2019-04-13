/*
*********************************************************************************************************
*
* file name:   sl_list.cpp
* creator:     Isaac
* date:        20190412
* description: singly link list
*
*********************************************************************************************************
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <typeinfo>
#include "sl_list.h"

using namespace std;



SLinkList::SLinkList(){

    CreatList();
}

SLinkList::~SLinkList(){

	ClearList();
}

/**********************************************************************/
/*
 * creat a head node of singly linked list with initialization
 * Parameters: none
 * Returns: status
 */
/**********************************************************************/
bool SLinkList::CreatList(){

    head = new SLNode(0);  // 头指针指向头结点，头结点初始化指向 NULL
    if(head){
        tail = head; // 尾指针也指向头结点
    }
    else{
        cout << "creat node failed" << endl;
        return false;
    }
    return true;
}

/**********************************************************************/
/*
 * clear singly linked list
 * Parameters: none
 * Returns: none
 */
/**********************************************************************/
void SLinkList::ClearList(){

    SLNode *p = head;
    while(p){
        SLNode *q = p -> next;
        delete p;
        p = q;
    }
}

/**********************************************************************/
/*
 * insert a node into the head of singly linked list
 * Parameters: init_data
 * Returns: status
 */
/**********************************************************************/
bool SLinkList::HeadInsert(const ElemType_SlList &e){

    SLNode *p = new SLNode(e);

    if(p){
        if(head -> next == NULL){ // 如果是插入的第一个节点，将尾指针指向它
            tail = p;
        }
        p -> next = head -> next;
        head -> next = p;
    }
    else{
        cout << "Insert failed, creat node failed" << endl;
        return false;
    }
    return true;
}

/**********************************************************************/
/*
 * insert a node into the tail of singly linked list
 * Parameters: none
 * Returns: none
 */
/**********************************************************************/
bool SLinkList::TailInsert(const ElemType_SlList &e){

    SLNode *p = new SLNode(e);
    if(p){
        tail -> next = p;
        tail = p;
    }
    else{
        return false;
        cout << "Insert failed, creat node failed" << endl;
    }
    return true;
}

/**********************************************************************/
/*
 * insert a node into appointed position of singly linked list
 * Parameters: none
 * Returns: none
 */
/**********************************************************************/
bool SLinkList::Insert(int i, const ElemType_SlList &e){

    SLNode *p = new SLNode(e);
    SLNode *q;
//    GetNode(i-1, q);
    q = GetNode(i-1);
    if(q){
        p -> next = q -> next;
        q -> next = p;
    }
    else{
        cout << "Insert failed" << endl;
        return false;
    }
    return true;
}

/**********************************************************************/
/*
 * get node value by ordinal number
 * Parameters: ordinal number, node value
 * Returns: status
 */
/**********************************************************************/
bool SLinkList::GetElem(int i, ElemType_SlList &e){

    if(i<1){
        cout << "get elem failed, parameter error" << endl;
        return false;
    }

    SLNode *p = head;
    while(i>0){
        if(p -> next == NULL){
            cout << "get elem failed, exceed the list length" << endl;
            return false;
        }
        p = p -> next;
        i--;
    }
    e = p -> data;

    return true;
}

/**********************************************************************/
/*
 * get node position of a given value
 * Parameters: ordinal number, node value
 * Returns: status
 */
/**********************************************************************/
bool SLinkList::LocateElem(int &i, ElemType_SlList e){

    if(typeid(e) != typeid(ElemType_SlList)){
        cout << "locate failed, data type error" << endl;
        return false;
    }

    int loc = 1;
    SLNode *p = head -> next;
    while(p){
        if(p -> data == e){
            i = loc;
            return true;
        }
        p = p -> next;
        loc++;
    }
    i = 0;
    return false;
}

/**********************************************************************/
/*
 * delete a node
 * Parameters: ordinal number
 * Returns: status
 */
/**********************************************************************/
bool SLinkList::DeleteNode(int i){

    if(i<1){
        cout << "delete failed, parameter error" << endl;
        return false;
    }

    SLNode *p, *q;
    p = GetNode(i-1);
    if(p && p -> next){
        q = p -> next;
        p -> next = q -> next;
        delete q;
    }
    else{
        cout << "delete failed, exceed the list length" << endl;
        return false;
    }
    return true;
}

/**********************************************************************/
/*
 * get the list length
 * Parameters: none
 * Returns: length
 */
/**********************************************************************/
int SLinkList::GetListLength(){

    int len = 0;
    SLNode *p = head -> next;

    while(p){
        len++;
        p = p -> next;
    }

    return len;
}





/**********************************************************************/
/*
 * print the singly link list
 * Parameters: none
 * Returns: none
 */
/**********************************************************************/
void SLinkList::PrintList(){

    SLNode *p = head -> next;
    for(; p; p=p->next){
        if(typeid(ElemType_SlList) == typeid(int))
            cout << p->data << endl;
        else if(typeid(ElemType_SlList) == typeid(char))
            cout << p->data;
    }
    cout << endl;
}





/**********************************************************************/
/*
 * get node point by ordinal number
 * Parameters: ordinal number, node value
 * Returns: status
 */
/**********************************************************************/

bool SLinkList::GetNode(int i, SLNode* &p){

    if(i<0){
        cout << "get node failed, parameter error" << endl;
        p = NULL;
        return false;
    }

    p = head;
    while(i>0){
        if(p -> next == NULL){
            cout << "get elem failed, exceed the list length" << endl;
            p = NULL;
            return false;
        }
        p = p -> next;
        i--;
    }

    return true;
}

SLinkList::SLNode* SLinkList::GetNode(int i){  // another form

    SLNode* p;
    if(i<0){
        cout << "get node failed, parameter error" << endl;
        return NULL;
    }
    p = head;
    while(i>0){
        if(p -> next == NULL){
            cout << "get elem failed, exceed the list length" << endl;
            return NULL;
        }
        p = p -> next;
        i--;
    }
    return p;
}

bool SLinkList::isEmpty(){

    if(head -> next == NULL)
        return true;

    return false;
}
