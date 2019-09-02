/*
*********************************************************************************************************
*
* file name:   sq_list.h
* creator:     Isaac
* date:        20190403
* description: sequence list
*
*********************************************************************************************************
*/
#ifndef __SQ_LIST_H__
#define __SQ_LIST_H__

#define LIST_INIT_SIZE  100  // initial assigned amount of linear list storage space
#define LIST_INCREMENT  10   // assigned increment of linear list storage space

//typedef char ElemType_SqList;
typedef int ElemType_SqList;


typedef struct{
	ElemType_SqList  *data;       //storage space base address
	int length;      //current length
	int listsize;    //current assigned storage capacity
}SqList;

// 暂时没有写动态扩充容量的函数，直接开辟新内存并复制数据，然后回收旧内存即可

extern bool InitList_Sq(SqList&);  // 初始化一个顺序表
extern bool DestroyList_Sq(SqList&);  // 销毁一个顺序表（回收内存空间）
extern bool ClearList_Sq(SqList&);  // 清空一个顺序表
extern bool ListEmpty_Sq(SqList&);  // 顺序表判空
extern int ListLength_Sq(SqList&);  // 获取表长
extern bool GetElem_Sq(SqList&, int, ElemType_SqList&); // 获取指定位置元素
extern int LocateElem_Sq(SqList &, ElemType_SqList); // 定位某元素首次出现的位置
extern bool PriorElem_Sq(SqList&, ElemType_SqList, ElemType_SqList&);  // 获取指定元素的前一个元素
extern bool NextElem_Sq(SqList&, ElemType_SqList, ElemType_SqList&);   // 获取指定元素的后一个元素
extern bool ListInsert_Sq(SqList&, int, ElemType_SqList);  // 在指定位置插入元素
extern bool ListDelete_Sq(SqList&, int, ElemType_SqList&); // 删除指定位置元素

// 其他操作
extern bool PrintList_Sq(SqList&);  // 打印整个顺序表
extern bool Generate_Test_Set(SqList&, int);  // 生成 char 型测试集
extern bool Bubble_Sort(SqList&);  // 冒泡排序
extern bool Binary_Search(SqList, ElemType_SqList, int&);  // 二分查找
extern bool Generate_Test_Set(SqList&, int, int); // 生成 int 型测试集

#endif //__SQ_LIST_H__
