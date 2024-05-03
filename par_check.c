#include "stack.h"

int check(Stack*stack, const char* s) {
	int i = 0;
	while (s[i] != NULL) {
		switch (s[i]) {
		case '[': case '{': case '(':
			push(stack, s[i]);
			break;
		case ']':
			if (pop(stack, s[i]) != '[') {
				return FALSE;
			};
			break;
		case '}':
			if (pop(stack, s[i]) != '{') {
				return FALSE;
			};
			break;
		case ')':
			if (pop(stack, s[i]) != '(') {
				return FALSE;
			};
			break;
		default: continue;
	}
		if (!is_empty(stack)) return FALSE;
		else return TRUE;
}