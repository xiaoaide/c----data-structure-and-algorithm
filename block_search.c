#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

struct index {
	int index;
	int max;
};

struct index_table {
	struct index *id;
	int len;
	int size;
};

static void creat_indextable(struct index_table *tb, int key[], int block, int size)
{
	int i, j, k, max, index;

	tb->id = (struct index *)malloc(sizeof(struct index) * block);
	if (!tb->id) {
		printf("malloc faild\n");
		return;
	}
	tb->len = block;
	tb->size = size;

	for (i = 0; i < block; i++) {
		tb->id[i].index = i * size;
	}
	
	for (i = 0; i < block; i++) {
		k = tb->id[i].index;
		max = key[k];
		for (j = 1; j < size; j++) {
			if (key[k + j] > max)
				max= key[k + j];	
		}
		tb->id[i].max = max;
	}

	for (i = 0; i < (tb->len - 1); i ++) {
		for (j = 0; j < (tb->len - i); j++) {
			if (tb->id[j].max > tb->id[j + 1].max) {
				max = tb->id[j + 1].max;	
				index = tb->id[j + 1].index;	
				tb->id[j + 1].max = tb->id[j].max;
				tb->id[j + 1].index = tb->id[j].index;
				tb->id[j].max = max;
				tb->id[j].index = index;
			}
		}
	}
	
}

static int search(struct index_table *tb, int key[], int find)
{
	int i, iblock;
	int j;

	for (i = 0; i < tb->len; i++) {
		if (find <= tb->id[i].max) {
			iblock = tb->id[i].index;		
			break;
		}
	}

	for (j = 0; j < tb->size; j++) {
		if (key[iblock + j] == find) {
			printf("search success\n");
			return iblock + j;
		}
	}

	printf("search failed\n");
	return -1;
	
}

int main(int argc, void *argv[])
{
	int key[18] = {33,42,44,38,24,48, 22,12,13,8,9,20,  60,58,74,49,86,53};
	struct index_table tb;
	int position;

	creat_indextable(&tb, key, 3, 6);
	position = search(&tb, key, 13);
	printf("the position is %d\n", position);

	
}
