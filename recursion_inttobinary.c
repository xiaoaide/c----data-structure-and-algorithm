#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void  func(int n)
{
	if (n / 2 != 0) {
		func(n / 2);
	}

	printf("%d", n % 2);
}


int main(void *argc, void *argv[])
{
	func(85);
	printf("\n");
}
