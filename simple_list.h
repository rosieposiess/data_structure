#pragma once

#include <stdio.h>
#include <malloc.h>

//단순 연결 리스트 구현
typedef int element;
typedef struct Node {
	element val;
	Node* next;
}Node;

Node* insert_first_simple(Node* head, element val);
Node* insert_simple(Node* head, Node* pre, element val);
Node* delete_first_simple(Node* head);
Node* del_simple(Node* head, Node* pre);
Node* search_simple_list(Node* head, element val);
Node* concat_simple_list(Node* head1, Node* head2);
void print_simple_list(Node* head);
