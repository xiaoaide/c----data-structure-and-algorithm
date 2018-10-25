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
	head->data = 1;
	head->next = NULL;
	head->preve = NULL;
	
	frontnode = head;
	for (i = 1; i < num; i++) {
		node = (struct link *)malloc(sizeof(struct link));
		if (!node) {
			printf("malloc failed\n");
			return NULL;
		}
		node->data = i + 1;
		node->preve = frontnode;
		node->next = NULL;

		frontnode->next = node;
		frontnode = node;
	}

	frontnode->next = head;
	head->preve = frontnode;

	return head;
} 

static void findandkillk(struct link *head, int k, int m)
{
	struct link *node, *kill, *frontkill, *backkill;
	int i;

	node = head;
	while (node->data != k) {
		node = node->next;
	}

	while (node->next != node) {
		kill = node;
		for (i = 1; i < m; i++) {
			kill = kill->next;	
		}		
		printf("kill num is %d\n", kill->data);
		frontkill = kill->preve;
		backkill = kill->next;

		backkill->preve = frontkill;
		frontkill->next = backkill;
		free(kill);

		node = backkill;
	
		if (node->next == node)
			break;

		kill = node;
		for (i = 1; i < m; i++) {
			kill = kill->preve;
		}
		printf("kill num is %d\n", kill->data);
		frontkill = kill->preve;
		backkill = kill->next;

		backkill->preve = frontkill;
		frontkill->next = backkill;
		free(kill);

		node = frontkill;
	}

	printf("the reset num is %d\n", node->data);
	
	
}


int main (int argc, char *argv[])
{
	struct link *head;
	
	head = initlinktable(5);
	findandkillk(head, 3, 2);
	
	return 0;
}
