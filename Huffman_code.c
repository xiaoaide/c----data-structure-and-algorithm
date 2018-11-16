#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

struct node {
	int weight;
	int parent;
	int lchild;
	int rchild;
};

static void choice(struct node *huffman_tree, int len, int *position1, int *position2)
{
	int weight_min1;
	int weight_min2;
	int i;

	i = 0;
	while (huffman_tree[i].parent != -1) i++;

	weight_min1 = huffman_tree[i].weight;
	*position1 = i;

	i++;
	while (huffman_tree[i].parent != -1) i++;

	if (huffman_tree[i].weight < weight_min1) {
		weight_min2 = weight_min1;
		weight_min1 = huffman_tree[i].weight;	
		*position2 = *position1;
		*position1 = i;
	} else {
		weight_min2 = huffman_tree[i].weight;
		*position2 = i;
	}

	i++;
	for ( ; i < len; i++) {
		if (huffman_tree[i].parent != -1) 
			continue;
		if (huffman_tree[i].weight < weight_min1) {
			weight_min2 = weight_min1;
			weight_min1 = huffman_tree[i].weight;
			*position2 = *position1;
			*position1 = i;
		} else if (huffman_tree[i].weight > weight_min1 && huffman_tree[i].weight < weight_min2) {
			weight_min2 = huffman_tree[i].weight;
			*position2 = i;
		}
	}
}

static struct node * creat_huffmantree(int *weight, int n)
{
	int m;
	int i;
	struct node *huffman_tree;
	int position1, position2;
	
	m = 2 * n - 1;
	huffman_tree = (struct node *)malloc(m * sizeof(struct node));
	if (!huffman_tree) {
		printf("malloc failed\n");
		return NULL;
	}

	for (i = 0; i < n; i++) {
		huffman_tree[i].weight = weight[i];
		huffman_tree[i].parent = -1;
		huffman_tree[i].lchild = -1;
		huffman_tree[i].rchild = -1;
	}

	for ( ; i < m; i++) {
		huffman_tree[i].weight = 0;
		huffman_tree[i].parent = -1;
		huffman_tree[i].lchild = -1;
		huffman_tree[i].rchild = -1;
	}
	
	for (i = n; i < m; i++) {
		choice(huffman_tree, i, &position1, &position2);
		huffman_tree[i].weight = huffman_tree[position1].weight + huffman_tree[position2].weight;
		huffman_tree[i].lchild = position1;
		huffman_tree[i].rchild = position2;
		huffman_tree[position1].parent = i;
		huffman_tree[position2].parent = i;
	}	

	return huffman_tree;

}

static char **  huffman_coding(struct node *huffman_tree, int n)
{

	char *code;
	int i, position, pa, cl;
	char **huffman_code;
	
	huffman_code = (void *)malloc(n * sizeof(char *));
	if (!huffman_code) {
		printf("malloc failed\n");
		return NULL;
	}

	code = (char *)malloc(n * sizeof(char)); 
	if (!code) {
		printf("malloc failed\n");
		return NULL;
	}
	code[n - 1] = '\0';

	for (i = 0; i < n; i++) {
		position = n - 2;	
		pa = huffman_tree[i].parent;
		cl = i;
		while (pa != -1) {
			if (huffman_tree[pa].lchild == cl) {
				code[position] = '0';
			} else 
				code[position] = '1';
		
			cl = pa;
			pa = huffman_tree[pa].parent;
			position--;
		}	
		huffman_code[i] = (char *)malloc(sizeof(char) * (n - position));
		if (!huffman_code[i]) {
			printf("malloc failed\n");
			return NULL;
		}
		strcpy(huffman_code[i], &code[position + 1]);
	}

	free(code);

	return huffman_code;
}

int main(int argc, void *argv[])
{
	int w[5] = {2, 8, 7, 6, 5};
	struct node *huffman_tree;
	char **huffman_code;
	int i;

	huffman_tree = creat_huffmantree(w, 5);
	huffman_code = huffman_coding(huffman_tree, 5);
	
	printf("output the huffman_code:\n");
	for (i = 0; i < 5; i++) {
		printf("the %d huffman_code is %s\n", huffman_tree[i].weight, huffman_code[i]);	
	}
	
}
