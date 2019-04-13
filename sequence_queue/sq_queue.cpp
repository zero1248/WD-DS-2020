/*
*********************************************************************************************************
*
* file name:   sq_queue.cpp
* creator:     Isaac
* date:        20190413
* description: sequence queue
*
*********************************************************************************************************
*/
#include <iostream>
#include "sq_queue.h"

using namespace std;


void InitQueue_Sq(SqQueue &Q){

    Q.data = new ElemType_SqQueue[queue_size];
    Q.qfront = 0;
    Q.qrear = 0;
}


void DestroyQueue_Sq(SqQueue &Q){

    delete[] Q.data;
    Q.qfront = 0;
    Q.qrear = 0;
}


bool QueueEmpty_Sq(SqQueue Q){

    if(Q.qrear == Q.qfront)
        return true;
    else
        return false;
}


bool QueueFull_Sq(SqQueue Q){

    if((Q.qrear+1)%queue_size == Q.qfront)
        return true;
    else
        return false;
}


bool EnQueue_Sq(SqQueue &Q, ElemType_SqQueue e){

    if(QueueFull_Sq(Q))
        return false;
    Q.data[Q.qrear] = e;
    Q.qrear = (Q.qrear + 1) % queue_size;

    return true;
}


bool DeQueue_Sq(SqQueue &Q, ElemType_SqQueue &e){

    if(QueueEmpty_Sq(Q))
        return false;
    e = Q.data[Q.qfront];
    Q.qfront = (Q.qfront + 1) % queue_size;

    return false;
}


bool GetFront_Sq(SqQueue Q, ElemType_SqQueue &e){

    if(QueueEmpty_Sq(Q))
        return false;
    e = Q.data[Q.qfront];

    return false;
}


bool GetRear_Sq(SqQueue Q, ElemType_SqQueue &e){

    if(QueueEmpty_Sq(Q))
        return false;
    e = Q.data[Q.qrear-1];

    return false;
}






