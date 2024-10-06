// Study-DoubleLinkList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

typedef struct Node {
    int data;//存放Val
    struct Node* next;//下一个
    struct Node* pre;//上一个
}Node;


//创建新双链表的头
Node* InitNewNode(int val) {
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = val;
    head->next = NULL;

    return head;
}

//头插法
void InitHeadMethod(Node *head,vector<int> array) {
    if (head == NULL) return;
    Node* p = head;//表头

    int i = 0;//索引

    while (p != NULL) {
        if (i == array.size()) return;
        Node* s = (Node*)malloc(sizeof(Node));//开辟新空间
        s->data = array[i];
        s->next = head->next;
        s->pre = head;
        head->next = s;
        i++;
    }
}
//尾插法
void InitTailMethod(Node* head, vector<int> array) {
    if (head == NULL) return;

    Node* p = head;//前进指针

    int i = 0; 

    while (p != NULL) {
        if (i == array.size()) return;
        Node* s = (Node*)malloc(sizeof(Node));//开辟新空间
        s->data = array[i];//赋值
        s->next = p->next;
        p->next = s;
        s->pre = p;
        p = s;

        i++;
    }
}

//遍历链表
void ergDbLinkList(Node *head) {
    if (head == NULL) {
        printf("长度为1");
        return;
    }
    Node* p = head;
    while (p != NULL) {
        printf("%d \n", p->data);
        p = p->next;
    }
}
//根据索引找出对应的val
void ergDbLinkListByIndex(Node* head,int index) {
    if (head == NULL) {
        printf("长度为1");
        return;
    }
    Node* p = head;
    int i = 0;
    while (p != NULL) {
        if(i == index){
            printf("%d \n", p->data);
            return;
        }
        p = p->next;
    }
}


int main()
{
    Node* node_1 = InitNewNode(10);
    Node* node_2 = InitNewNode(100);
    vector<int> array = { 1,2,3,4,5,6,7,8 };
    //头插法
    InitHeadMethod(node_1,array);
    ergDbLinkList(node_1);

    printf("----------------------- \n");

    //尾插法
    InitTailMethod(node_2,array);
    ergDbLinkList(node_2);

}
