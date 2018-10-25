#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

struct list {
	int num;
	struct list *next;
};

static struct list *init_list(int num)
{
	struct list *head, *node, *frotnode;
	int i;

	head = (struct list *)malloc(sizeof(struct list));
	if (!head) {
		printf("malloc faild\n");
		return NULL;
	}
	head->num = 1;
	head->next = NULL;

	frotnode = head;
	for (i = 1; i < num; i++) {
		node = (struct list *)malloc(sizeof(struct list));
		if (!node) {
			printf("malloc faild\n");
			return NULL;
		}
		node->num = i + 1;
		node->next = NULL;

		frotnode->next = node;
		frotnode = node;
	}

	frotnode->next = head;

	return head;
}

static void findandkill_k(struct list *head, int k, int m)
{
	struct list *node, *kill, *frontkill;
	int i;
	
	node = head;
	while (node->num != k) {
		node = node->next;
	}

	while (node->next != node) {
		frontkill = node;
		for (i = 1; i < (m - 1); i++) {
			frontkill = frontkill->next;
		}	
		
		kill = frontkill->next;
		node = kill->next;
		printf("the kill num is %d\n", kill->num);
		frontkill->next = kill->next;	
		free(kill);
	}

	printf("the reset num is %d\n", node->num);
}

int main (int argc, char *argv[])
{
	struct list *head;
	
	head = init_list(5);
	findandkill_k(head, 3, 2);
	
	return 0;
}
