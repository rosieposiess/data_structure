#include "dlist.h"

int main() {
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
	return 0;
}
