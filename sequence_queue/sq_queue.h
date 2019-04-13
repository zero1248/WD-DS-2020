/*
*********************************************************************************************************
*
* file name:   sq_queue.h
* creator:     Isaac
* date:        20190413
* description: sequence queue
*
*********************************************************************************************************
*/
#ifndef __SQ_QUEUE_H__
#define __SQ_QUEUE_H__

const int queue_size = 100;

//typedef char ElemType_SqQueue;
typedef int ElemType_SqQueue;


typedef struct SqQueue{

    ElemType_SqQueue *data; //
    int qfront, qrear;   // 队头指针和队尾指针

}SqQueue;

extern void InitQueue_Sq(SqQueue &Q);
extern void DestroyQueue_Sq(SqQueue &Q);
extern bool QueueEmpty_Sq(SqQueue Q);
extern bool QueueFull_Sq(SqQueue Q);
extern bool EnQueue_Sq(SqQueue &Q, ElemType_SqQueue e);
extern bool DeQueue_Sq(SqQueue &Q, ElemType_SqQueue &e);
extern bool GetFront_Sq(SqQueue Q, ElemType_SqQueue &e);
extern bool GetRear_Sq(SqQueue Q, ElemType_SqQueue &e);







#endif // __SQ_QUEUE_H__
