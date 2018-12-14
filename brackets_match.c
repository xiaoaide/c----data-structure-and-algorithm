#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define  STACH_LEN 100

struct stack {
	char data[STACH_LEN];
	int top;
};

static void push_stack(struct stack *st, char data)
{
	int position;

	if (st->top + 1 >= STACH_LEN) {
		printf("the stack is full\n");
		return;
	}

	position = st->top + 1;
	st->data[position] = data;
	st->top = position;
}

static char pop_stack(struct stack *st)
{
	char data;

	if (st->top == -1) {
		printf("the stack is empty\n");
		return -1;
	}
	data = st->data[st->top];
	st->top--;
	return data;	
}	

static int brackets_match(char *s)
{
	struct stack st;
	char temp;

	st.top = -1;

	if (s == NULL)
		return -1;

	if (*s == '\0')
		return -1;

	while (*s != '\0') {
		if (*s == '{' || *s == '[') {
			push_stack(&st, *s);
		} else if (*s == '}') {
			temp = pop_stack(&st);	
			if (temp == -1) {
				printf("not match\n");
				return -1;
			}
			if (temp != '{') {
				printf("not match\n");
				return -1;
			} 
		} else if (*s == ']') {
			temp = pop_stack(&st);	
			if (temp == -1) {
				printf("not match\n");
				return -1;
			}
			if (temp != '[') {
				printf("not match\n");
				return -1;
			} 
		}
		s++;
	}

	if (st.top != -1) {
		printf("not match\n");
		return -1;
	}

	printf("match success\n");
	return 0;
}

int main(int argc, void *argv)
{
	char s[] = "{{"; 

	brackets_match(s);
}
