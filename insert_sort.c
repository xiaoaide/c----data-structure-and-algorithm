#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

static void print_sort(int val[], int n)
{
	int i;

	for (i = 0; i < n; i++) {
		printf("%d",val[i]);
	}
	printf("\n");
}

static void sort(int val[], int n)
{
	int i;
	int temp;
	int j;

	for (i = 1; i < n; i++) {
		if (val[i] < val[i - 1]) {
			temp = val[i];
			j = i - 1;
			while (j >= 0 && val[j] > temp) {
				val[j + 1] = val[j];
				j--;
			}
			val[j + 1] = temp;
		}

		print_sort(val, n);
	}

}

int main(int argc, void *argv[])
{
	int a[] = {3,1,7,5,2,4,9,6};

	sort(a, 8);
}
