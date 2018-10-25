#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

struct result {
	int position[10];
	int count;
};

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

static void match(char *a, char *b, int next[], struct result *m_result)
{
	int len, lenb;
	int i = 0, j = 0, k = 0;

	len = strlen(a);
	lenb = strlen(b);

	while (i < len) {
		if (a[i] == b[j]) {
			j++;	
			i++;
			if (j == lenb) {
				m_result->position[k] = i - j + 1;
				printf("the a and b is matching, the matching position is %d\n", m_result->position[k]);
				k++;
				m_result->count++;
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

static int relpace(char *a, int position, char  *rep)
{
	int len, i;

	len = strlen(rep);
	for (i = 0; i < len; i++) {
		a[position - 1 + i] = rep[i];
	}
	printf("the new  a is %s\n", a);
}

int main (int argc, char *argv[])
{
	char a[30], b[10], rep[20];
	int *next;
	struct result m_result;
	int i;

	m_result.count = 0;

	printf("please input a string:\n");
	scanf("%s", a);
	getchar();

	printf("please input b string:\n");
	scanf("%s", b);
	getchar();

	printf("please input rep string:\n");
	scanf("%s", rep);
	getchar();

	next = (int *)malloc(sizeof(int) * strlen(b));
	if (!next) {
		printf("the malloc failed\n");
	}

	getnext(b, next);

	match(a, b, next, &m_result);

	for (i = 0; i < m_result.count; i++) {
		relpace(a, m_result.position[i], rep);
	}

	return 0;
}
