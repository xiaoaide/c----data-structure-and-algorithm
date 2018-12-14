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

static int palindrome_string_lianxi(char *s)
{
	char *str;
	char *end;

	str = s;
	end = s;
	while (*end != '\0')
		end++;
	end--;

	while (str < end) {
		if (*str != *end)
			return 0;
		str++;
		end--;
	}

	return 1;
}


int main(int atgc, void *argv[])
{
	char *s = "abccdcba";

	printf("the string is palindrome %d\n", palindrome_string_lianxi(s));
}
