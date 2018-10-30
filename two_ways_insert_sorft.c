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

static void sort(int val[], int temp[], int n)
{
	int min, max;
	int i, j, k;

	min = 0;
	max = 0;
	temp[0] = val[0];

	for (i = 1; i < n; i++) {
		if (val[i] < temp[min]) {
			min = min - 1 + n;
			temp[min] = val[i];
		} else if (val[i] > temp[max]) {
			max = max + 1;
			temp[max] = val[i];
		} else {
			for (j = max + n - 1; j >= min; j--) {
				if (temp[j % n] < val[i]) {
					k = j + 1;
					break;
				}
			}	

			for (j = max + n; j >= k; j--) {
				temp[(j + 1) % n] = temp[j % n];
			}

			temp[k % n] = val[i];
			max += 1;
		}
	}

	for (i = min, j = 0; i <= (max + n); i++, j++) {
		val[j] = temp[i % n];
	}
}

int main(int argc, void *argv[])
{
	int a[] = {3,1,7,5,2,4,9,6};
	int temp[8];

	sort(a, temp, 8);
	print_sort(a, 8);
}
