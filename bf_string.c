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

int main (int argc, char *argv[])
{
	char *a = "ababcabcacbab";
	char *b = "cbab";
	int position;

	position = match(a, b);
	if (position != -1) {
		printf("the position is %d\n", position);
	}
	

	return 0;
}
