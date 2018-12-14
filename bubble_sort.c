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

static void sort_up(int a[], int n)
{
	int i, j, temp;

	for (i = 0; i < (n - 1); i++) {
		for (j = 0; j < (n - i - 1); j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;	
			}
		}
	}
}

static void sort_down(int a[], int n)
{
	int i, j, temp;

	for (i = 0; i < (n - 1); i++) {
		for (j = 0; j < (n - i - 1); j++) {
			if (a[j] < a[j + 1]) {
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;	
			}
		}
	}
}
static void sort_up_lianxi1(int a[], int n)
{
	int i, j;
	int temp;

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}


int main (int argc, char *argv[])
{
	int a[8] = {49,38,65,97,76,13,27,49};

	sort_up(a, 8);
	print_sort(a, 8);
	sort_up_lianxi1(a, 8);
	print_sort(a, 8);
	sort_down(a, 8);
	print_sort(a, 8);
	
}
