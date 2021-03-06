#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

static void print_sort(int val[], int n)
{
	int i;

	for (i = 0; i < n; i++) {
		printf("%d ",val[i]);
	}
	printf("\n");
}

static int partiton(int a[], int low, int high)
{
	int temp;
	
	temp = a[low];
	while (low < high) {
		while (a[high] >= temp && low < high) {
			high--;
		}
		a[low] = a[high];

		while (a[low] <= temp && low < high) {
			low++;
		}
		a[high] = a[low];
	}

	a[low] = temp;
	return low;
}

static void fast_sort(int a[], int low, int high)
{
	int position;

	if (low < high) { 
		position = partiton(a, low, high);	
		fast_sort(a, low, position - 1);
		fast_sort(a, position + 1, high);
	}
}

static int partiton_lianxi1(int a[], int low, int high)
{
	int temp;
	
	temp = a[low];
	while (low < high) {
		while (a[high] >= temp && low < high) {
			high--;
		}
		a[low] = a[high];

		while (a[low] <= temp && low < high) {
			low++;
		}
		a[high] = a[low];
	}

	a[low] = temp;
	return low;
}

static void fast_sort_lianxi1(int a[], int low, int high)
{
	int mid;

	if (low < high) {
		mid = partiton_lianxi1(a, low, high);
		fast_sort_lianxi1(a, low, mid - 1);
		fast_sort_lianxi1(a, mid + 1, high);		
	}
}

int main(int argc, void *argv[])
{
	int a[8] = {49, 38, 65, 97, 76, 13, 27, 49};

	print_sort(a, 8);
	fast_sort_lianxi1(a, 0, 7);
	print_sort(a, 8);
	fast_sort_lianxi1(a, 0, 7);
	print_sort(a, 8);
}
