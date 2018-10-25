#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

struct staticlist {
	int data;
	int cur;
};

static int mallocarr(struct staticlist *head)
{
	int i;
	
	i = head[0].cur;
	if (i) {
		head[0].cur = head[i].cur;
		return i;
	}

	return 0;

}

static struct staticlist *init_staticlist(int num)
{
	struct staticlist *head;

	head = (struct staticlist *)malloc(num * sizeof(struct staticlist));
	if (!head) {
		printf("the malloc faild\n");
		return NULL;
	}

	return head;
}

static int set_staticlist(struct staticlist *head, int num)
{
	int i, list, frontlist, headcur;


	for (i = 0; i < num; i++) {
		head[i].cur = i + 1;
	}
	head[num - 1].cur = 0;

	headcur = mallocarr(head);
	head[headcur].data = 0;
	head[headcur].cur = 0;
	frontlist = headcur;
	for (i = 1; i < 4; i++) {
		list = mallocarr(head);
		head[list].data = i;
		head[list].cur = 0;
		head[frontlist].cur = list;
		frontlist = list;
	}

	return headcur;
}

static int selectlinktable(struct staticlist *head, int headcur, int elem)
{
	int cur;

	cur = headcur;
	while (cur) {
		if (head[cur].data == elem)
			return cur;
		cur = head[cur].cur;
	}

	return 0;
}

static void modifylinktable(struct staticlist *head, int headcur, int oldelem, int newelem)
{
	int position;

	position = selectlinktable(head, headcur, oldelem);
	head[position].data = newelem;
}

static int insertlinktable(struct staticlist *head, int headcur, int position, int elem)
{
	int node;
	int frontcur, backcur;
	int i;
	
	node = mallocarr(head);
	if (!node) {
		printf("mallocarr faild\n");
		return -1;
	}
	head[node].data = elem;
	head[node].cur = 0;
	
	frontcur = headcur;
	for (i = 0; i < position; i++) {
		frontcur = head[frontcur].cur;
	}
	backcur = head[frontcur].cur;

	head[node].cur = backcur;
	head[frontcur].cur = node;

	return node;
}	

static int freearr(struct staticlist *head, int node)
{
	head[node].cur = head[0].cur;
	head[0].cur = node;
}

static int delectlinktable(struct staticlist *head, int headcur, int elem)
{
	int node;
	int frontcur;

	node = selectlinktable(head, headcur, elem);
	if (!node) {
		printf("selectlinktable faild\n");
		return -1;
	}
	
	frontcur = headcur;
	while (head[frontcur].cur != node) {
		frontcur = head[frontcur].cur;
	}

	head[frontcur].cur = head[node].cur;
	freearr(head, node);

	return 0;
}

static void displaylinktable(struct staticlist *head, int headcur)
{
	int temp, i = 0;

	temp = headcur;
	while (temp != 0) {
		printf("the node %d  value is %d\n", i, head[temp].data);
		temp = head[temp].cur;
		i++;
	}
}

int main (int argc, char *argv[])
{
	struct staticlist *head;
	int list, node;

	head = init_staticlist(10);
	if (!head) {
		printf("init_staticlist faild\n");
		exit(-1);
	}
	list = set_staticlist(head, 10);
	printf("the old list display:\n");
	displaylinktable(head, list);

	insertlinktable(head, list, 2, 8);
	printf("insertlinktable display:\n");
	displaylinktable(head, list);

	delectlinktable(head, list, 1);
	printf("delectlinktable display:\n");
	displaylinktable(head, list);

	node = selectlinktable(head, list, 8);
	printf("the selectlinktable node is %d\n", node);

	modifylinktable(head, list, 3, 7);
	printf("modifylinktable display:\n");
	displaylinktable(head, list);
	
	return 0;
}
