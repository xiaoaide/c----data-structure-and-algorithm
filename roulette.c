#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <time.h> 

struct list {
	int data;
	struct list *next;
};

static struct list *inittable(int num)
{
	struct list *head, *frontnode, *node;
	int i;

	head = (struct list *)malloc(sizeof(struct list));
	if (!head) {
		printf("%s:malloc faild\n", __func__);
		return NULL;
	}
	head->data = 1;
	head->next = NULL;

	frontnode = head;
	for (i = 1; i < num; i++) {
		node = (struct list *)malloc(sizeof(struct list));
		if (!node) {
			printf("%s:malloc faild\n", __func__);
			return NULL;
		}
		node->data = i + 1;
		node->next = NULL;
		
		frontnode->next = node;
		frontnode = node;
	}

	frontnode->next = head;

	return head;
}

static int selectlist(struct list *head, int position)
{
	struct list *node;
	int i;

	node = head;
	for (i = 1; i < position; i++)
		node = node->next;	

	return node->data;

}

static struct list *delectelem(struct list *head, int position)
{
	struct list *node, *frontnode;
	int i;

	if (position == 1) {
		frontnode = head;
		while(frontnode->next != head) {
			frontnode = frontnode->next;
		}

	} else {
		frontnode = head;
		for (i = 1; i < (position - 1); i++) {
			frontnode = frontnode->next;	
		}
	}

	node = frontnode->next;

	frontnode->next = node->next;
	free(node);
	
	return frontnode->next; 
}


int main (int argc, char *argv[])
{
	struct list *head, *p;
	int i, randval;

	head = inittable(5);

	srand((unsigned int)time(NULL));

	for (i = 0; i < 4; i++) {
		randval = rand() % 5 + 1;
		printf("the %i kill %d data is %d \n", i, randval, selectlist(head, randval));
		head = delectelem(head, randval);
	}

	printf("the reset num is %d\n", head->data);
}
