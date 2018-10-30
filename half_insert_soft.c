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
	int high, low, mid;

	for (i = 1; i < n; i++) {
		if (val[i] < val[i - 1]) {
			temp = val[i];
			high = i - 1;
			low = 0;
			mid = (high - low) / 2;
			while (low <= high) {
				if (val[mid] > temp) {
					high = mid - 1;
				} else {
					low = mid + 1;
				}
				mid = (high - low) / 2 + low;
			}
			for (j = i; j > low; j--) {
				val[j] = val[j - 1];
			}

			val[low] = temp;
		}

		print_sort(val, n);
	}

}

int main(int argc, void *argv[])
{
	int a[] = {3,1,7,5,2,4,9,6};

	sort(a, 8);
}
