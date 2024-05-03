#ifndef _POLY_H_
#define _POLY_H_

#include <stdio.h>
#include <malloc.h>

typedef struct polyTerm {
	int coef;
	int degree;
	struct polyTerm* link;
}polyTerm;

typedef struct Polynomial {
	int size; //Ç× °³¼ö
	polyTerm* head;
	polyTerm* last;
}Polynomial;

Polynomial* create();
Polynomial* insert(Polynomial* poly, float coef, int degree);
Polynomial* add_poly(Polynomial* poly1, Polynomial* poly2, Polynomial* result);
Polynomial* product_poly(Polynomial* poly1, Polynomial* poly2, Polynomial* result);
Polynomial* diff_poly(Polynomial* poly, Polynomial* result);
void polyPrint(Polynomial* poly);
void poly_test();

#endif // _POLY_H_
