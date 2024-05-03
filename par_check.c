#include "stack.h"

int check_paren(Stack* stack, const char* s) {
	for(int i=0;s[i]!=NULL;i++){
		//printf("%c\n", s[i]);
		switch (s[i]) {
			case '[': case '{': case '(':
				push(stack, s[i]);
				break;
			case ']':
				if (pop(stack) != '[') {
					return FALSE;
				};
				break;
			case '}':
				if (pop(stack) != '{') {
					return FALSE;
				};
				break;
			case ')':
				if (pop(stack) != '(') {
					return FALSE;
				};
				break;
		}
		print_stack(stack);
	}
	if (!is_empty(stack)) return FALSE;
	else return TRUE;
}
void test_p() {
		Stack* s = initStack();
		char* str = "[{}[(){}]]";	
		int result=check_paren(s, str);
		if (result==1) {
			printf("good");
		}
		else printf("bad");
	}