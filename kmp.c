#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

static void getnext(char *b, int next[])
{
	int len, i, j;

	len = strlen(b);
	next[0] = -1;

	for (i = 1; i < len; i++) {
		j = next[i - 1];
		while (b[i] != b[j + 1] && j >= 0) {
			j = next[j];
		}

		if (b[i] == b[j + 1]) {
			next[i] = j + 1;
		} else {
			next[i] = -1;
		}
	}
}

static void match(char *a, char *b, int next[])
{
	int len, i, j, lenb;

	len = strlen(a);
	lenb = strlen(b);
	j = 0;
	i = 0;

	while (i < len) {
		if (a[i] == b[j]) {
			j++;	
			i++;
			if (j == lenb) {
				printf("the a and b is matching, the matching position is %d\n", i - j + 1);
				j = 0;
			}
		} else {
			if (j == 0) {
				i++;
			} else 
				j = next[j - 1] + 1;
		}
	}
}

int main (int argc, char *argv[])
{
	char *a = "ababcabcacbab";
	char *b = "abcac";
	int *next;

	next = (int *)malloc(sizeof(int) * strlen(b));
	if (!next) {
		printf("the malloc failed\n");
	}

	getnext(b, next);
	match(a, b, next);

	return 0;
}
