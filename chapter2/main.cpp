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
//#include "main.h"
#include "chapter2_2.h"
//#include "test_set.h"

using namespace std;

int main(void){

// 2.2 “ª°¢1.Ã‚ ≤‚ ‘
	SqList L;
	ElemType_SqLlist e = 0;
	ElemType_SqLlist temp_value = 0;
    InitList_Sq(L);
    for(int i=0; i<13; i++){
        cout << "test" << i+1 << ": " << endl;
        generate_Test_Set(L, i+1);
        PrintList_Sq(L);
        Del_Min(L, e);
        PrintList_Sq(L);
        cout << "Delete: " << e << endl << endl;
        ClearList_Sq(L);
    }









//    SqList sq_L;
//    InitList_Sq(sq_L);
//    ListInsert_Sq(sq_L, 1, 'a');
//    PrintList_Sq(sq_L);

	return 0;
}

