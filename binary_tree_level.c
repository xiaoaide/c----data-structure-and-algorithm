#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define LENGTH 20

struct node {
	int data;
	struct node *lchild;
	struct node *rchild;
};

struct queue {
	struct node *qu[LENGTH];
	int front;
	int rear;
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

static void input_queue(struct queue *qu, struct node *nd)
{
	int position;

	position = (qu->rear + 1) % LENGTH;
	if (position == qu->front) {
		printf("the queue is full\n");
		return;
	}

	qu->rear = position;
	qu->qu[position] = nd; 
}

static struct node * output_queue(struct queue *qu)
{
	struct node *nd;
	int position;

	if (qu->rear == qu->front) {
		printf("the queue is empty\n");
		return NULL;
	}
	
	position = (qu->front + 1) % LENGTH;
	nd = qu->qu[position];

	qu->front = position;

	return nd;
	
}

static void level_traversal(struct queue *qu, struct node *tree)
{
	struct node *nd;

	nd = tree;
	input_queue(qu, nd);

	while (nd = output_queue(qu)) {
		printf("%d ", nd->data);
		if (nd->lchild != NULL) 
			input_queue(qu, nd->lchild);
		if (nd->rchild != NULL) 
			input_queue(qu, nd->rchild);
	}
} 


int main(int argc, void *argv[])
{
	struct node *tree;
	struct queue qu;

	tree = creat_tree();
	
	qu.front = 0;
	qu.rear = 0;

	printf("level_traversal:\n");
	level_traversal(&qu, tree);
	printf("\n");
}
