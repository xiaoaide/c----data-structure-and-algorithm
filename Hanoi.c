#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

static void hanoi(int num, char a, char b, char c)
{
	if (num == 1) {
		printf("from %c to %c\n", a, c);
	} else {
		hanoi(num - 1, a, c, b);
		printf("from %c to %c\n", a, c);
		hanoi(num - 1, b, a, c);
	}
}


int main(int atgc, void *argv[])
{
	char a = 'a';
	char b = 'b';
	char c = 'c';

	hanoi(3, a, b, c);
}
