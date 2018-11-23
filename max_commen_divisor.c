#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

static int max_commen_divisor(int a, int b)
{
	int c;

	if (c = a % b) {
		a = b;
		b = c;
		return	max_commen_divisor(a, b);
	} else {
		return b;
	}
}

int main(int atgc, void *argv[])
{
	int a= 319, b = 377;
	
	printf("a and b max commen divisor is %d\n", max_commen_divisor(a, b));
}
