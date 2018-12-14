#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

static int max_child(char *s1, char *s2)
{
	int len1, len2;
	int **c;
	int i, j;
	int max = 0;

	len1 = strlen(s1);
	len2 = strlen(s2);

	c = (void *)malloc(len1 * sizeof(void *));
	if (!c) {
		printf("malloc failed\n");
		return -1;
	}

	for (i = 0; i < len1; i++) {
		c[i] = (int *)malloc(len2 * sizeof(int));
		if (!c[i])
			return -1;
	}

	for (i = 0; i < len1; i++) {
		for (j = 0; j < len2; j++) {
			if (s1[i] == s2[j]) {
				if (i > 0 && j > 0) {
					c[i][j] = c[i - 1][j - 1] + 1;
					if (max < c[i][j])
						max = c[i][j];
				} else {
					c[i][j] = 1;
				}
			} else {
				c[i][j] = 0;
			}
		}
	}

	return max;

}

static int max_child_lianxi(char *s1, char *s2)
{
	int **arry;
	int len1, len2;
	int i, j;
	int max = 0;

	if (s1 == NULL || s2 == NULL)
		return -1;

	len1 = strlen(s1);
	len2 = strlen(s2);

	arry = (void *)malloc(sizeof(void *) * len1);
	if (!arry)
		return -1;

	for (i = 0; i < len1; i++) {
		arry[i] = (int *)malloc(sizeof(int) * len2);
		if (!arry[i])
			return -1;
	}

	for (i = 0; i < len1; i++) {
		for (j = 0; j < len2; j++) {
			if (s1[i] == s2[j]) {
				if (i == 0 || j == 0) {
					arry[i][j] = 1;
				} else {
					arry[i][j] = 1 + arry[i - 1][j - 1];
					if (arry[i][j] > max)
						max = arry[i][j];
				}
			} else {
				arry[i][j] = 0;
			}
		}
	}

	return max;
}

int main(int atgc, void *argv[])
{
	char *s1 = "abctdefg";
	char *s2 = "abctgdefg";

	printf("max commen child is %d\n", max_child_lianxi(s1, s2));
}
