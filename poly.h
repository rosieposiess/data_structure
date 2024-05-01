#ifndef _POLY_H_
#define _POLY_H_

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

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
Polynomial* insert(Polynomial* poly, int coef, int degree);
Polynomial* add_poly(Polynomial* poly1, Polynomial* poly2, Polynomial* result);
void error_print(const char* message);
void polyPrint(Polynomial* poly);
void poly_test();

#endif // _POLY_H_
