/*
*********************************************************************************************************
*
* file name:   chapter.cpp
* creator:     Isaac
* date:        20190403
* description: ������ ���ݽṹ��2.2
*
*********************************************************************************************************
*/

#include "chapter2_2.h"



// 1. ��˳�����ɾ��������Сֵ��Ԫ�أ�����Ψһ�����ɺ������ر�ɾԪ�ص�ֵ���ճ���λ�������һ��Ԫ�����
//    ��˳���Ϊ������ʾ������Ϣ���˳����С�
bool Del_Min(SqList &L, ElemType_SqLlist &e){

    if(L.length == 0)
        return false;
    e = L.data[0];
    int loc = 0;
    for(int i=1; i<L.length; i++){
        if(L.data[i]<e){
            e = L.data[i];
            loc = i;
        }
    }
    L.data[loc] = L.data[L.length-1];

    return 0;
}
