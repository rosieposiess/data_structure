#define _CRT_SECURE_NO_WARNINGS
#include "stack.h"

int check_paren(Stack* stack, const char* s) {
	for(int i=0;s[i]!=NULL;i++){
		switch (s[i]) {
			case '[': case '{': case '(':
				push(stack, s[i]);
				break;
			case ']':
				if ((is_empty(stack))||(pop(stack) != '[')){
					return FALSE;
				};
				break;
			case '}':
				if ((is_empty(stack))||(pop(stack) != '{')) {
					return FALSE;
				};
				break;
			case ')':
				if ((is_empty(stack)) || (pop(stack) != '(')) {
					return FALSE;
				};
				break;
			default:
				break;
		}
		print_stack(stack);
	}
	if (!is_empty(stack)) return FALSE;
	else return TRUE;
}

void test_p() {
		Stack* s = initStack();
		char str[100] = {0,};
		scanf("%s", str);
		int result=check_paren(s, str);
		if (result==1) {
			printf("good");
		}
		else printf("bad");
	}