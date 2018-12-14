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

static void merge(int a[], int b[], int s, int m, int n)
{
	int j, k, i;
	
	i = s;
	j = m + 1;
	for (k = s; i <= m && j <= n; k++) {
		if (a[i] < a[j]) {
			b[k] = a[i];
			i++;
		} else {
			b[k] = a[j];
			j++;
		}
	}

	while (i <= m) {
		b[k] = a[i];
		k++;
		i++;
	}

	while (j <= n) {
		b[k] = a[j];
		k++;
		j++;
	}

}

static void merge_sort(int a[], int b[], int s, int t)
{
	int c[20];
	int m;

	if (s == t) {
		b[s] = a[t];
	} else {
		m = (s + t) / 2;
		merge_sort(a, c, s, m);
		merge_sort(a, c, m + 1, t);
		merge(c, b, s, m , t);
	}
}

static void merge_lianxi(int a[], int b[], int s, int m, int n)
{
	int i, j;
	int k;
	
	i = s;
	j = m + 1;
	k = s;
	while (i <= m && j <= n) {
		if (a[i] < a[j]) {
			b[k] = a[i];
			k++;
			i++;
		} else {
			b[k] = a[j];
			k++;
			j++;
		}
	}

	while (i <= m) {
		b[k] = a[i];
		i++;
		k++;
	}

	while (j <= n) {
		b[k] = a[j];
		j++;
		k++;
	}
}

static void merge_sort_lianxi(int a[], int b[], int s, int n)
{
	int m;
	int c[20];

	if (s == n) {
		b[s] = a[s];
	} else {
		m = (n - s) / 2 + s;
		merge_sort_lianxi(a, c, s, m);
		merge_sort_lianxi(a, c, m + 1, n);
		merge_lianxi(c, b, s, m, n);
	}
}

int main(int argc, void *argv[])
{
	int a[7] = {49, 38, 65, 97, 76, 13, 27};
	int b[7];

	print_sort(a, 7);
	merge_sort_lianxi(a, b, 0, 6);
	print_sort(b, 7);
	
}
