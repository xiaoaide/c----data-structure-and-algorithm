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

static void sort_lianxi1(int val[], int n)
{
	int i, j;
	int temp;

	for (i = 1; i < n; i++) {
		if (val[i] < val[i - 1]) {
			temp = val[i];	
			j = i - 1;
			while (j >= 0 && temp < val[j]) {
				val[j + 1] = val[j];
				j--;
			}
			if (j < 0) {
				val[0] = temp;	
			} else {
				val[j + 1] = temp;
			}
		}
	}
}

int main(int argc, void *argv[])
{
	int a[] = {3,1,7,5,2,4,9,6};

	sort_lianxi1(a, 8);
	print_sort(a, 8);
}
