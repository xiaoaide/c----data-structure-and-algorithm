#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

struct table {
	int *key;
	int len;
};

static void creat_table(struct table *tb, int len)
{
	int i;

	tb->key = (int *)malloc(sizeof(int) * (len + 1));
	if (!tb->key) {
		printf("malloc failed\n");
		return;
	}	

	tb->len = len;
	for (i = 0; i < len; i++) {
		tb->key[i] = i;
	}

}

static int search(struct table *tb, int key)
{
	int i;

	i = 0;
	tb->key[tb->len] = key;
	while (tb->key[i] != key) {
		i++;
	}

	if (i == tb->len) {
		printf("search failed\n");
		return -1;
	}
	
	printf("search success\n");
	return i;
}

static int search_lianxi1(int a[], int n, int data)
{
	int i;

	a[n - 1] = data;
	i = 0;
	while (a[i] != data)
		i++;
	if (i == n - 1) {
		printf("search failed\n");
		return -1;
	} else {
		printf("search success\n");
		return i;
	}
}

int main(int argc, void *argv[])
{
	struct table tb;
	int position;
	int a[9] = {49,38,65,97,76,13,27,49};

	creat_table(&tb, 10);
	position = search(&tb, 5);
	printf("the position is %d\n", position);

	position = search_lianxi1(a, 9, 65);
	printf("the position is %d\n", position);
	
}
