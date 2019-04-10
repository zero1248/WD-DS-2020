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
#include <iostream>
#include "chapter2_2.h"
#include <cstring>

using namespace std;

// 1. 从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值。空出的位置由最后一个元素填补，
//    若顺序表为空则显示出错信息并退出运行。
bool Del_Min(SqList &L, ElemType_SqList &e){

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
    L.length--; //最后一个元素填补后删除
    return true;
}

//2. 设计一个高效算法，将顺序表 L 的所有元素逆置，要求算法的空间复杂度为 O(1)
bool Reverse(SqList &L){

    int len = L.length;
    ElemType_SqList e;
    for(int i=0; i<len/2; i++){
        e = L.data[i];
        L.data[i] = L.data[len-i-1];
        L.data[len-i-1] = e;
    }
    return true;
}

//3. 对长度为 n 的顺序表 L，编写一个时间复杂度为 O(n)、空间复杂度为O(1)的算法，
//   该算法删除线性表中所有值为 x 的数据元素
bool Delete_x(SqList &L, ElemType_SqList x){

    int len = L.length;
    int step = 0;
    for(int i=0; i<len; i++){
        if(step)
            L.data[i-step] = L.data[i];
        if(L.data[i] == x)
            step++;
    }
    L.length -= step;
    return true;
}

//4. 从有序顺序表中删除其值在给定值 s 与 t 之间（s<t）的所有元素，
//   如果 s 或 t 不合理或顺序表为空，则显示出错信息并退出运行
bool Delete_s_t1(SqList &L, ElemType_SqList s, ElemType_SqList t){

    if((s >= t) || (L.length == 0))
        return false;

    int i,j;
    int len = L.length;
    for(i=0; L.data[i]<s && i<len; i++); //第一个大于等于 s
    if(i > len-1)
        return false;
    for(j=0; L.data[j]<=t && j<len; j++); //第一个大于 t
    for(; j<len; i++,j++)
        L.data[i] = L.data[j];
    L.length = i;
    return true;
}

//5. 从顺序表中删除其值在给定值 s 和 t 之间（包含 s 和 t，要求 s<t）的所有元素，
//   如果 s 或 t 不合理或顺序表为空，则显示出错信息并退出运行
bool Delete_s_t2(SqList &L, ElemType_SqList s, ElemType_SqList t){

    if((s >= t) || (L.length == 0))
        return false;

    int len = L.length;
    int k = 0;
    for(int i=0; i<len; i++){
        if((L.data[i] < s) || (L.data[i] > t)){
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
    return true;
}

//6. 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同
bool Delete_Same(SqList &L){

    int len = L.length;
    int step = 0;
    for(int i=1; i<len; i++){
    	if(L.data[i] == L.data[i-1]){
    		step++;
    	}
        if(step){
    		L.data[i-step] = L.data[i];
    	}
    }
    L.length -= step;
    return true;
}

//7. 将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表
bool Merge(SqList A, SqList B, SqList &C){

    if(A.length + B.length > C.listsize)
        return false;
    int i = 0, j = 0, k = 0;
    while(i < A.length && j < B.length){
        if(A.data[i] < B.data[j])
            C.data[k++] = A.data[i++];
        else
            C.data[k++] = B.data[j++];
    }
    while(i < A.length)
        C.data[k++] = A.data[i++];
    while(j < B.length)
        C.data[k++] = B.data[j++];
    C.length = k;
    return true;
}

//8. 已知在一维数组 A[m+n] 中依次存放两个线性表 (a1,a2,…,am) 和 (b1,b2,…,bn)。
//   试编写一个函数，将数组中两个顺序表的位置互换，即将 (b1,b2,…,bn) 放在
//   (a1,a2,…,am) 的前面
bool Add(SqList &A, SqList B){

    if(A.length+B.length>A.listsize)
        return false;
    int k = A.length;
    for(int i=0; i<B.length; i++){
        A.data[k+i] = B.data[i];
        A.length++;
    }
    return true;
}

bool Reverse(SqList &L, int m, int n){

    if(m>=n || m<1 || n>L.length)
        return false;
    int len = n - m + 1;
    len /= 2;
    ElemType_SqList temp;
    for(int i = 0; i < len; i++){
        temp = L.data[m-1+i];
        L.data[m-1+i] = L.data[n-1-i];
        L.data[n-1-i] = temp;
    }
    return true;
}

bool Exchange_m_n(SqList &L, int m, int n){

    Reverse(L, 1, m+n);
    Reverse(L, 1, n);
    Reverse(L, n+1, m+n);

    return true;
}

//9. 在有序线性表中查找值为 x 的元素，若找到将其与后继元素位置交换，若找不到将其值插入表中
//   并使表中元素仍有序递增
bool SearchExchangeInsert(SqList &L, ElemType_SqList x){

    int pos;
    if(Binary_Search(L, x, pos)){
        cout << pos << endl;
        if(pos != L.length-1){
            int temp = L.data[pos-1];
            L.data[pos-1] = L.data[pos];
            L.data[pos] = temp;
        }
    }
    else{
        cout << pos << endl;
        ListInsert_Sq(L, pos+1, x); //在比 x 的小的最大数之后插入 x
    }
    return true;
}
//书上答案
//bool SearchExchangeInsert(SqList &L, ElemType_SqList x){
//
//    int low = 0, high = L.length-1,mid;
//    while(low <= high){
//        mid = (low + high) / 2;
//        if(L.data[mid] == x) break;
//        else if(L.data[mid] < x)
//            low = mid + 1;
//        else
//            high = mid - 1;
//    }
//    if(L.data[mid] == x && mid != L.length-1){
//        int temp = L.data[mid];
//        L.data[mid] = L.data[mid+1];
//        L.data[mid+1] = temp;
//    }
//    int i;
//    if(low > high){
//        for(i=L.length-1; i>high; i--)
//            L.data[i+1] = L.data[i];
//        L.data[i+1] = x;
//    }
//}

//10.循环左移 p 个位置
bool Shifting(SqList &L, int p){

    Reverse(L, 1, L.length);
    Reverse(L, 1, L.length-p);
    Reverse(L, L.length-p+1, L.length);

    return true;
}

//11.找出两个升序序列的中位数
ElemType_SqList M_Search(SqList A, SqList B){

    int len = (A.length + B.length)/2;
    int i = 0, j = 0, k = 0;
    ElemType_SqList mid = 0;
    while(k<len){
        if(A.data[i] < B.data[j]){
            mid = A.data[i++];
        }
        else
            mid = B.data[j++];
        k++;
    }
    return mid;
}

//12.找出主元素（个数大于一半长度的元素）
ElemType_SqList Majority(SqList L){

    ElemType_SqList maj = L.data[0];
    int k = 1;
    for(int i=1; i<L.length; i++){
        if(maj == L.data[i])
            k++;
        else
            k--;
        if(k == 0){
            maj = L.data[i];
            k = 1;
        }
    }
    int cnt = 0;
    for(int j=0; j<L.length; j++){

        if(maj == L.data[j])
            cnt++;
    }
    if(cnt > L.length/2)
        return maj;
    else
        return -1;
}

//13.找出未出现的最小正整数
int Find_Miss_Min(SqList &L){

    int len = L.length;
    int i;
    ElemType_SqList* bucket = new ElemType_SqList[len]; // C++
    memset(bucket, 0, len*sizeof(ElemType_SqList));
    for(i=0; i<len; i++){
        if(L.data[i] > 0 && L.data[i] <= len)
            bucket[L.data[i]-1] = 1;
    }
    for(i=0; i<len; i++){
        if(bucket[i] == 0){
            break;
        }
    }
    delete[] bucket;  // C++
    return i+1;
}















