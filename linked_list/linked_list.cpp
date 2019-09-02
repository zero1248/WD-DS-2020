/*
*********************************************************************************************************
*
* file name:   linked_list.cpp
* creator:     Isaac
* date:        20190412
* description: linked list
*
*********************************************************************************************************
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <typeinfo>
#include "linked_list.h"
#include "test_set.h"

using namespace std;



LinkList::LinkList(HeadNode head, ListType listtype){

    CreatList(head, listtype);

}

LinkList::~LinkList(){

	DestroyList();
}



/**********************************************************************/
/*
 * insert a node into the head of singly linked list
 * Parameters: init_data
 * Returns: status
 */
/**********************************************************************/
bool LinkList::HeadInsert(const ElemType_LinkList &e){

    LNode *p = new LNode(e);
    if(p){
        if(_has_HeadNode){
            if(_head -> next == NULL){ // 如果是插入的第一个节点，将尾指针指向它
                _tail = p;
            }
            p -> next = _head -> next;
            _head -> next = p;
        }
        else{
            if(_head == NULL){   // 如果是插入的第一个节点，将头尾指针指向它
                _head = p;
                _tail = p;
            }
            else{
                p -> next = _head;
                _head = p;
            }
        }
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
bool LinkList::TailInsert(const ElemType_LinkList &e){

    LNode *p = new LNode(e);
    if(p){
        if(_has_HeadNode){
            _tail -> next = p;
            _tail = p;
        }
        else{
            if(_head == NULL){ // 如果是插入的第一个结点
                _head = p;
                _tail = p;
            }
            else{
                _tail -> next = p;
                _tail = p;
            }
        }
    }
    else{
        return false;
        cout << "Insert failed, creat node failed" << endl;
    }
    return true;
}

/**********************************************************************/
/*
 * insert a node into appointed position of singly linked list(i >= 1)
 * Parameters: none
 * Returns: none
 */
/**********************************************************************/
bool LinkList::Insert(int i, const ElemType_LinkList &e){

    LNode *p = new LNode(e);
    LNode *q;
    if(_has_HeadNode){
        if(p){
//            GetNode(i-1, q);
            q = GetNode(i-1);
            p -> next = q -> next;
            q -> next = p;
            if(p -> next == NULL)
                _tail = p;
        }
        else{
            cout << "Insert failed" << endl;
            return false;
        }
    }
    else{
        if(p){
            if(i==1){  // 在第一个位置插入比较特殊
                if(_head == NULL){  // 如果原先链表为空，需要操作尾指针指向新结点
                    _head = p;
                    _tail = p;
                }
                else{
                    p -> next = _head;
                    _head = p;
                }
            }
            else{
                //    GetNode(i-1, q);
                q = GetNode(i-1);

                p -> next = q -> next;
                q -> next = p;
                if(p -> next == NULL)
                    _tail = p;
            }
        }
        else{
            cout << "Insert failed" << endl;
            return false;
        }
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
bool LinkList::GetElem(int i, ElemType_LinkList &e){

    if(i<1){
        cout << "get elem failed, parameter error" << endl;
        return false;
    }

    LNode *p = _head;
    while(i>(_has_HeadNode?0:1)){
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
bool LinkList::LocateElem(int &i, ElemType_LinkList e){

    if(typeid(e) != typeid(ElemType_LinkList)){
        cout << "locate failed, data type error" << endl;
        return false;
    }

    int loc = 1;
    LNode *p = (_has_HeadNode ? _head->next : _head);
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
bool LinkList::DeleteNode(int i){

    if(i<1){
        cout << "delete failed, parameter error" << endl;
        return false;
    }

    LNode *p, *q;

    if(!_has_HeadNode && i==1){
        p = _head;
        if(p){
            _head = p -> next;
            delete p;
            if(_head == NULL)
                _tail = NULL;
            return true;
        }
        else{
            cout << "delete failed, not that long" << endl;
            return false;
        }
    }
    else{
        p = GetNode(i-1);
        if(p && p -> next){
            q = p -> next;
            p -> next = q -> next;
            delete q;
            if(p -> next == NULL)
                _tail = p;
        }
        else{
            cout << "delete failed, exceed the list length" << endl;
            return false;
        }
        return true;
    }

}

/**********************************************************************/
/*
 * get the list length
 * Parameters: none
 * Returns: length
 */
/**********************************************************************/
int LinkList::GetListLength(){

    int len = 0;
    LNode *p = _has_HeadNode ? _head->next : _head;

    while(p){
        len++;
        p = p -> next;
    }

    return len;
}

void LinkList::ClearList(){

    LNode *p = _has_HeadNode ? _head->next : _head;
    while(p){
        LNode *q = p -> next;
        delete p;
        p = q;
    }
    _has_HeadNode ? _head->next = NULL : _head = NULL;
}

/**********************************************************************/
/*
 * print the singly link list
 * Parameters: none
 * Returns: none
 */
/**********************************************************************/
void LinkList::PrintList(){

    LNode *p = _has_HeadNode ? _head->next : _head;
    for(; p; p=p->next){
        if(typeid(ElemType_LinkList) == typeid(int))
            cout << p->data << endl;
        else if(typeid(ElemType_LinkList) == typeid(char))
            cout << p->data;
    }
    cout << endl;
}

/**********************************************************************/
/*
 * generate a singly link list from a exist file
 * Parameters: line
 * Returns: status
 */
/**********************************************************************/
bool LinkList::Generate_Test_Set(int line){

    string data_str;
    if(_has_HeadNode?(_head -> next != NULL):(_head != NULL) || typeid(ElemType_LinkList) != typeid(char)){ // only for empty list
        cout << "generate test set failed" << endl;
        return false;
    }

    if(GetLine_char(data_str, line, test_set_path)){

        int len = data_str.size();
        for(int i=0; i<len; i++){
            char e = data_str[i];
            Insert(i+1, e);
        }
    }
    else{
        cout << "generate test set failed, get line failed" << endl;
        return false;
    }

    return true;
}

bool LinkList::Generate_Test_Set(int s, int e){

    if(_has_HeadNode?(_head -> next != NULL):(_head != NULL) || (s > e) || typeid(ElemType_LinkList) != typeid(int)){
        cout << "generate test set failed" << endl;
        return false;
    }

    int val, k = 1;
    for(int i=s; i<=e; i++){
        if(GetLine_int(val, i, test_set_path_int)){
            Insert(k++, val);
        }
        else{
            cout << "generate test set failed, get line failed" << endl;
            return false;
        }
    }
    return true;
}



/**********************************************************************/
/*
 * creat a head node of singly linked list with initialization
 * Parameters: none
 * Returns: status
 */
/**********************************************************************/
bool LinkList::CreatList(HeadNode head, ListType listtype){

    _has_HeadNode = head; // 默认使用头结点
    _list_type = listtype;

    if(_has_HeadNode){
        _head = new LNode('6');  // 头指针指向头结点，头结点初始化指向 NULL
        if(_head){
            _tail = _head; // 尾指针也指向头结点
        }
        else{
            cout << "creat node failed" << endl;
            return false;
        }
        return true;
    }
    else{
        _head = NULL;
        _tail = NULL;
    }
}

/**********************************************************************/
/*
 * clear singly linked list
 * Parameters: none
 * Returns: none
 */
/**********************************************************************/
void LinkList::DestroyList(){

    cout << endl << "destruct starting ..." << endl;
    LNode *p = _head;
    while(p){
        LNode *q = p -> next;
        delete p;
        p = q;
    }
    cout << "destruct end" << endl;
}

/**********************************************************************/
/*
 * get node point by ordinal number
 * Parameters: ordinal number, node value
 * Returns: status
 */
/**********************************************************************/
bool LinkList::GetNode(int i, LNode* &p){


    if(i < (_has_HeadNode?0:1)){
        cout << "get node failed, parameter error" << endl;
        p = NULL;
        return false;
    }

    p = _head;
    while(i>(_has_HeadNode?0:1)){
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

LinkList::LNode* LinkList::GetNode(int i){  // another form

    LNode* p;
    if(i < (_has_HeadNode?0:1)){
        cout << "get node failed, parameter error" << endl;
        return NULL;
    }
    p = _head;
    while(i > (_has_HeadNode?0:1)){
        if(p -> next == NULL){
            cout << "get elem failed, exceed the list length" << endl;
            return NULL;
        }
        p = p -> next;
        i--;
    }
    return p;
}

/**********************************************************************/
/*
 * whether the list is empty
 * Parameters: none
 * Returns: status
 */
/**********************************************************************/
bool LinkList::isEmpty(){

    if(_has_HeadNode ? _head -> next == NULL : _head == NULL){
        return true;
    }
    return false;
}



//int main(){
//
//    ElemType_LinkList x = 0;
//    int loc = 0;
//    LinkList L(has_headnode, singly);
//    LinkList M(no_headnode, singly);

//// 测试各项操作
//    cout << "linked list with head node:" << endl << endl;
//    L.HeadInsert('0');
//    L.PrintList();
//    L.HeadInsert('1');
//    L.PrintList();
//    L.HeadInsert('2');
//    L.PrintList();
//    L.HeadInsert('3');
//    L.PrintList();
//    L.HeadInsert(52);
//    L.PrintList();
//
//    L.TailInsert('1');
//    L.PrintList();
//    L.TailInsert('2');
//    L.PrintList();
//    L.TailInsert('3');
//    L.PrintList();
//
//    L.Insert(1, '7');
//    L.PrintList();
//    L.PrintList();
//    L.PrintList();
//    L.Insert(10, '7');
//    L.PrintList();
//
//    cout << "list length: " << L.GetListLength() << endl << endl;
//
//    L.DeleteNode(1);
//    L.PrintList();
//    cout << "list length: " << L.GetListLength() << endl << endl;
//    L.DeleteNode(1);
//    L.PrintList();
//    cout << "list length: " << L.GetListLength() << endl << endl;
//    L.DeleteNode(L.GetListLength());
//    L.PrintList();
//    cout << "list length: " << L.GetListLength() << endl << endl;
//    L.DeleteNode(L.GetListLength());
//    L.PrintList();
//    cout << "list length: " << L.GetListLength() << endl << endl;
//
//    L.TailInsert('4');
//    L.PrintList();
//    L.TailInsert('5');
//    L.PrintList();
//    L.TailInsert('6');
//    L.PrintList();
//
//    L.GetElem(1, x);
//    cout << "the 1st element is: " << x << endl;
//    L.GetElem(2, x);
//    cout << "the 2nd element is: " << x << endl;
//    L.GetElem(3, x);
//    cout << "the 3rd element is: " << x << endl;
//    L.GetElem(L.GetListLength(), x);
//    cout << "the last element is: " << x << endl;
//
//    L.LocateElem(loc, '4');
//    cout << "\'4\' is in:  " << loc << endl;
//    L.LocateElem(loc, '5');
//    cout << "\'5\' is in:  " << loc << endl;
//    L.LocateElem(loc, '1');
//    cout << "\'1\' is in:  " << loc << endl;
//    L.LocateElem(loc, '7');
//    cout << "\'7\' is in:  " << loc << endl;
//    cout << endl;


//    cout << "linked list without head node:" << endl << endl;
//    M.HeadInsert('0');
//    M.PrintList();
//    M.HeadInsert('1');
//    M.PrintList();
//    M.HeadInsert('2');
//    M.PrintList();
//    M.HeadInsert('3');
//    M.PrintList();
//    M.HeadInsert(52);
//    M.PrintList();
//
//    M.TailInsert('1');
//    M.PrintList();
//    M.TailInsert('2');
//    M.PrintList();
//    M.TailInsert('3');
//    M.PrintList();
//
//    M.Insert(1, '7');
//    M.PrintList();
//    M.Insert(6, '7');
//    M.PrintList();
//    M.Insert(11, '7');
//    M.PrintList();
//
//    cout << "list length: " << M.GetListLength() << endl << endl;
//
//    M.DeleteNode(1);
//    M.PrintList();
//    cout << "list length: " << M.GetListLength() << endl << endl;
//    M.DeleteNode(1);
//    M.PrintList();
//    cout << "list length: " << M.GetListLength() << endl << endl;
//    M.DeleteNode(M.GetListLength());
//    M.PrintList();
//    cout << "list length: " << M.GetListLength() << endl << endl;
//    M.DeleteNode(M.GetListLength());
//    M.PrintList();
//    cout << "list length: " << M.GetListLength() << endl << endl;
//
//    M.TailInsert('4');
//    M.PrintList();
//    M.TailInsert('5');
//    M.PrintList();
//    M.TailInsert('6');
//    M.PrintList();
//
//    M.GetElem(1, x);
//    cout << "the 1st element is: " << x << endl;
//    M.GetElem(2, x);
//    cout << "the 2nd element is: " << x << endl;
//    M.GetElem(3, x);
//    cout << "the 3rd element is: " << x << endl;
//    M.GetElem(M.GetListLength(), x);
//    cout << "the last element is: " << x << endl;
//
//    M.LocateElem(loc, '3');
//    cout << "\'3\' is in:  " << loc << endl;
//    M.LocateElem(loc, '5');
//    cout << "\'5\' is in:  " << loc << endl;
//    M.LocateElem(loc, '1');
//    cout << "\'1\' is in:  " << loc << endl;
//    M.LocateElem(loc, '7');
//    cout << "\'7\' is in:  " << loc << endl;
//    cout << endl;


//// 测试生成测试数据功能
//    for(int i=1; i<29; i++){
//        L.Generate_Test_Set(i);
//        L.PrintList();
//        L.ClearList();
//    }
//    cout << endl;


//    for(int i=1; i<29; i++){
//        M.Generate_Test_Set(i);
//        M.PrintList();
//        M.ClearList();
//    }
//    cout << endl;

//    return 0;
//}
