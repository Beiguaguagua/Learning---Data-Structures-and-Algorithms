#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/// <summary>
/// 反转链表
/// </summary>
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
		if (i == array.size()) return;
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
void deleteElement(int i, Node* node) {
	int k = 0;
	if (node->next == NULL) {
		return;
	}
	if (node->next == NULL) {
		return;
	}
	Node* p = node;
	while (p != NULL) {
		if (k == i - 1) {
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
void ergodicLinkList(Node* node) {
	if (node == NULL) {
		return;
	}
	Node* p = node;
	while (p != NULL) {
		cout << p->data << endl;
		p = p->next;
	}

}
//反转链表
//方法1-反转数组，然后进行尾插法
Node* reverseLinkList_1(Node* head,vector<int> array) {
	vector<int> tempArray;
	reverse(array.begin(), array.end());
	Node* newList = InitNewNode(10);
	tailInsert(array,newList);

	return newList;
}

//方法2-三指针
Node* reverseLinkList_2(Node *head) {
	if (head == NULL) return NULL;
	Node* p = head;
	Node* prev = nullptr;
	while (p != nullptr) {
		Node* n = p->next;//存储下一个节点的内容
		p->next = prev;
		prev = p;
		p = n;
	}
	return prev;
}


int main()
{
	Node* firNode = InitNewNode(10);
	vector<int> arr = { 1,2,3,4,5,6,7,9 };
	tailInsert(arr, firNode);
	//反转1
	Node* test = reverseLinkList_1(firNode,arr);
	ergodicLinkList(test);

	//反转2
	Node* prev = reverseLinkList_2(firNode);
	ergodicLinkList(prev);
}