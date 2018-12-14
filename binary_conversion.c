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

static char *binary_conversion(char *s, int binary, int to_binary)
{
	int val = 0;
	char *s1;
	char temp;
	struct stack st;
	int i = 0;

	if (s == NULL)
		return NULL;

	st.top = -1;

	s1 = (char *)malloc(sizeof(char) * 100);
	if (!s1)
		return NULL;

	while (*s != '\0') {
		val = val * binary + (*s - 0x30);
		s++;
	}

	while (val / to_binary) {
		temp = val % to_binary + 0x30;
		push_stack(&st, temp);	
		val /= to_binary;
	}	
	temp = val + 0x30;
	push_stack(&st, temp);	

	while (st.top != -1) {
		temp = pop_stack(&st);
		s1[i] = temp;
		i++;	
	}
	s1[i] = '\0';

	return s1;
}

static void reverse_string(char *s)
{
	char *str;
	char *end;
	char temp;

	str = s;
	end = s;
	while (*end != '\0')
		end++;
	end--;

	while (str < end) {
		temp = *str;
		*str = *end;
		*end = temp;
		str++;
		end--;
	}
}

static char *binary_conversion_lianxi(char *s, int binary, int to_binary)
{
	int val = 0;
	char *s1;
	char temp;
	int i = 0;

	if (s == NULL)
		return NULL;

	s1 = (char *)malloc(sizeof(char) * 100);
	if (!s1)
		return NULL;

	while (*s != '\0') {
		val = val * binary + (*s - 0x30);
		s++;
	}

	while (val / to_binary) {
		temp = val % to_binary + 0x30;
		s1[i] = temp;
		i++;
		val /= to_binary;
	}	
	temp = val + 0x30;
	s1[i] = temp;
	s1[++i] = '\0';

	reverse_string(s1);
	return s1;
}

int main(int argc, void *argv)
{
	char s[] = "13";

	printf("%s\n", binary_conversion_lianxi(s, 10, 2));
}
