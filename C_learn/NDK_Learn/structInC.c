#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> //only for system("pause")
//struct Node
//{
//	char *data;
//	struct Node *pre;
//	struct Node *next;
//	void(*printNode)(struct Node* d);
//	
//};
//void printNode(struct Node* d2)
//{
//	printf("%s", d2->data);
//}
//void initNode(struct Node* node,char *str) {
//	if (node != NULL)
//	{
//		node->pre = NULL;
//		node->next = NULL;
//		node->data = str;
//		node->printNode = printNode;
//	}
//}
//
//int main()
//{
//	struct Node head,nextNode;
//	initNode(&head,"head");
//	initNode(&nextNode,"nextNode");
//	head.printNode(&head);
//	system("pause");
//	return 0;
//}





//
//
//void addNode(struct Node*head, struct Node *d) {
//	if (head != NULL) {
//		struct Node* tempHead = head;
//		while (tempHead->next != NULL) {
//			tempHead = tempHead->next;
//		}
//		tempHead->next = d;
//		if (d != NULL) {
//			d->pre = tempHead;
//			d->next = NULL;
//		}
//
//	}
//	else { head = d; }
//}
//void removeNode(struct Node* head, struct Node * d) {
//
//}