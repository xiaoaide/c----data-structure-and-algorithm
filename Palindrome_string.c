#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

static int palindrome_string(char *s)
{
	char *start = s;

	while (*s != '\0')
		s++;
	s--;

	while (start < s) {
		if (*start != *s) {
			return 0;
		}
		start++;
		s--;
	}

	return 1;
}


int main(int atgc, void *argv[])
{
	char *s = "abccdcba";

	printf("the string is palindrome %d\n", palindrome_string(s));
}
