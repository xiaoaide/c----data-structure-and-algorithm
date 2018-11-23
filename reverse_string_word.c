#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

static void reverse_word(char *s, char *e)
{
	char temp;

	while (s < e) {
		temp = *s;
		*s = *e;
		*e = temp;
		e--;
		s++;
	}
}

static void reverse_string(char *s)
{
	char *start = s;
	char *end = s;

	while (*end != '\0') {
		if (*end == ' ') {
			reverse_word(start, end - 1);
			end++;
			start = end;
		} else 
			end++;
	}

	reverse_word(start, end - 1);
	reverse_word(s, end - 1);
}

int main(int atgc, void *argv[])
{
	char s[] = "my name is qinyisong";

	reverse_string(s);
	printf("the s is %s\n", s);
}
