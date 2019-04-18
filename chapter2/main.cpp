/*
*********************************************************************************************************
*
* file name:   main.cpp
* creator:     Isaac
* date:        20190403
* description: test the data sturcture module(chapter2)
*
*********************************************************************************************************
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "sq_list.h"
#include "sl_list.h"
//#include "main.h"
#include "chapter2_2.h"
//#include "test_set.h"

using namespace std;

//#define CHAPTER2_2
#define CHAPTER2_3


#ifdef CHAPTER2_2
int main(void){

//// 只对一个线性表（char 型）进行操作
//// 需要把 ElemType_SqList 改成 char
//	SqList L;
//	ElemType_SqList e = 0;
//	ElemType_SqList temp_value = 0;
//    InitList_Sq(L);
//    for(int i=0; i<1; i++){
//        cout << "test" << i+1 << ": " << endl;
//        Generate_Test_Set(L, i+1);
//        PrintList_Sq(L);
//
///*----------------2.2  1----------------*/
////        Del_Min(L, e);
////        cout << "Delete: " << e << endl << endl;
//
///*----------------2.2  2----------------*/
////        Reverse(L);
//
///*----------------2.2  3----------------*/
////        Delete_x(L, '5');
//
///*----------------2.2  4----------------*/
////        Bubble_Sort(L);
////        PrintList_Sq(L);
////        Delete_s_t1(L, '5', 'h');
//
///*----------------2.2  5----------------*/
////        Delete_s_t2(L, '5', 'h');
//
///*----------------2.2  6----------------*/
////        Bubble_Sort(L);
////        PrintList_Sq(L);
////        Delete_Same(L);
//
///*----------------2.2  9----------------*/
////        Bubble_Sort(L);
////        Delete_Same(L);
////        PrintList_Sq(L);
////        SearchExchangeInsert(L, '5');
//
///*----------------2.2  10---------------*/
////        Shifting(L, 5);
//
///*----------------2.2  12---------------*/
////        cout << Majority(L) << endl;
//
//
//        PrintList_Sq(L);
//        ClearList_Sq(L);
//        cout << endl;
//    }
//    DestroyList_Sq(L);





////对两个以上线性表（char 型）进行操作
//// 需要把 ElemType_SqList 改成 char
//	SqList L, M, N;
//	ElemType_SqList e = 0;
//	ElemType_SqList temp_value = 0;
//    InitList_Sq(L);
//    InitList_Sq(M);
//    InitList_Sq(N);
//    for(int i=0; i<19; i++){
//        cout << "test" << i+1 << ": " << endl;
//        Generate_Test_Set(L, i+1);
//        Bubble_Sort(L);
//        Generate_Test_Set(M, i+2);
//        Bubble_Sort(M);
//        PrintList_Sq(L);
//        PrintList_Sq(M);
//
///*----------------2.2  7----------------*/
////        Merge(L, M, N);
////        PrintList_Sq(N);
//
///*----------------2.2  8----------------*/
////        Add(L, M);
////        PrintList_Sq(L);
////        Exchange_m_n(L, L.length-M.length, M.length);
////        PrintList_Sq(L);
//
///*----------------2.2 11----------------*/
////        cout << M_Search(L, M) << endl;
//
//

//        ClearList_Sq(L);
//        ClearList_Sq(M);
//        ClearList_Sq(N);
//        cout << endl;
//    }
//    DestroyList_Sq(L);
//    DestroyList_Sq(M);
//    DestroyList_Sq(N);




// 只对一个线性表（int 型）进行操作
// 需要把 ElemType_SqList 改成 int
	SqList L;
    InitList_Sq(L);
    cout << "test: " << endl;
    Generate_Test_Set(L, 2, 13);
    PrintList_Sq(L);

/*----------------2.2  13---------------*/
    int miss_min = Find_Miss_Min(L);
    cout << miss_min << endl;



    ClearList_Sq(L);
    cout << endl;

    DestroyList_Sq(L);


//    SqList sq_L;
//    InitList_Sq(sq_L);
//    ListInsert_Sq(sq_L, 1, 'a');
//    PrintList_Sq(sq_L);

	return 0;
}

#endif // CHAPTER2_2

#ifdef CHAPTER2_3
int main(){

    ElemType_LinkList x = 0;
    int loc = 0;
    LinkList L(has_headnode, singly);
    LinkList M(no_headnode, singly);


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


// 测试生成测试数据功能
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


    return 0;
}
#endif // CHAPTER2_3








