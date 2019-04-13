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

    ElemType_SlList x = 0;
    int loc = 0;
    SLinkList L;

    L.HeadInsert('0');
    L.HeadInsert('1');
    L.HeadInsert('2');
    L.HeadInsert('3');
    L.HeadInsert(52);
    L.TailInsert('1');
    L.TailInsert('2');
    L.TailInsert('3');
    L.Insert(1, '7');

    L.PrintList();
    cout << "list length: " << L.GetListLength() << endl;


    L.DeleteNode(1);
    L.PrintList();

    cout << "list length: " << L.GetListLength() << endl;


//    L.GetElem(2, x);
//    L.LocateElem(loc, '5');
//    cout << x << endl;
//    cout << loc << endl;

    return 0;
}
#endif // CHAPTER2_3








