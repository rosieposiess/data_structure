#include "stack.h"

Stack* initStack() {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->top = NULL;
	return s;
}


void error(const char* message) {
	printf("%s\n", message);
	exit(1);
}
//is_empty
int is_empty(Stack* s) {
	if (s->top == NULL) return 1;
	else return 0;
}

//pop
element pop(Stack*s) {
	if (is_empty(s)) {
		error("Stack is empty!\n");
	}
	StackNode* tmp = s->top;
	s->top = s->top->next;
	free(tmp);
	return tmp->data;
}

//push
void push(Stack* s, element e) {
	StackNode* node= (StackNode*)malloc(sizeof(StackNode));

	if (is_empty(s)) {
		s->top = node;
		node->data = e;
		node->next = NULL;
	}
	else {
		node->data = e;
		node->next = s->top;
		s->top = node;
	}
}

//print_stack
void print_stack(Stack* s) {
	if (is_empty(s)) {
		printf("Stack is empty!\n");
		return;
	}
	for (StackNode* p = s->top; p != NULL; p = p->next) {
		printf("%d -> ", p->data);
	}
	printf("NULL\n");
}

int search(Stack* s, element e) {
	for (StackNode* p = s->top; p != NULL; p = p->next) {
		if (e == p->data) {
			printf("Element %d exists!\n",e);
			return 1;
		}
	}
	printf("Element %d doesn't exist!\n",e);
	return 0;

}

void test_stack() {
	Stack* s = initStack();
	push(s, 1);
	push(s, 2);
	push(s, 5);

	print_stack(s);
	search(s, 3);
	search(s, 5);

	pop(s);
	pop(s);
	print_stack(s);
	search(s, 5);

}