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
// 链表部分没有按照《王道·数据结构》的方式实现
// 更新：与《王道》相同的指针方式在 chapter2_3 工程中实现

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "sq_list.h"
#include "linked_list.h"
#include "chapter2_2.h"
#include "chapter2_3.h"

using namespace std;

#define CHAPTER2_2
#define CHAPTER2_3

// ElemType_SqList 在 sq_list.h 中修改


#ifdef CHAPTER2_2

///*----------------2.2  1----------------*/
//// 需要把 ElemType_SqList 改成 char
//int main(void){
//	SqList L;
//	ElemType_SqList e = 0;
//	ElemType_SqList temp_value = 0;
//    InitList_Sq(L);
//    for(int i=0; i<1; i++){
//        cout << "test" << i+1 << ": " << endl;
//        Generate_Test_Set(L, i+1);
//        PrintList_Sq(L);
//
//        Del_Min(L, e);
//        cout << "Delete: " << e << endl << endl;
//
//        PrintList_Sq(L);
//        ClearList_Sq(L);
//        cout << endl;
//    }
//    DestroyList_Sq(L);
//	return 0;
//}

///*----------------2.2  2----------------*/
//// 需要把 ElemType_SqList 改成 char
//int main(void){
//	SqList L;
//	ElemType_SqList e = 0;
//	ElemType_SqList temp_value = 0;
//    InitList_Sq(L);
//    for(int i=0; i<1; i++){
//        cout << "test" << i+1 << ": " << endl;
//        Generate_Test_Set(L, i+1);
//        PrintList_Sq(L);
//
//        Reverse(L);
//
//        PrintList_Sq(L);
//        ClearList_Sq(L);
//        cout << endl;
//    }
//    DestroyList_Sq(L);
//	return 0;
//}

///*----------------2.2  3----------------*/
//// 需要把 ElemType_SqList 改成 char
//int main(void){
//	SqList L;
//	ElemType_SqList e = 0;
//	ElemType_SqList temp_value = 0;
//    InitList_Sq(L);
//    for(int i=0; i<1; i++){
//        cout << "test" << i+1 << ": " << endl;
//        Generate_Test_Set(L, i+1);
//        PrintList_Sq(L);
//
//        Delete_x(L, '5');
//
//        PrintList_Sq(L);
//        ClearList_Sq(L);
//        cout << endl;
//    }
//    DestroyList_Sq(L);
//	return 0;
//}

///*----------------2.2  4----------------*/
//// 需要把 ElemType_SqList 改成 char
//int main(void){
//	SqList L;
//	ElemType_SqList e = 0;
//	ElemType_SqList temp_value = 0;
//    InitList_Sq(L);
//    for(int i=0; i<1; i++){
//        cout << "test" << i+1 << ": " << endl;
//        Generate_Test_Set(L, i+1);
//        PrintList_Sq(L);
//
//        Bubble_Sort(L);
//        PrintList_Sq(L);
//        Delete_s_t1(L, '5', 'h');
//
//        PrintList_Sq(L);
//        ClearList_Sq(L);
//        cout << endl;
//    }
//    DestroyList_Sq(L);
//	return 0;
//}

///*----------------2.2  5----------------*/
//// 需要把 ElemType_SqList 改成 char
//int main(void){
//	SqList L;
//	ElemType_SqList e = 0;
//	ElemType_SqList temp_value = 0;
//    InitList_Sq(L);
//    for(int i=0; i<1; i++){
//        cout << "test" << i+1 << ": " << endl;
//        Generate_Test_Set(L, i+1);
//        PrintList_Sq(L);
//
//
//        Delete_s_t2(L, '5', 'h');
//
//        PrintList_Sq(L);
//        ClearList_Sq(L);
//        cout << endl;
//    }
//    DestroyList_Sq(L);
//	return 0;
//}

///*----------------2.2  6----------------*/
//// 需要把 ElemType_SqList 改成 char
//int main(void){
//	SqList L;
//	ElemType_SqList e = 0;
//	ElemType_SqList temp_value = 0;
//    InitList_Sq(L);
//    for(int i=0; i<1; i++){
//        cout << "test" << i+1 << ": " << endl;
//        Generate_Test_Set(L, i+1);
//        PrintList_Sq(L);
//
//        Bubble_Sort(L);
//        PrintList_Sq(L);
//        Delete_Same(L);
//
//        PrintList_Sq(L);
//        ClearList_Sq(L);
//        cout << endl;
//    }
//    DestroyList_Sq(L);
//	return 0;
//}

///*----------------2.2  7----------------*/
//// 需要把 ElemType_SqList 改成 char
//int main(void){
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
//        Merge(L, M, N);
//        PrintList_Sq(N);
//
//        ClearList_Sq(L);
//        ClearList_Sq(M);
//        ClearList_Sq(N);
//        cout << endl;
//    }
//    DestroyList_Sq(L);
//    DestroyList_Sq(M);
//    DestroyList_Sq(N);
//
//	return 0;
//}

///*----------------2.2  8----------------*/
//// 需要把 ElemType_SqList 改成 char
//int main(void){
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
//        Add(L, M);
//        PrintList_Sq(L);
//        Exchange_m_n(L, L.length-M.length, M.length);
//        PrintList_Sq(L);
//
//        ClearList_Sq(L);
//        ClearList_Sq(M);
//        ClearList_Sq(N);
//        cout << endl;
//    }
//    DestroyList_Sq(L);
//    DestroyList_Sq(M);
//    DestroyList_Sq(N);
//
//	return 0;
//}

///*----------------2.2  9----------------*/
//// 需要把 ElemType_SqList 改成 char
//int main(void){
//	SqList L;
//	ElemType_SqList e = 0;
//	ElemType_SqList temp_value = 0;
//    InitList_Sq(L);
//    for(int i=0; i<1; i++){
//        cout << "test" << i+1 << ": " << endl;
//        Generate_Test_Set(L, i+1);
//        PrintList_Sq(L);
//
//        Bubble_Sort(L);
//        Delete_Same(L);
//        PrintList_Sq(L);
//        SearchExchangeInsert(L, '5');
//
//        PrintList_Sq(L);
//        ClearList_Sq(L);
//        cout << endl;
//    }
//    DestroyList_Sq(L);
//	return 0;
//}

///*----------------2.2  10---------------*/
//// 需要把 ElemType_SqList 改成 char
//int main(void){
//	SqList L;
//	ElemType_SqList e = 0;
//	ElemType_SqList temp_value = 0;
//    InitList_Sq(L);
//    for(int i=0; i<1; i++){
//        cout << "test" << i+1 << ": " << endl;
//        Generate_Test_Set(L, i+1);
//        PrintList_Sq(L);
//
//        Shifting(L, 5);
//
//        PrintList_Sq(L);
//        ClearList_Sq(L);
//        cout << endl;
//    }
//    DestroyList_Sq(L);
//	return 0;
//}

///*----------------2.2 11----------------*/
//// 需要把 ElemType_SqList 改成 char
//int main(void){
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
//        cout << M_Search(L, M) << endl;
//
//        ClearList_Sq(L);
//        ClearList_Sq(M);
//        ClearList_Sq(N);
//        cout << endl;
//    }
//    DestroyList_Sq(L);
//    DestroyList_Sq(M);
//    DestroyList_Sq(N);
//
//	return 0;
//}

///*----------------2.2  12---------------*/
//// 需要把 ElemType_SqList 改成 char
//int main(void){
//	SqList L;
//	ElemType_SqList e = 0;
//	ElemType_SqList temp_value = 0;
//    InitList_Sq(L);
//    for(int i=0; i<1; i++){
//        cout << "test" << i+1 << ": " << endl;
//        Generate_Test_Set(L, i+1);
//        PrintList_Sq(L);
//
//        cout << Majority(L) << endl;
//
//        PrintList_Sq(L);
//        ClearList_Sq(L);
//        cout << endl;
//    }
//    DestroyList_Sq(L);
//	return 0;
//}

///*----------------2.2  13---------------*/
//// 需要把 ElemType_SqList 改成 int
//int main(void){
//
//	SqList L;
//    InitList_Sq(L);
//    cout << "test: " << endl;
//    Generate_Test_Set(L, 2, 13);
//    PrintList_Sq(L);
//
//
//    int miss_min = Find_Miss_Min(L);
//    cout << miss_min << endl;
//
//    ClearList_Sq(L);
//    cout << endl;
//
//    DestroyList_Sq(L);
//
//	return 0;
//}

#endif // CHAPTER2_2

#ifdef CHAPTER2_3

///*----------------2.3  1----------------*/
//int main(){
//
//    ElemType_LinkList x = '0';
//    LinkList L(no_headnode, singly);
//
//    for(int i=1; i<29; i++){
//        cout << "test" << i+1 << ": " << endl;
//        L.Generate_Test_Set(i);
//        L.PrintList();
//
//        Delete_x(L, x, 1);
//
//        L.PrintList();
//        L.ClearList();
//        cout << endl;
//    }
//
//    return 0;
//}

///*----------------2.3  2----------------*/
// 可以直接用 1.题 的函数

///*----------------2.3  3----------------*/
//int main(){
//
//    LinkList L(has_headnode, singly);
//
//    for(int i=1; i<29; i++){
//        cout << "test" << i+1 << ": " << endl;
//        L.Generate_Test_Set(i);
//        L.PrintList();
//
//        Reverse_Print(L, 1);
//
//        L.ClearList();
//        cout << endl << endl;
//    }
//
//    return 0;
//}

///*----------------2.3  4----------------*/
int main(){

    LinkList L(has_headnode, singly);

    for(int i=1; i<29; i++){
        cout << "test" << i+1 << ": " << endl;
        L.Generate_Test_Set(i);
        L.PrintList();

        Delete_Min(L);

        L.PrintList();
        L.ClearList();
        cout << endl << endl;
    }

    return 0;
}

// 剩余题目在 chapter2_3 工程中单独实现

#endif // CHAPTER2_3








