#include "dlist.h"

int main() {
	dListNode* head = (dListNode*)malloc(sizeof(dListNode));
	dInit(head);
	printf("ù ��ġ�� ��� 5�� ������ �߰�\n");
	for (int i = 1; i <= 5; i++) {
		dInsert(head, i);
		print_dlist(head);
	}
	printf("ù ��° ��� 5�� ������ ����\n");
	print_dlist(head);
	for (int i = 1; i <= 5; i++) {
		dDelete(head, head->right);
		print_dlist(head);
	}
	free(head);
	return 0;
}
