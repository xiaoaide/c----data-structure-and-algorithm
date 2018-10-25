#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

struct link {
	int data;
	struct link *next;
};

struct link *initlinktable(int num)
{
	struct link *head;
	struct link *temp, *node;
	int i;

	head = (struct link *)malloc(sizeof(struct link));
	head->data = 0;
	head->next = NULL;

	temp = head;
	for (i = 1; i < num; i++) {
		node = (struct link *)malloc(sizeof(struct link));
		node->data = i;
		node->next = NULL;
		temp->next = node;
		temp = node;
	}

	return head;
} 

int selectlinktable(struct link *head, int num)
{
	struct link *temp;
	int i = 0;
	
	temp = head;
	while (temp != NULL) {
		if (temp->data == num)
			return i;
		temp = temp->next;
		i++; 
	}

	return -1;
}

struct link *modifylinktable(struct link *head, int position, int data)
{
	struct link *node;
	int i;

	node = head;
	for (i = 0; i < position; i++) {
		node = node->next;
	}
	node->data = data;

	return node;
}

void insertelem(struct link *head, int num, struct link *node)
{
	struct link *temp, *temp1;
	int i;

	temp = head;
	for (i = 0; i < num; i++) {
		temp = temp->next;
	}
	temp1 = temp->next;

	node->next = temp1;
	temp->next = node;
}

struct link *delectlinktable(struct link *head, int position)
{
	struct link *node;
	struct link *frontnode;
	int i;
	
	frontnode = head;
	for (i = 0; i < (position - 1); i++) {
		frontnode = frontnode->next;
	}
	node = frontnode->next;
	frontnode->next = node->next;
	node->next = NULL;
	free(node);	
}

void displaylinktable(struct link *head)
{
	struct link *temp;
	int i = 0;

	temp = head;
	while (temp != NULL) {
		printf("the node %d val is %d\n", i, temp->data);
		i++;
		temp = temp->next;
	}
}

int main (int argc, char *argv[])
{
	struct link *head;
	struct link *node;
	int position;

	head = initlinktable(4);
	printf("the old table display:\n");
	displaylinktable(head);

	node = (struct link *)malloc(sizeof(struct link));
	if (!node) {
		printf("malloc failed\n");
		exit(-1);
	}
	node->data = 7;
	node->next = NULL;
	insertelem(head, 1, node);
	printf("the insertelem table display:\n");
	displaylinktable(head);

	delectlinktable(head, 3);
	printf("delectlinktable display:\n");
	displaylinktable(head);

	position = selectlinktable(head, 3);
	printf("the elem 3 position is %d\n", position);

	modifylinktable(head, 1, 8);
	printf("modifylinktable display:\n");
	displaylinktable(head);
	
	return 0;
}
