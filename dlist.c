#include "dlist.h"

void dInit(dListNode* head) {
	head->left = head;
	head->right = head;
}

void dInsert(dListNode* pnode, element val) { //pnode 오른쪽에 insert
	dListNode* n = (dListNode*)malloc(sizeof(dListNode));
	n->data = val;
	n->left = pnode;
	n->right = pnode->right;
	pnode->right->left = n;
	pnode->right = n;
}
void dDelete(dListNode* head, dListNode* removed) {
	if (removed == head) return;
	dListNode* left = removed->left;
	dListNode* right = removed->right;
	left->right = removed->right;
	right->left = removed->left;
	free(removed);
}
void print_dlist(dListNode* head) {
	for(dListNode*p=head->right;p!=head;p=p->right){
		printf("%3d", p->data);
	}
	printf("\n");
}


void dlist_test() {
	dListNode* head = (dListNode*)malloc(sizeof(dListNode));
	dInit(head);
	printf("첫 위치에 노드 5개 순차적 추가\n");
	for (int i = 1; i <= 5; i++) {
		dInsert(head, i);
		print_dlist(head);
	}
	printf("첫 번째 노드 5개 순차적 삭제\n");
	print_dlist(head);
	for (int i = 1; i <= 5; i++) {
		dDelete(head, head->right);
		print_dlist(head);
	}
	free(head);
}
