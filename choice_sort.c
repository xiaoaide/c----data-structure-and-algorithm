#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

static void choice_sort(int a[], int len)
{
	int min;
	int i, j, minj, temp;

	for (i = 0; i < len - 1; i++) {
		j = i;
		min = a[j];
		minj = j;
		j++;
		while (j < len) {
			if (a[j] < min) {
				min = a[j];
				minj = j;
			}			
			j++;
		}
		if (i != minj) {
			temp = a[i];
			a[i] = a[minj];
			a[minj] = temp;
		}
	}
	
}

static void choice_sort_lianxi1(int a[], int n)
{
	int i, j;
	int min, minj;
	int temp;

	for (i = 0; i < n - 1; i++) {
		min = a[i];
		minj = i;
		for (j = i + 1; j < n; j++) {
			if (a[j] < min) {
				min = a[j];
				minj = j;
			}
		}
		temp = a[i];
		a[i] = min;
		a[minj] = temp;
	}
}


int main(int atgc, void *argv[])
{
	int a[5] = {56, 12, 80, 91, 20};
	int i;

	choice_sort_lianxi1(a, 5);

	for (i = 0; i < 5; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
