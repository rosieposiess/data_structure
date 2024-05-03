#pragma once

#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef int element;

typedef struct StackNode {
	element data;
	struct StackNode* next;
}StackNode;

typedef struct Stack {
	struct StackNode* top;
}Stack;

void error(const char* message);
Stack* initStack();
int is_empty(Stack* s);
element pop(Stack* s);
void push(Stack* s, element e);
void print_stack(Stack* s);
void test_stack();
int search(Stack* s, element e);