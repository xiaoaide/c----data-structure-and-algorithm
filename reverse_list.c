#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

struct list {
	int data;
	struct list *next;
};

static void *initlist(int len)
{
	struct list *head;
	struct list *node;
	struct list *pre;
	int i;

	head = (struct list *)malloc(sizeof(struct list));
	if (!head) {
		printf("malloc list failed\n");
		return NULL;
	}

	head->data = 0;
	head->next = NULL;

	pre = head;
	for (i = 1; i < len; i++) {
		node = (struct list *)malloc(sizeof(struct list));
		if (!node) {
			printf("malloc list failed\n");
			return NULL;
		}
		node->data = i;
		node->next = NULL;
		pre->next = node;
		pre = node;
	}

	return head;
}

static struct list *reverse_list(struct list *lt)
{
	struct list *head;
	struct list *pre;
	struct list *next;

	pre = lt;
	head = lt;
	while (next = pre->next) {
		pre->next = next->next;
		next->next = head;
		head = next;
	}

	return head;
}

static void printf_list(struct list *lt)
{
	struct list *node;
	struct list *pre;

	node = lt;
	pre = lt;
	printf("%d ", node->data);
	while (node = pre->next) {
		printf("%d ", node->data);
		pre = node;
	}
	printf("\n");
}

int main(int argc, void *argv)
{
	struct list *lt;

	lt = initlist(10);
	printf_list(lt);
	lt = reverse_list(lt);
	printf_list(lt);
}
