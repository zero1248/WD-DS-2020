#include <iostream>
#include "chapter2_3_wd.h"

using namespace std;


///*----------------2.3  1----------------*/
//int main(){
//
//    ElemType_LinkList x = '0';
//    LinkList L(no_headnode, singly);
//
//    for(int i=1; i<29; i++){
//        cout << "test" << i << ": " << endl;
//        L.Generate_Test_Set(i);
//        L.Print_List();
//
//        Delete_x(L._head, x);
//
//        L.Print_List();
//        L.Clear_List();
//        cout << endl;
//    }
//
//
//    return 0;
//}

///*----------------2.3  2----------------*/
//int main(){
//
//    ElemType_LinkList x = '0';
//    LinkList L(has_headnode, singly);
//
//    for(int i=1; i<29; i++){
//        cout << "test" << i << ": " << endl;
//        L.Generate_Test_Set(i);
//        L.Print_List();
//
////        Delete_x2(L._head, x); // 递归方法
//        Delete_x3(L._head, x);  // 非递归方法
//
//        L.Print_List();
//        L.Clear_List();
//        cout << endl;
//    }
//    return 0;
//}

///*----------------2.3  3----------------*/
//int main(){
//
//    LinkList L(has_headnode, singly);
//
//    for(int i=1; i<29; i++){
//        cout << "test" << i << ": " << endl;
//        L.Generate_Test_Set(i);
//        L.Print_List();
//
//        Reverse_Print(L._head);
//        cout << endl;
//
//        L.Print_List();
//        L.Clear_List();
//        cout << endl;
//    }
//    return 0;
//}

///*----------------2.3  4----------------*/
//int main(){
//
//    LinkList L(has_headnode, singly);
//
//    for(int i=1; i<29; i++){
//        cout << "test" << i << ": " << endl;
//        L.Generate_Test_Set(i);
//        L.Print_List();
//
//        Delete_Min(L._head); //因为有重复，删除的实际是第一个最小的结点
//
//        L.Print_List();
//        L.Clear_List();
//        cout << endl;
//    }
//    return 0;
//}

///*----------------2.3  5----------------*/
//int main(){
//
//    LinkList L(has_headnode, singly);
//
//    for(int i=1; i<29; i++){
//        cout << "test" << i << ": " << endl;
//        L.Generate_Test_Set(i);
//        L.Print_List();
//
////        Reverse_List(L._head);
////        Reverse_List2(L._head);
//        Reverse_List3(L._head);
//
//        L.Print_List();
//        L.Clear_List();
//        cout << endl;
//    }
//    return 0;
//}

///*----------------2.3  6----------------*/
//int main(){
//
//    LinkList L(has_headnode, singly);
//
//    for(int i=1; i<29; i++){
//        cout << "test" << i << ": " << endl;
//        L.Generate_Test_Set(i);
//        L.Print_List();
//
//        Sort(L);
//
//        L.Print_List();
//        L.Clear_List();
//        cout << endl;
//    }
//    return 0;
//}

///*----------------2.3  7----------------*/
//int main(){
//
//    LinkList L(has_headnode, singly);
//
//    for(int i=1; i<29; i++){
//        cout << "test" << i << ": " << endl;
//        L.Generate_Test_Set(i);
//        L.Print_List();
//
//        RangeDelete(L._head, '1', 'c');
//
//        L.Print_List();
//        L.Clear_List();
//        cout << endl;
//    }
//    return 0;
//}

///*----------------2.3  8----------------*/
int main(){

    LinkList L(has_headnode, singly);

    for(int i=1; i<29; i++){
        cout << "test" << i << ": " << endl;
        L.Generate_Test_Set(i);
        L.Print_List();

        RangeDelete(L._head, '1', 'c');

        L.Print_List();
        L.Clear_List();
        cout << endl;
    }
    return 0;
}






