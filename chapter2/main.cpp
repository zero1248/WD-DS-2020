/*
*********************************************************************************************************
*
* file name:   main.cpp
* creator:     Isaac
* date:        20190403
* description: test the data sturcture module
*
*********************************************************************************************************
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "sq_list.h"
#include "sl_list.h"
#include "main.h"
//#include "test_set.h"

using namespace std;

int main(void){

	SqList list_test;
	ElemType_SqLlist temp_value = 0;

	InitList_Sq(list_test);
	generate_Test_Set(list_test, 5);
	PrintList_Sq(list_test);

//	SqList list_test;
//	ElemType_SqLlist temp_value = 0;
//
//	InitList_Sq(list_test);
//	PrintList_Sq(list_test);
//
//	ListInsert_Sq(list_test, 1, '1');
//	PrintList_Sq(list_test);
//	ListInsert_Sq(list_test, 2, '2');
//	PrintList_Sq(list_test);
//	ListInsert_Sq(list_test, 3, '3');
//	PrintList_Sq(list_test);
//	ListInsert_Sq(list_test, 4, '4');
//	PrintList_Sq(list_test);
//	ListInsert_Sq(list_test, 5, '5');
//	PrintList_Sq(list_test);
//	printf("the sequence linear list %s an empty list \n",ListEmpty_Sq(list_test)?"is not":"is");
//
//	ListDelete_Sq(list_test, 5, temp_value);
//	PrintList_Sq(list_test);
//	printf("delete element \"%c\" from the sequence linear list \n", temp_value);
//
//	GetElem_Sq(list_test, 3, temp_value);
//	printf("the third element of the sequence linear list is %c \n", temp_value);
//
//	printf("the sequence linear list has %d elements \n",ListLength_Sq(list_test));
//
//	PriorElem_Sq(list_test, '2', temp_value);
//	printf("the prior element of '2' in the sequence linear list is %c \n", temp_value);
//
//	NextElem_Sq(list_test, '2', temp_value);
//	printf("the next element of '2' in the sequence linear list is %c \n", temp_value);
//
//	DestroyList_Sq(list_test);
//	PrintList_Sq(list_test);
//
//	ClearList_Sq(list_test);
//	PrintList_Sq(list_test);
//
//	printf("the sequence linear list %s an empty list \n",ListEmpty_Sq(list_test)?"is not":"is");




//    SqList sq_L;
//    InitList_Sq(sq_L);
//    ListInsert_Sq(sq_L, 1, 'a');
//    PrintList_Sq(sq_L);

	return 0;
}

