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

void error_print(const char* message);
void polyPrint(Polynomial* poly);
Polynomial* create();
Polynomial* insert(Polynomial* poly, int coef, int degree);
void poly_test();

#endif // _POLY_H_
