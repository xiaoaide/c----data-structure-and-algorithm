#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

struct list {
	int data;
	struct list *next;
};

struct listqune {
	struct list *head;
	struct list *front;
	struct list *tail;
};

static int init_listqune(struct listqune *quenu)
{
	quenu->head = (struct list *)malloc(sizeof(struct list));
	if (!quenu->head) {
		printf("the malloc faild\n");
		return -1;
	}
	quenu->front = quenu->tail = quenu->head;
	
	return 0;
}

static int input_quenu(struct listqune *quenu, int elem)
{
	struct list *node;

	node = (struct list *)malloc(sizeof(struct list));
	if (!node) {
		printf("the malloc faild\n");
		return -1;
	}
	node->data = elem;
	node->next = NULL;

	quenu->tail->next = node;
	quenu->tail = node;

	return 0;
}

static int outquenu(struct listqune *quenu)
{
	struct list *node;

	if (quenu->head->next == NULL) {
		printf("the quenu is null\n");
		return -1;
	}

	node = quenu->front->next;
	printf("out quenu vale is %d\n", node->data);
	quenu->front->next = node->next;

	if (quenu->front->next == NULL)
		quenu->tail = quenu->front;

	free(node);

	return 0;
}


int main (int argc, char *argv[])
{
	struct listqune quenu;

	init_listqune(&quenu);

	input_quenu(&quenu, 1);
	input_quenu(&quenu, 2);
	input_quenu(&quenu, 3);
	input_quenu(&quenu, 4);
	input_quenu(&quenu, 5);
	input_quenu(&quenu, 6);
	
	outquenu(&quenu);
	outquenu(&quenu);
	outquenu(&quenu);
	outquenu(&quenu);
	outquenu(&quenu);
	outquenu(&quenu);
	outquenu(&quenu);
	outquenu(&quenu);
	printf("\n");
	input_quenu(&quenu, 1);
	input_quenu(&quenu, 2);
	input_quenu(&quenu, 3);
	input_quenu(&quenu, 4);
	input_quenu(&quenu, 5);
	input_quenu(&quenu, 6);
	printf("\n");
	outquenu(&quenu);
	outquenu(&quenu);
	outquenu(&quenu);
	outquenu(&quenu);
	outquenu(&quenu);
	outquenu(&quenu);
	outquenu(&quenu);
	outquenu(&quenu);

	return 0;
}
