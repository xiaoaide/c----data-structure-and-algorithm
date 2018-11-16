#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

struct node {
	int data;
	struct node *lchild;
	struct node *rchild;
};

static struct node * creat_tree(void)
{
	struct node *tree;

	tree = (struct node *)malloc(sizeof(struct node));
	if (!tree) {
		printf("malloc failed\n");
		return NULL;
	}
	tree->data = 1;
	tree->lchild = (struct node *)malloc(sizeof(struct node));
	tree->rchild = (struct node *)malloc(sizeof(struct node));

	tree->lchild->data = 2;
	tree->lchild->lchild = (struct node *)malloc(sizeof(struct node));
	tree->lchild->rchild = (struct node *)malloc(sizeof(struct node));

	tree->rchild->data = 3;
	tree->rchild->lchild = (struct node *)malloc(sizeof(struct node));
	tree->rchild->rchild = (struct node *)malloc(sizeof(struct node));

	tree->lchild->lchild->data = 4;
	tree->lchild->lchild->lchild = NULL; 
	tree->lchild->lchild->rchild = NULL; 

	tree->lchild->rchild->data = 5;
	tree->lchild->rchild->lchild = NULL; 
	tree->lchild->rchild->rchild = NULL; 

	tree->rchild->lchild->data = 6;
	tree->rchild->lchild->lchild = NULL; 
	tree->rchild->lchild->rchild = NULL; 

	tree->rchild->rchild->data = 7;
	tree->rchild->rchild->lchild = NULL; 
	tree->rchild->rchild->rchild = NULL; 

	return tree;
}

static void first_traversal(struct node *tree)
{
	if (tree) {
		printf("%d ", tree->data);
		first_traversal(tree->lchild);
		first_traversal(tree->rchild);
	}
}

static void middle_traversal(struct node *tree)
{
	if (tree) {
		middle_traversal(tree->lchild);
		printf("%d ", tree->data);
		middle_traversal(tree->rchild);
	}
}

static void post_traversal(struct node *tree)
{
	if (tree) {
		post_traversal(tree->lchild);
		post_traversal(tree->rchild);
		printf("%d ", tree->data);
	}
}

int main(int argc, void *argv[])
{
	struct node *tree;

	tree = creat_tree();

	printf("first_traversal:\n");
	first_traversal(tree);
	printf("\n");

	printf("middle_traversal:\n");
	middle_traversal(tree);
	printf("\n");

	printf("post_traversal:\n");
	post_traversal(tree);
	printf("\n");
}
