//力扣19题-删除链表倒数第N个节点

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
/// 遍历链表
/// </summary>
/// <param name="node"></param>
void ergodicLinkList(Node* node) {
    if (node == NULL) {
        return;
    }
    Node* p = node;
    while (p != NULL) {
        cout << p->data << "-";
        p = p->next;
    }
    
    cout << "----------" << endl;
}

/// <summary>
/// 删除链表倒数第N个节点
/// </summary>
/// <param name="head">链表头</param>
/// <param name="n">倒数第几个节点</param>
/// <returns></returns>
Node* removeNthFromEnd(Node* head, int n) {

    if (head == NULL || n <= 0) {
        cout << "该链表为空或 n 无效" << endl;
        return head;
    }

    // 创建一个虚拟头节点
    Node* dummy = new Node();
    dummy->next = head;
    Node* f = dummy;
    Node* s = dummy;

    // 快指针先走 n 步
    for (int i = 0; i <= n; i++) {
        if (f == NULL) {
            return head;  // n 大于链表长度
        }
        f = f->next;
    }

    // 快慢指针一起走，直到快指针到达链表末尾
    while (f != NULL) {
        f = f->next;
        s = s->next;
    }

    // 删除慢指针的下一个节点
    Node* toDelete = s->next;
    s->next = toDelete->next;
    delete toDelete;

    // 返回新头节点
    Node* newHead = dummy->next;
    delete dummy;
    return newHead;
}

int cur = 0;//当前索引
Node* removeNthFromEnd_2(Node* head, int n) {
    if (!head) return NULL;
    head->next = removeNthFromEnd(head->next, n);
    cur++;
    if (n == cur) return head->next;
    return head;
}


int main()
{
    //准备基础数据
    vector<int> array = { 10,2,3,4,5,6,7,8,9 };
    Node* before = createNewLinkList(100);
    tailInsert(before,array);

    Node *temp = removeNthFromEnd(before,5);
    ergodicLinkList(temp);
}
