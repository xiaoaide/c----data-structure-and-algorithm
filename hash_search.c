#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define NULL1 -1

#define HASH_LEN 7

struct hash_table {
	int *key;
	int len;
};

static void init_hashtable(struct hash_table *tb, int size)
{
	int i;

	tb->key = (int *)malloc(sizeof(int) * size);
	if (!tb->key) {
		printf("malloc failed\n");
		return;
	}
	tb->len = size;
	
	for (i = 0; i < size; i++) {
		tb->key[i] = NULL1;
	}
}

static void insert_hashtable(struct hash_table *tb, int data)
{
	int position;

	position = data % HASH_LEN;
	while (tb->key[position] != NULL1) {
		position += 1;
		position = position % HASH_LEN;
	}

	tb->key[position] = data;
}

static int search_hashtable(struct hash_table *tb, int data)
{
	int position;

	position = data % HASH_LEN;
	while (tb->key[position] != data) {
		if (tb->key[position] == NULL1) {
			printf("search_hashtable failed\n");
			return -1;
		}
		position += 1;
		position = position % HASH_LEN;
		if (position == data % HASH_LEN) {
			printf("search_hashtable failed\n");
			return -1;
		}
	}

	printf("search_hashtable success\n");
	return position;
}

int main(int argc, void *argv[])
{
	struct hash_table tb;
	int key[HASH_LEN] = {13,29,27,28,26,30,38};
	int i, position;

	init_hashtable(&tb, HASH_LEN);
	
	for (i = 0; i < HASH_LEN; i++) {
		insert_hashtable(&tb, key[i]);
	}

	position = search_hashtable(&tb, 29);
	printf("the position is %d\n", position);


}
