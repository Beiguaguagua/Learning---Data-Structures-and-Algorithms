#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

typedef struct Node {
    int data;//存储的val值
	struct  Node* next;//指向下一个val的指针
} Node;


/// <summary>
/// 初始化指针
/// </summary>
/// <param name="val"></param>
/// <returns></returns>
Node* InitNewNode(int val) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = val;
	p->next = NULL;
	return p;

}

//头插法
void headInsert(vector<int> array, Node* node) {
	if (node->next == NULL) {
		return;
	}
	if (array.size() == 0) {
		return;
	}
	Node* p = node;
	int i = 0; 
	while (p != NULL) {
		if (i == array.size() - 1) return;
		Node* s = (Node*)malloc(sizeof(Node));//开辟新空间用于存放新值

		s->data = array[i];
		s->next = p->next;
		p->next = s;

		i++;
	}

}

//尾插法
void tailInsert(vector<int> array, Node* node) {
	if (array.size() == 0) {
		return;
	}

	Node* p = node;
	int i = 0;
	while (p != NULL) {
		if (i == array.size() - 1) return;
		Node* s = (Node*)malloc(sizeof(Node));//开辟新空间用于存放新值
		s->data = array[i];

		s->next = p->next;
		p->next = s;
		p = s;

		i++;
	}
}

//删除

/// <summary>
/// 根据索引删除
/// </summary>
/// <param name="i">索引</param>
/// <param name="node">链表本身</param>
void deleteElement(int i ,Node *node) {
	int k = 0;
	if (node->next == NULL) {
		return;
	}
	if (node->next == NULL) {
		return;
	}
	Node* p = node;
	while (p != NULL) {
		if (k == i-1) {
			Node* s = p->next;
			Node* q = s->next;
			p->next = q;
			delete s;
			return;
		}
		k++;
	}

}

//遍历
void ergodicLinkList(Node *node) {
	if (node == NULL) {
		return;
	}
	Node* p = node;
	while (p != NULL) {
		cout << p->data << endl;
		p = p->next;
	}

}


int main()
{
	Node* firNode = InitNewNode(10);
	Node* secNode = InitNewNode(20);
	vector<int> arr = { 1,2,3,4,5,6,7,9 };
	vector<int> array = { 1,2,3,4,5,6,7,9 };
	tailInsert(arr, firNode);

	headInsert(array, secNode);

	ergodicLinkList(secNode);

	cout << "------------------------" << endl;

	ergodicLinkList(firNode);


    return 0;
}