#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

static void creat_head_lianxi(int a[], int s, int n)
{
	int i;
	int temp;
	int child;

	temp = a[s];
	for (i = s; 2 * i + 1 < n; i = child) {
		child = 2 * i + 1;
		if (2 * i + 2 < n) {
			if (a[2 * i + 1] < a[2 * i + 2]) {
				child = 2 * i + 2;
			}
		}
		if (a[i] < a[child]) {
			a[i] = a[child];
			a[child] = temp;
			temp = a[child];
		} else {
			break;
		}
	}
}

static void head_sort_lianxi(int a[], int n)
{
	int i;
	int temp;
	
	for (i = n / 2 - 1; i >= 0; i--) {
		creat_head_lianxi(a, i, n);
	}

	temp = a[0];
	a[0] = a[n - 1];
	a[n - 1] = temp;
	for (i = 0; i < n - 2; i++) {
		creat_head_lianxi(a, 0, n - 1 - i);
		temp = a[0];
		a[0] = a[n - 2 - i];
		a[n - 2 - i] = temp;
	}
}

int main(int atgc, void *argv[])
{
	int arr[10]={2,87,39,49,34,34,53,6,44,98};
	int i;
	
	head_sort_lianxi(arr, 10);
	for (i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
