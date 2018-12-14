#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

static int match(char *s, char *t) 
{
	int i, j;
	int lens, lent;

	lens = strlen(s);
	lent = strlen(t);

	if (lent > lens) {
		printf("the string not match\n");
		return -1;
	}

	for (i = 0; i <= (lens - lent); i++) {
		for (j = 0; j < lent; j++) {
			if (t[j] != s[i + j]) {
				break;
			}
		}	
		if (j == lent) {
			printf("the string match\n");
			return i + 1;
		}
	}

	printf("the string not match\n");
	
	return -1;
}

static int match_lianxi(char *s, char *t)
{
	int count = 0;
	int i, j, k, lens, lent;

	if (s == NULL || t == NULL)
		return -1;

	lens = strlen(s); 
	lent = strlen(t); 

	for (i = 0; i < lens; i++) {
		k = i;
		for (j = 0; j < lent; j++) {
			if (s[k] != t[j])	
				break;
			k++;
		}
		if (j == lent)
			count++;
	}

	return count;
}

int main (int argc, char *argv[])
{
	char *a = "ababcabcacbabcbab";
	char *b = "cbab";
	int position;

	position = match(a, b);
	if (position != -1) {
		printf("the position is %d\n", position);
	}

	printf("the match count is %d\n", match_lianxi(a, b));
	

	return 0;
}
