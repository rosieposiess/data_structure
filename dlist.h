#pragma once
#include <stdio.h>
#include <malloc.h>

typedef int element;
typedef struct dListNode {
	element data;
	dListNode* left;
	dListNode* right;
}dListNode;

void dInit(dListNode*head);
void dInsert(dListNode* pnode, element val); //pnode �����ʿ� insert
void dDelete(dListNode* head, dListNode* removed);
void print_dlist(dListNode* head);
void dlist_test();