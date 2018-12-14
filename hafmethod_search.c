#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

struct table {
	int *key;
	int len;
	int low;
	int high;
	int mid;
};

static void creat(struct table *tb, int len)
{
	int i;

	tb->key = (int *)malloc(sizeof(int) * len);
	if (!tb->key) {
		printf("malloc failed\n");
		return;
	}

	tb->len = len;
	tb->low = 0;
	tb->high = len - 1;
	tb->mid = (tb->high - tb->low) / 2;
	for (i = 0; i < len; i++) {
		tb->key[i] = i;
	}
}

static int search(struct table *tb, int key) 
{
	while (tb->low <= tb->high) {
		if (key > tb->key[tb->mid]) {
			tb->low = tb->mid + 1;
			tb->mid = (tb->high - tb->low) / 2 + tb->low;
		} else if (key < tb->key[tb->mid]) {
			tb->high = tb->mid - 1;
			tb->mid = (tb->high - tb->low) / 2 + tb->low;
		} else if (key == tb->key[tb->mid]) {
			printf("search success\n");	
			return tb->mid;
		}
	}

	printf("search failed\n");
	return -1;
}

static int search_lianxi(int a[], int n, int data)
{
	int i;
	int high, mid, low;

	high = n - 1;
	low = 0;
	mid = (high - low) / 2 + low;
	while (low <= high) {
		if (a[mid] == data) {
			printf("search success\n");
			return mid;
		} else if (a[mid] < data) {
			low = mid + 1;
			mid = (high - low) / 2 + low;
		} else if (a[mid] > data) {
			high = mid - 1;
			mid = (high - low) / 2 + low;
		}
	}

	printf("search failed\n");
	return -1;
}

int main(int argc, void *argv[])
{
	struct table tb;
	int position;
	int a[8] = {3, 5, 7, 8, 9, 10, 11, 13};

	creat(&tb, 30);
	position = search(&tb, 10);
	printf("the position is %d\n", position);

	position = search_lianxi(a, 8, 9);
	printf("the position is %d\n", position);
}
