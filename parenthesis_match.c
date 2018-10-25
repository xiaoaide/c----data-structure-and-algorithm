#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define HAVE_LEFT 1

struct stack {
	char a[100];
	int top;
};

static int push(struct stack *table, char elem)
{
	table->top += 1;
	table->a[table->top] = elem;

	return table->top;
}

static char pop(struct stack *table)
{
	char vale;
	
	if (table->top == -1) {
		printf("the stack is null\n");
		return -1;
	}

	vale = table->a[table->top];	
	table->top -= 1;

	return vale;
}


int main (int argc, char *argv[])
{
	struct stack table;
	char string[100];
	int length, i;
	int leftcount = 0;
	char temp;

	table.top = -1;

	printf("please input the char:\n");
	scanf("%s", string);
	getchar();

	length = strlen(string);
	for (i = 0; i < length; i++) {
		if (string[i] == '{') {
			push(&table, string[i]);
			leftcount++;
		} else if (string[i] == '(') {
			push(&table, string[i]);
			leftcount++;
		} else if (string[i] == '}') {
			temp = pop(&table);	
			if (temp == '{') {
				leftcount--;
				continue;
			} else {
				leftcount = HAVE_LEFT;
				break;
			}
		} else if (string[i] == ')') {
			temp = pop(&table);	
			if (temp == '(') {
				leftcount--;
				continue;
			} else {
				leftcount = HAVE_LEFT;
				break;
			}
		}
	}

	if (leftcount) {
		printf("not match\n");
	} else {
		printf("match\n");
	}

	return 0;
}
