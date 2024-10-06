//力扣61题-旋转链表

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
void tailInsert(Node* head, vector<int> array) {
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
/// 获取链表的长度
/// </summary>
/// <param name="head">链表头</param>
/// <returns></returns>
int getNodeLength(Node *head) {
    int i = 0; 
    Node* p = head;
    while (p != NULL) {
        p = p->next;
        i++;
    }
    return i;
}

/// <summary>
/// 旋转链表
/// </summary>
/// <param name="head">链表头</param>
/// <param name="k">需要旋转的次数</param>
Node* rotateRight(Node* head,int k) {
    if (k == 0 || head == nullptr || head->next == nullptr) {
        return head;
    }
    int n = 1;
    Node* iter = head;
    while (iter->next != nullptr) {
        iter = iter->next;
        n++;
    }
    int add = n - k % n;
    if (add == n) {
        return head;
    }
    iter->next = head;
    while (add--) {
        iter = iter->next;
    }
    Node* ret = iter->next;
    iter->next = nullptr;
    return ret;
}

//遍历
void ergodicLinkList(Node* node) {
    if (node == NULL) {
        return;
    }
    Node* p = node;
    while (p != NULL) {
        cout << p->data << "-";
        p = p->next;
    }

}

int main()
{
    vector<int> array = { 1,2,3,4,5,6,7,8,9,10 };
    Node* l = createNewLinkList(100);
    headInsert(l,array);
    ergodicLinkList(l);
    cout << endl;
    Node* nl = rotateRight(l,10);
    ergodicLinkList(nl);

}
