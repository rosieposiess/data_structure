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

			else if (term->degree == p->degree) { //������ ���� ���
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

Polynomial* add_poly(Polynomial* poly1, Polynomial* poly2, Polynomial* result) {
	polyTerm* p1 = poly1->head;
	polyTerm* p2 = poly2->head;

	while (p1 && p2) { // �� ���׽Ŀ� ��� ���� �����ִ� ����

		if (p1->degree > p2->degree) {
			insert(result, p1->coef, p1->degree);
			p1 = p1->link;
		}
		else if (p1->degree < p2->degree) {
			insert(result, p2->coef, p2->degree);
			p2 = p2->link;
		}
		else if (p1->degree == p2->degree) { // �� ���� ����
			insert(result, p1->coef + p2->coef, p1->degree);
			p1 = p1->link;
			p2 = p2->link;
		}
	}

	while (p1) { //���� p1�� ���� ����������
		insert(result, p1->coef, p1->degree);
		p1 = p1->link;
	}
	while (p2) { //���� p2�� ���� ����������
		insert(result, p2->coef, p2->degree);
		p2 = p2->link;
	}
	return result;
}

void polyPrint(Polynomial* poly) {
	for (polyTerm* p = poly->head; p != poly->last; p = p->link) {
		printf("%dx^%d + ", p->coef, p->degree);
	}
	if (poly->last->degree == 0) {
		printf("%d (size:%d)\n", poly->last->coef, poly->size);
	}
	else printf("%dx^%d (size:%d)\n", poly->last->coef, poly->last->degree, poly->size);

}

void poly_test() {
	Polynomial *p1 = create();
	Polynomial *p2 = create();
	Polynomial *p3 = create();

	//ù��° ���׽�
	insert(p1, 4, 8);
	insert(p1, 1, 0);
	insert(p1, 4, 1);

	//�ι�° ���׽�
	insert(p2, 3, 6);
	insert(p2, 1, 9);
	insert(p2, 4, 9);

	printf("p1:");
	polyPrint(p1);
	printf("p2:");
	polyPrint(p2);

	add_poly(p1, p2, p3);
	printf("sum:");
	polyPrint(p3);
}