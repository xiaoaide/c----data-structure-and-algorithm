#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

struct bucket {
	int val[10];
	int count;
};

static void put_bucket(struct bucket *bucks, int data)
{
	int index;
	int position;


	index = data / 10;
	bucks[index].count++;
	position = bucks[index].count - 1;
	bucks[index].val[position] = data;
}

static void bubble_sort(int a[], int n)
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

static void sort_bucket(struct bucket *buck)
{
	if (buck->count == 0)
		return;

	bubble_sort(buck->val, buck->count);
}

static void out_bucket(struct bucket *bucks, int a[])
{
	int i, j, k;

	j = 0;
	for (i = 0; i < 10;  i++) {
		if (bucks[i].count > 0) {
			for (k = 0; k < bucks[i].count; k++) {
				a[j] = bucks[i].val[k];
				j++;
			}		
		}
	}
}

static void bucket_sort(struct bucket *bucks, int a[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		put_bucket(bucks, a[i]);

	for (i = 0; i < 10; i++)
		sort_bucket(&bucks[i]);

	out_bucket(bucks, a);
}

static void print_sort(int val[], int n)
{
	int i;

	for (i = 0; i < n; i++) {
		printf("%d ",val[i]);
	}
	printf("\n");
}

int main(int atgc, void *argv[])
{
	int i;
	int a[8] = {49,38,65,97,76,13,27,49};
	struct bucket bucks[10];

	for (i = 0; i < 10; i++)
		bucks[i].count = 0;

	bucket_sort(bucks, a, 8);
	print_sort(a, 8);
	
}
