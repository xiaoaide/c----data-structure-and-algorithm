#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

struct table {
	int *node;
	int length;
	int size;
};

int inittable(struct table *nu, int num)
{

	nu->node = (int *)malloc(num * sizeof(int));
	if (!nu->node) {
		printf("alloc node errno\n");
		return -1;
	}
	nu->length = 0;
	nu->size = num;

	return 0;
}

int selecttable(struct table *nu, int elem)
{
	int i;

	for (i = 0; i < nu->length; i++) {
		if (nu->node[i] == elem)
			return i;
	}
	
	return -1;
}

void changetable(struct table *nu, int oldelem, int newelem)
{
	int num;

	num = selecttable(nu, oldelem);
	nu->node[num] = newelem;
}

int addtable(struct table *nu, int elem, int position)
{
	int i;

	if (position > (nu->length + 1) || position > nu->size || position < 0) {
		printf("the position is illegal\n");
		return -1;
	}

	if (nu->length == nu->size) {
		nu->node = (int *)realloc(nu->node, (nu->size + 4) * sizeof(int));
		if (!nu->node) {
			printf("realloc fail\n");
			return -1;
		}

		nu->size += 4;
	}

	for (i = nu->length; i > position; i--) {
		nu->node[i] = nu->node[i - 1];
	}

	nu->node[position] = elem;
	nu->length++;	
	
	return 0;
}

int delecttable(struct table *nu, int position)
{
	int i;

	for (i = position; i < nu->length - 1; i++) {
		nu->node[i] = nu->node[i + 1];
	}

	nu->length--;

	return position;
}

void displaytable(struct table *nu)
{
	int i;

	for (i = 0; i < nu->length; i++) {
		printf("the table node %d is %d\n", i , nu->node[i]);
	}
}

int main (int argc, char *argv[])
{
	struct table nu;
	int i;

	memset(&nu, 0, sizeof(struct table));
	
	inittable(&nu, 4);
	for (i = 0; i < 4; i++) {
		nu.node[i] = i;
		nu.length++;
	}
	
	printf("printf old table\n");
	displaytable(&nu);

	printf("delect elem 1\n");
	delecttable(&nu, 1);	
	displaytable(&nu);

	printf("insert elem 5 in the num 2\n");
	addtable(&nu, 5, 2);
	displaytable(&nu);

	printf("select elem 3 position\n");
	printf("the elem 3 position is %d\n", selecttable(&nu, 3));

	printf("modify the elem 3 to 6\n");
	changetable(&nu, 3, 6);
	displaytable(&nu);

}
