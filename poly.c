//���׽� ������ simple linked list�� ����
#include "poly.h"

void error_print(const char* message) {
	printf("%s\n", message);
	exit(1);
}

Polynomial* create() {
	Polynomial* poly = (Polynomial*)malloc(sizeof(Polynomial));
	poly->head = NULL;
	poly->last = NULL;
	poly->size = 0;
	return poly;
}

//������������ insert
Polynomial*insert(Polynomial*poly, int coef, int degree){
	polyTerm* term = (polyTerm*)malloc(sizeof(polyTerm));
	term->coef = coef;
	term->degree = degree;
	term->link = NULL;

	if(poly->size==0){ //���� �ƹ� �׵� ���� ���
		poly->head = term;
		poly->last = term;
		(poly->size)++;
		return poly;
	}

	else { //�ּ� �Ѱ� �̻��� ���� �̹� �����ϴ� ���

		if ((term->degree) > poly->head->degree) { //�ְ������� �������� term�� ������ �� ū ���
			term->link = poly->head;
			poly->head = term;
			(poly->size)++;
			return poly;
		}

		polyTerm* p = poly->head;
		polyTerm* q = (polyTerm*)malloc(sizeof(polyTerm)); //p�� ���� ��� ����
		q->link = p; 

		for (; p != NULL; p = p->link, q=q->link) { //�� ���� �� ��ġ�� ã��
			if ((term->degree) > (p->degree)) { //������ p->degree���� ó������ ū ��� �ٷ� ���� ����
				term->link = p;
				q->link = term;
				(poly->size)++;
				return poly;
			}

			if (term->degree == p->degree) { //������ ���� ���
				p->coef += (term->coef);
				free(term);
				return poly;
			}

			if (p == poly->last) { //�� ������ �ױ��� �Դµ� �� ������ �׺��� ������ ���� ��� => �� �ڿ� ����
				p->link = term;
				poly->last = term;
				(poly->size)++;
				return poly;
			}

		}
	}
}

void polyPrint(Polynomial* poly) {
	for (polyTerm* p = poly->head; p != poly->last; p = p->link) {
		printf("%dx^%d + ", p->coef, p->degree);
	}
	if (poly->last->degree == 0) {
		printf("%d (size:%d)\n", poly->last->coef,poly->size);
	}
	else printf("%dx^%d (size:%d)\n", poly->last->coef, poly->last->degree,poly->size);
	
}

void poly_test() {
	Polynomial *p1 = create();
	Polynomial *p2 = create();
	Polynomial *p3 = create();

	//ù��° ���׽�
	insert(p1, 3, 8);
	insert(p1, 1, 0);
	insert(p1, 4, 1);

	//�ι�° ���׽�
	insert(p2, 3, 6);
	insert(p2, 1, 9);
	insert(p2, 4, 9);

	polyPrint(p1);
	polyPrint(p2);
}