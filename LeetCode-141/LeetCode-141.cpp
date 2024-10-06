// LeetCode-141.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

typedef struct Node {
    int data;//存放Val
    struct Node* next;//下一个
}Node;

/// <summary>
/// 创建新的链表
/// </summary>
/// <param name="val"></param>
/// <returns></returns>
Node* createNewLinkList(int val) {

    Node* head = (Node*)malloc(sizeof(Node));
    head->data = val;
    head->next = NULL;

    return head;
}
/// <summary>
/// 尾插法
/// </summary>
void tailInsert(Node *head,vector<int> array) {
    if (head == NULL) {
        cout << "该链表为空" << endl;
        return;
    }
    Node* p = head;
    int i = 0; 
    while (p != NULL) {
        if (i == array.size()) return;
        Node* s = (Node*)malloc(sizeof(Node));
        s->data = array[i];
        s->next = p->next;
        p->next = s;
        p = s;

        i++;
    }
    cout << "尾插法完成" << endl;
}

/// <summary>
/// 头插法
/// </summary>
void headInsert(Node* head, vector<int> array) {
    if (head == NULL) {
        cout << "该链表为空" << endl;
        return;
    }
    Node* p = head;
    int i = 0;
    while (p != NULL) {
        if (i == array.size()) return;
        Node* s = (Node*)malloc(sizeof(Node));
        s->data = array[i];
        s->next = p->next;
        p->next = s;

        i++;
    }
    cout << "头插法完成" << endl;
}
/// <summary>
/// 检查该链表是否为环形链表
/// </summary>
/// <param name="head">链表头部</param>
/// <param name="pos">检查环形的位置</param>
bool checkIsCircle(Node *head,int pos) {
    if (head == NULL) {
        cout << "该链表为空" << endl;
        return false;
    }
    Node* p = head;//赋值

    bool res = false;

    int i = 0; 

    Node* q = head;//pos位置的指针

    while (p != NULL) {
        if (i == pos) {
            q = p;//q指针指向pos位置
        }
        //检查p的next是否指向q
        if (p->next != q) {
            p = p->next;
            i++;
        }
        else {
            res = !res;
        }
    }

    return res;
}

int main()
{
    Node* test = createNewLinkList(10);   //声明新的链表
    vector<int> array = { 1,1,2,3,4,5,6,7,8 };
    headInsert(test,array);//头插法赋值
    bool res = checkIsCircle(test,2);//检查是否为环形链表
    if (res) {
        cout << "该链表为环形链表" << endl;
    }
    else {
        cout << "该链表不为环形链表" << endl;
    }
}
