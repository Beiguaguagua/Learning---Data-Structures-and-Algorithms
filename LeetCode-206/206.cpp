#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/// <summary>
/// ��ת����
/// </summary>
typedef struct Node {
	int data;//�洢��valֵ
	struct  Node* next;//ָ����һ��val��ָ��
} Node;


/// <summary>
/// ��ʼ��ָ��
/// </summary>
/// <param name="val"></param>
/// <returns></returns>
Node* InitNewNode(int val) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = val;
	p->next = NULL;
	return p;

}

//ͷ�巨
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
		Node* s = (Node*)malloc(sizeof(Node));//�����¿ռ����ڴ����ֵ

		s->data = array[i];
		s->next = p->next;
		p->next = s;

		i++;
	}

}

//β�巨
void tailInsert(vector<int> array, Node* node) {
	if (array.size() == 0) {
		return;
	}

	Node* p = node;
	int i = 0;
	while (p != NULL) {
		if (i == array.size()) return;
		Node* s = (Node*)malloc(sizeof(Node));//�����¿ռ����ڴ����ֵ
		s->data = array[i];

		s->next = p->next;
		p->next = s;
		p = s;

		i++;
	}
}

//ɾ��

/// <summary>
/// ��������ɾ��
/// </summary>
/// <param name="i">����</param>
/// <param name="node">������</param>
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

//����
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
//��ת����
//����1-��ת���飬Ȼ�����β�巨
Node* reverseLinkList_1(Node* head,vector<int> array) {
	vector<int> tempArray;
	reverse(array.begin(), array.end());
	Node* newList = InitNewNode(10);
	tailInsert(array,newList);

	return newList;
}

//����2-��ָ��
Node* reverseLinkList_2(Node *head) {
	if (head == NULL) return NULL;
	Node* p = head;
	Node* prev = nullptr;
	while (p != nullptr) {
		Node* n = p->next;//�洢��һ���ڵ������
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
	//��ת1
	Node* test = reverseLinkList_1(firNode,arr);
	ergodicLinkList(test);

	//��ת2
	Node* prev = reverseLinkList_2(firNode);
	ergodicLinkList(prev);
}