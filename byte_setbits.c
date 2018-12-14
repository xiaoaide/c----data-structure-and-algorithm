#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

static int count_setbits(char a)
{
	int cout = 0;
	int i;

	for (i = 0; i < 8; i++) {
		if (a & (1 << i)) {
			cout++;
		}
	}

	return cout;
}

static int count_setbits_lianxi(char val)
{
	int cout = 0;
	int i;

	for (i = 0; i < 8; i++) {
		if (0x1 << i & val)
			cout++;
	}

	return cout;
}

int main(int atgc, void *argv[])
{
	int a;

	a = 0x7;
	printf("setbits is %d\n", count_setbits_lianxi(a));
}
