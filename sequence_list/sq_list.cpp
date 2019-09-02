/*
*********************************************************************************************************
*
* file name:   sq_list.cpp
* creator:     Isaac
* date:        20190403
* description: sequence list
*
*********************************************************************************************************
*/
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <typeinfo>
#include <iostream>
#include "sq_list.h"
#include "test_set.h"

using namespace std;

/*-------------------------------------------------------------------------
                               basic options
--------------------------------------------------------------------------*/

/**********************************************************************/
/*
 * creat a new sequence list
 * Parameters: a new squence list
 * Returns: status
 */
/**********************************************************************/
bool InitList_Sq(SqList &L){

	L.data = (ElemType_SqList *)malloc(LIST_INIT_SIZE * sizeof(ElemType_SqList));  // C
//	L.data = new ElemType_SqList[LIST_INIT_SIZE]; // C++
	if (!(L.data))
        exit(false);       //assign failed
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;

    return true;
}

/**********************************************************************/
/*
 * destroy an exist sequence list
 * Parameters: an exist squence list
 * Returns: status
 */
/**********************************************************************/
bool DestroyList_Sq(SqList &L){

    free(L.data);  // C
//    delete[] L.data;  // C++
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;

    return true;
}

/**********************************************************************/
/*
 * clear a sequence list
 * Parameters: an exist squence list
 * Returns: status
 */
/**********************************************************************/
bool ClearList_Sq(SqList &L){

    L.length = 0;

    return true;
}

/**********************************************************************/
/*
 * judge if a sequence list is empty
 * Parameters: an exist squence list
 * Returns: logic value
 */
/**********************************************************************/
bool ListEmpty_Sq(SqList &L){

    if((L.length) == 0)
        return true;
    else
        return false;
}

/**********************************************************************/
/*
 * get the length of a sequence list
 * Parameters: an exist squence list
 * Returns: length of the list
 */
/**********************************************************************/
int ListLength_Sq(SqList &L){

	return L.length;
}

/**********************************************************************/
/*
 * get the i th value of a sequence list
 * Parameters: an exist squence ist, location i, element
 * Returns: status
 */
/**********************************************************************/
bool GetElem_Sq(SqList &L, int i, ElemType_SqList &e){

    if(i<1 || i>L.length)
        return false;
    e = L.data[i-1];
    return true;
}


/**********************************************************************/
/*
 * get the location of certain elmement
 * Parameters: an exist squence ist, element
 * Returns: location(>0)
 */
/**********************************************************************/
int LocateElem_Sq(SqList &L, ElemType_SqList e){

    int i = 0;
    for(i=0; i<L.length; i++){
        if(L.data[i] == e)
            return i+1;
    }
    return false;  // return 0 means e is not exist
}


/**********************************************************************/
/*
 * return the prior elmement of cur_e using pre_e
 * Parameters: an exist squence list, element cur_e, element pre_e
 * Returns: status
 */
/**********************************************************************/
bool PriorElem_Sq(SqList &L, ElemType_SqList cur_e, ElemType_SqList &pre_e){

    int i = 0;

    for(i=L.length; i>0; i--){
        if(L.data[i-1] == cur_e && (i > 1)){
            pre_e = L.data[i-2];
            return true;
        }
    }

	return false;
}

/**********************************************************************/
/*
 * return the next elmement of cur_e using pre_e
 * Parameters: an exist squence list, element cur_e, element pre_e
 * Returns: status
 */
/**********************************************************************/
bool NextElem_Sq(SqList &L, ElemType_SqList cur_e, ElemType_SqList &next_e){

    int i = 0;

    for(i=L.length; i>0;i--){
        if(L.data[i-1] == cur_e && (i<L.length)){
            next_e = L.data[i];
            return true;
        }
    }

    return false;
}

/**********************************************************************/
/*
 * insert new element e before the i element
 * Parameters: an exist squence list, location i, new element e
 * Returns: status
 */
/**********************************************************************/
bool ListInsert_Sq(SqList &L, int i, ElemType_SqList e){

	ElemType_SqList* newbase;
	ElemType_SqList* q; //point to insert location
	ElemType_SqList* p; //shift pointer

	if( i < 1 || i > L.length+1 )
		return false;
	if( i > L.listsize ){  //current storage space is full, increase assignment
		newbase = (ElemType_SqList*)realloc(L.data, (L.listsize + LIST_INCREMENT) * sizeof(ElemType_SqList));
		if(!newbase)
			exit(false);
		L.data = newbase;
		L.listsize += LIST_INCREMENT;
	}
	q = &(L.data[i-1]);  //insert location
	for(p = &(L.data[L.length-1]); p >= q; p-- )
		*(p + 1) = *p;
	*q = e;
	L.length++;

    return true;
}

/**********************************************************************/
/*
 * Delete element from squence list
 * Parameters: an exist squence list, location i, deleted element
 * Returns: status
 */
/**********************************************************************/
bool ListDelete_Sq(SqList &L, int i, ElemType_SqList &e){

	ElemType_SqList* q; //point to delete location
	ElemType_SqList* p; //shift pointer


	if( i < 1 || i > L.length+1 )
		return false;

	q = &(L.data[i-1]);  //delete location
	e = *q;
	for(p = q; p < &(L.data[L.length-1]); p++)
		*p = *(p + 1);
    /*p = q + L->length-1;  //q as shift pointer
    for(q++; q<=p; q++)
        *(q-1) = *q;*/
	(L.length)--;

    return true;
}



/***********************************************************************/



/*-------------------------------------------------------------------------
                               other options
--------------------------------------------------------------------------*/

/**********************************************************************/
/*
 * print a squence list
 * Parameters: an exist squence list
 * Returns: status
 */
/**********************************************************************/
bool PrintList_Sq(SqList &L){

	int i = 0;

	if(!(L.length)){
        printf("the sequence list is empty \n");
        return true;
    }

    printf("the sequence list contains below:\n");
	for (i = 0; i < L.length; i++){
        if(typeid(ElemType_SqList) == typeid(char))
            printf("%c",L.data[i]);
        else if(typeid(ElemType_SqList) == typeid(int))
            printf("%d\n",L.data[i]);
	}
	printf("\n");

    return true;
}

/**********************************************************************/
/*
 * generate a squence list from a exist file
 * Parameters: an exist squence list, and line
 * Returns: status
 */
/**********************************************************************/
bool Generate_Test_Set(SqList &L, int line){

    string data_str;
    if(L.length != 0 || typeid(ElemType_SqList) != typeid(char)){ // only for empty list
        cout << "generate test set failed" << endl;
        return false;
    }

    if(GetLine_char(data_str, line, test_set_path)){

        int len = data_str.size();
        for(int i=0; i<len; i++){
            char e = data_str[i];
            ListInsert_Sq(L, i+1, e);
        }
    }
    else{
        cout << "generate test set failed, get line failed" << endl;
        return false;
    }

    return true;
}

bool Generate_Test_Set(SqList &L, int s, int e){

    if(L.length !=0 || s > e || typeid(ElemType_SqList) != typeid(int)){
        cout << "generate test set failed" << endl;
        return false;
    }

    int val, k = 1;
    for(int i=s; i<=e; i++){
        if(GetLine_int(val, i, test_set_path_int)){
            ListInsert_Sq(L, k++, val);
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
 * bubble sort
 * Parameters: an exist squence list
 * Returns: status
 */
/**********************************************************************/
bool Bubble_Sort(SqList &L){

    int len = L.length;
    ElemType_SqList temp;
    for(int i=0; i<len; i++){
        for(int j=1; j<len-i; j++){
            if(L.data[j] < L.data[j-1]){
                temp = L.data[j];
                L.data[j] = L.data[j-1];
                L.data[j-1] = temp;
            }
        }
    }
    return true;
}

/**********************************************************************/
/*
 * binary search
 * Parameters: an exist squence list, and element x
 * Returns: position
 */
/**********************************************************************/
bool Binary_Search(SqList L, ElemType_SqList x, int &pos){

    int low = 0, high = L.length-1;
    int mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(L.data[mid] == x){
            pos = mid + 1;  //pos 是 x 的位置
            return true;
        }
        else if(L.data[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    pos = high + 1; //pos 是比x小的数中最大数的位置
    return false;
}








