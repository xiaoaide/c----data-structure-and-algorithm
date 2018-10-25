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
	while (tb->mid != tb->low) {
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

int main(int argc, void *argv[])
{
	struct table tb;
	int position;

	creat(&tb, 30);
	position = search(&tb, 10);
	printf("the position is %d\n", position);
}
