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

static void sort(int a[], int n)
{
	int gap;
	int i;
	int j;
	int temp;

	for (gap = n / 2; gap >= 1; gap = gap / 2) {
		for (i = gap; i < n; i++) {
			j = i;	
			while (a[j] < a[j - gap] && (j - gap) >= 0) {
				temp = a[j];
				a[j] = a[j - gap];
				a[j - gap] = temp;		
				j -= gap;
			}
		}
	}

}

static void sort1(int a[], int n)
{
	int gap;
	int i, j, temp;

	for (gap = n / 2; gap >= 1; gap = gap / 2) {
		for (i = gap; i < n; i++) {
			j = i;
			temp = a[j];
			while (temp < a[j - gap] && (j - gap) >= 0) {
				a[j] = a[j - gap];
				j -= gap;
			}	

			a[j] = temp;
		}	
	}
}

int main(int argc, void *argv[])
{
	int a[10] = {49, 38, 65, 97, 76, 13, 27, 49, 55, 4};

	sort(a, 10);
	print_sort(a, 10);
	sort1(a, 10);
	print_sort(a, 10);
}
