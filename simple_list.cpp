#include "simple_list.h"

//insert first
Node* insert_first_simple(Node* head, element val) {
	Node* n = (Node*)malloc(sizeof(Node));
	n->val = val;
	n->next = head;
	if (head == NULL) {
		head = n;
		return head;
	}
	else head = n;
	return head;
}

//insert node
Node* insert_simple(Node* head, Node* pre, element val) {
	Node* n = (Node*)malloc(sizeof(Node));
	n->val = val;
	n->next = pre->next;
	pre->next = n;
	return head;
}

//delete first
Node* delete_first_simple(Node* head) {
	if (head == NULL) {
		return NULL;
	}
	else {
		Node* tmp = head;
		head = head->next;
		free(tmp);
		return head;
	}
}

//head는 첫 구조체의 주소인듯!
//delete element
Node* del_simple(Node* head, Node* pre) {
	Node* tmp = pre->next;
	pre->next = tmp->next;
	free(tmp);
	return head;
}

//void print_list
void print_simple_list(Node* head) {
	for (Node* p = head; p != NULL; p = p->next) {
		printf("%3d -> ", p->val);
	}
	printf(" NULL\n");
}

//search
Node* search_simple_list(Node* head, element val) {
	for (Node* p = head; p != NULL; p = p->next) {
		if (p->val == val) {
			return p;
		}
	}
	return NULL;
}

//concat
Node* concat_simple_list(Node* head1, Node* head2) {
	if (head1 == NULL) {
		return head2;
	}
	else if (head2 == NULL) {
		return head1;
	}
	Node* p = head1;
	for (; p->next != NULL; p = p->next);
	p->next = head2;
	return head1;
}


/*
//main
int main() {
	Node* head = NULL;
	int num;
	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);
		print_list(head);
	}

	num = 2;
	if (search_list(head, num) != NULL) {
		printf("List에서 %d 찾음\n", num);
	}
	else printf("List에서 %d 못 찾음\n", num);

	num = 7;
	if (search_list(head, num) != NULL) {
		printf("List에서 %d 찾음\n", num);
	}
	else printf("List에서 %d 못 찾음\n", num);

	Node* head2 = NULL;
	for (int i = 6; i < 10; i++) {
		head2 = insert_first(head2, i);
		print_list(head2);
	}
	head = concat_list(head, head2);
	print_list(head);

	return 0;
}
*/