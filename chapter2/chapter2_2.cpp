/*
*********************************************************************************************************
*
* file name:   chapter.cpp
* creator:     Isaac
* date:        20190403
* description: 《王道 数据结构》2.2
*
*********************************************************************************************************
*/

#include "chapter2_2.h"



// 1. 从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值。空出的位置由最后一个元素填补，
//    若顺序表为空则显示出错信息并退出运行。
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

