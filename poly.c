//다항식 덧셈을 simple linked list로 구현
#include "poly.h"

Polynomial* create() {
	Polynomial* poly = (Polynomial*)malloc(sizeof(Polynomial));
	poly->head = NULL;
	poly->last = NULL;
	poly->size = 0;
	return poly;
}

void* clear(Polynomial* poly) {
	polyTerm* p = poly->head;
	polyTerm* q = NULL;
	
	for (; p != NULL; p = q) {
		q = p->link;
		free(p);
	}
	free(q);
}

//내림차순으로 insert
Polynomial*insert(Polynomial*poly, int coef, int degree){
	
	if (coef == 0) { return; }

	polyTerm* term = (polyTerm*)malloc(sizeof(polyTerm));
	term->coef = coef;
	term->degree = degree;
	term->link = NULL;

	if(poly->size==0){ //아직 아무 항도 없는 경우
		poly->head = term;
		poly->last = term;
		(poly->size)++;
		return poly;
	}

	else { //최소 한개 이상의 항이 이미 존재하는 경우

		if ((term->degree) > poly->head->degree) { //최고차항의 차수보다 term의 차수가 더 큰 경우
			term->link = poly->head;
			poly->head = term;
			(poly->size)++;
			return poly;
		}

		polyTerm* p = poly->head;
		polyTerm* q = (polyTerm*)malloc(sizeof(polyTerm)); //p의 이전 노드 저장
		q->link = p; 

		for (; p != NULL; p = p->link, q=q->link) { //새 항이 들어갈 위치를 찾음
			if ((term->degree) > (p->degree)) { //차수가 p->degree보다 처음으로 큰 경우 바로 전에 삽입
				term->link = p;
				q->link = term;
				(poly->size)++;
				return poly;
			}

			else if (term->degree == p->degree) { //차수가 같은 경우
				p->coef += (term->coef);
				free(term);
				return poly;
			}

			if (p == poly->last) { //맨 마지막 항까지 왔는데 맨 마지막 항보다 차수가 낮은 경우 => 맨 뒤에 삽입
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

	while (p1 && p2) { // 두 다항식에 모두 항이 남아있는 동안

		if (p1->degree > p2->degree) {
			insert(result, p1->coef, p1->degree);
			p1 = p1->link;
		}
		else if (p1->degree < p2->degree) {
			insert(result, p2->coef, p2->degree);
			p2 = p2->link;
		}
		else if (p1->degree == p2->degree) { // 두 차수 동일
			insert(result, p1->coef + p2->coef, p1->degree);
			p1 = p1->link;
			p2 = p2->link;
		}
	}

	while (p1) { //아직 p1의 항이 남아있으면
		insert(result, p1->coef, p1->degree);
		p1 = p1->link;
	}
	while (p2) { //아직 p2의 항이 남아있으면
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


Polynomial* product_poly(Polynomial* poly1, Polynomial* poly2, Polynomial* result) {
	for (polyTerm* p = poly1->head; p != NULL; p = p->link) {
		for (polyTerm* q = poly2->head; q != NULL; q = q->link) {
			insert(result, p->coef * q->coef, p->degree + q->degree);
		}
	}
	return result;
}

Polynomial* diff_poly(Polynomial* poly, Polynomial* result) {
	for (polyTerm* p = poly->head; p != NULL; p = p->link) {
		if (p->degree == 0) return result;
		else insert(result, p->coef * p->degree, p->degree - 1);
	}
	return result;
}


void poly_test() {
	Polynomial *p1 = create(); //p1:4x ^ 8 + 4x ^ 1 + 1 (size : 3)
	Polynomial *p2 = create(); //p2 : 5x ^ 9 + 3x ^ 6 (size : 2)
	Polynomial *sum = create();
	Polynomial* product = create();
	Polynomial* diff = create();
	Polynomial* integral = create();


	//첫번째 다항식
	insert(p1, 4, 8);
	insert(p1, 1, 0);
	insert(p1, 4, 1);

	//두번째 다항식
	insert(p2, 3, 6);
	insert(p2, 1, 9);
	insert(p2, 4, 9);

	printf("p1:");
	polyPrint(p1);
	printf("p2:");
	polyPrint(p2);

	printf("============================\n");

	add_poly(p1, p2, sum);
	printf("sum of p1 & p2: ");
	polyPrint(sum);

	product_poly(p1, p2, product);
	printf("product of p1 & p2: ");
	polyPrint(product);


	diff_poly(p1,diff);
	printf("differential of p1: ");
	polyPrint(diff);

}