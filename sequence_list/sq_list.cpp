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
#include "sq_list.h"

/****************************linear list**********************************
**************************************************************************/
/*

	SqList list_test;
	ElemType_SqLlist temp_value = 0;

	InitList_Sq(&list_test);
	PrintList_Sq(&list_test);

	ListInsert_Sq(&list_test, 1, '1');
	PrintList_Sq(&list_test);
	ListInsert_Sq(&list_test, 2, '2');
	PrintList_Sq(&list_test);
	ListInsert_Sq(&list_test, 3, '3');
	PrintList_Sq(&list_test);
	ListInsert_Sq(&list_test, 4, '4');
	PrintList_Sq(&list_test);
	ListInsert_Sq(&list_test, 5, '5');
	PrintList_Sq(&list_test);
	printf("the sequence linear list %s an empty list \n",ListEmpty_Sq(&list_test)?"is not":"is");

	ListDelete_Sq(&list_test, 5, &temp_value);
	PrintList_Sq(&list_test);
	printf("delete element \"%c\" from the sequence linear list \n", temp_value);

	GetElem_Sq(&list_test, 3, &temp_value);
	printf("the third element of the sequence linear list is %c \n", temp_value);

	printf("the sequence linear list has %d elements \n",ListLength_Sq(&list_test));

	PriorElem_Sq(&list_test, '2', &temp_value);
	printf("the prior element of '2' in the sequence linear list is %c \n", temp_value);

	NextElem_Sq(&list_test, '2', &temp_value);
	printf("the next element of '2' in the sequence linear list is %c \n", temp_value);

//	DestroyList_Sq(&list_test);
//	PrintList_Sq(&list_test);

	ClearList_Sq(&list_test);
	PrintList_Sq(&list_test);

//	printf("the sequence linear list %s an empty list \n",ListEmpty_Sq(&list_test)?"is not":"is");

//	printf("NULL is %d %s",NULL,NULL);

*/
/******************************linear list*********************************/
/**************************************************************************/


/**********************************************************************/
/*
 * creat a new sequence linear list
 * Parameters: a new squence linear list
 * Returns: status
 */
/**********************************************************************/
bool InitList_Sq(SqList &L){

	L.data = (ElemType_SqLlist *)malloc(LIST_INIT_SIZE * sizeof(ElemType_SqLlist));  // C
//	L.data = new ElemType_SqLlist[LIST_INIT_SIZE]; // C++
	if (!(L.data))
        exit(false);       //assign failed
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;

    return true;
}

/**********************************************************************/
/*
 * destroy an exist sequence linear list
 * Parameters: an exist squence linear list
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
 * clear a sequence linear list
 * Parameters: an exist squence linear list
 * Returns: status
 */
/**********************************************************************/
bool ClearList_Sq(SqList &L){

    L.length = 0;

    return true;
}

/**********************************************************************/
/*
 * judge if a sequence linear list is empty
 * Parameters: an exist squence linear list
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
 * get the length of a sequence linear list
 * Parameters: an exist squence linear list
 * Returns: length of the list
 */
/**********************************************************************/
int ListLength_Sq(SqList &L){

	return L.length;
}

/**********************************************************************/
/*
 * get the i th value of a sequence linear list
 * Parameters: an exist squence linear list, location i, element
 * Returns: status
 */
/**********************************************************************/
bool GetElem_Sq(SqList &L, int i, ElemType_SqLlist &e){

    if(i<1 || i>L.length)
        return false;
    e = L.data[i-1];
    return true;
}

bool LocateElem_Sq(SqList &L, ElemType_SqLlist* e){

    return true;
}

/**********************************************************************/
/*
 * return the prior elmement of cur_e using pre_e
 * Parameters: an exist squence linear list, element cur_e, element pre_e
 * Returns: status
 */
/**********************************************************************/
bool PriorElem_Sq(SqList &L, ElemType_SqLlist cur_e, ElemType_SqLlist &pre_e){

    int i = 0;

    for(i=L.length; i>0; i--){
        if(L.data[i-1] == cur_e && (i > 1)){
            pre_e = L.data[i-2];
            return true;
        }
    }
    pre_e = NULL;

	return false;
}

/**********************************************************************/
/*
 * return the next elmement of cur_e using pre_e
 * Parameters: an exist squence linear list, element cur_e, element pre_e
 * Returns: status
 */
/**********************************************************************/
bool NextElem_Sq(SqList &L, ElemType_SqLlist cur_e, ElemType_SqLlist &next_e){

    int i = 0;

    for(i=L.length; i>0;i--){
        if(L.data[i-1] == cur_e && (i<L.length)){
            next_e = L.data[i];
            return true;
        }
    }
    next_e = NULL;

    return true;
}

/**********************************************************************/
/*
 * insert new element e before the i element
 * Parameters: an exist squence linear list, location i, new element e
 * Returns: status
 */
/**********************************************************************/
bool ListInsert_Sq(SqList &L, int i, ElemType_SqLlist e){

	ElemType_SqLlist* newbase;
	ElemType_SqLlist* q; //point to insert location
	ElemType_SqLlist* p; //shift pointer

	if( i < 1 || i > L.length+1 )
		return false;
	if( i > L.listsize ){  //current storage space is full, increase assignment
		newbase = (ElemType_SqLlist*)realloc(L.data, (L.listsize + LIST_INCREMENT) * sizeof(ElemType_SqLlist));
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
 * Delete element from squence linear list
 * Parameters: an exist squence linear list, location i, deleted element
 * Returns: status
 */
/**********************************************************************/
bool ListDelete_Sq(SqList &L, int i, ElemType_SqLlist &e){

	ElemType_SqLlist* q; //point to delete location
	ElemType_SqLlist* p; //shift pointer

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

/**********************************************************************/
/*
 * print a squence linear list
 * Parameters: an exist squence linear list
 * Returns: status
 */
/**********************************************************************/
bool PrintList_Sq(SqList &L){

	int i = 0;

	if(!(L.length)){
        printf("the sequence linear list is empty \n");
        return true;
    }

    printf("the sequence linear list contains below:\n");
	for (i = 0; i < L.length; i++){
		printf("%c",L.data[i]);
	}
	printf("\n");

    return true;
}


