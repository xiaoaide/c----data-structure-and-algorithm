#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void  func(int n)
{
	int c;

	if (n / 10 != 0) {
		func(n / 10);
	}

	printf("%d", n % 10);
}


int main(void *argc, void *argv[])
{
	func(9988877);
	printf("\n");
}
