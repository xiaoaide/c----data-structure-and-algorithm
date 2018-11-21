#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

static int max_child(char *s)
{
	int max_len;
	int child_len;
	int slen;
	int i, j, k;

	slen = strlen(s);
	printf("the slen is %d\n", slen);

	max_len = 0;
	for (i = 0; i < slen; i++) {
		child_len = 1;
		for (j = i + 1; j < slen; j++) {
			k = j - 1;
			while (k >= i) {
				if (s[k] == s[j]) {
					break;
				}
				k--;
			}
			if (k >= i) {
				break;	
			}
			child_len++;
		}

		if (child_len > max_len)
			max_len = child_len;
	}

	return max_len;
}



int main(int atgc, void *argv[])
{
	char *s = "abcabcbb";

	printf("max child len is %d\n", max_child(s));
}
