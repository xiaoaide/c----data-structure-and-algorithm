#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

struct link {
	int data;
	struct link *next;
	struct link *preve;
};

static struct link *initlinktable(int num)
{
	struct link *head;
	struct link *frontnode, *node;
	int i;

	head = (struct link *)malloc(sizeof(struct link));
	if (!head) {
		printf("malloc failed\n");
		return NULL;
	}
	head->data = 0;
	head->next = NULL;
	head->preve = NULL;
	
	frontnode = head;
	for (i = 0; i < num; i++) {
		node = (struct link *)malloc(sizeof(struct link));
		if (!node) {
			printf("malloc failed\n");
			return NULL;
		}
		node->data = i;
		node->preve = frontnode;
		node->next = NULL;

		frontnode->next = node;
		frontnode = node;
	}

	return head;
} 

static int insertelem(struct link *head, int position, int elem)
{
	struct link *node, *frontnode, *backnode;
	int i;

	node = (struct link *)malloc(sizeof(struct link));
	if (!node) {
		printf("malloc failed\n");
		return -1;
	}
	node->data = elem;
	node->preve = NULL;
	node->next = NULL;

	frontnode = head;
	for (i = 0; i < position; i++) {
		frontnode = frontnode->next;	
	}	
	backnode = frontnode->next;

	node->next = backnode;
	node->preve = frontnode;
	if (backnode)
		backnode->preve = node;
	frontnode->next = node;

	return 0;
}

static int delectlinktable(struct link *head, int position)
{
	struct link *node, *frontnode, *backnode;
	int i;

	node = head;
	for (i = 0; i < position; i++) {
		node = node->next;
	}
	
	frontnode = node->preve;
	backnode = node->next;
	
	backnode->preve = frontnode;
	frontnode->next = backnode;
} 
