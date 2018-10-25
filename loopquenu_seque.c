#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

struct quenu {
	int a[5];
	int tail;
	int front;
};

static int input_quenu(struct quenu *table, int elem)
{
	if (((table->tail + 1) == 5? 0: (table->tail + 1))  == table->front) {
		printf("the quene is full\n");
		return -1;
	}

	table->a[table->tail] = elem;
	table->tail = table->tail + 1 == 5? 0: table->tail + 1;

	return 0;
}

static int outquenu(struct quenu *table)
{
	int vale;

	if (table->tail == table->front) {
		printf("the quenu is null\n");
		return -1;
	}

	vale = table->a[table->front];	
	printf("out quenu value is  %d:", table->a[table->front]);
	table->front = table->front + 1 == 5? 0: table->front + 1;
	printf("the front is %d, the tail is %d\n", table->front, table->tail);

	return vale;
}


int main (int argc, char *argv[])
{
	struct quenu table;

	table.front = table.tail = 0;

	input_quenu(&table, 1);
	input_quenu(&table, 2);
	input_quenu(&table, 3);
	input_quenu(&table, 4);
	input_quenu(&table, 5);
	input_quenu(&table, 6);
	
	outquenu(&table);
	outquenu(&table);
	outquenu(&table);
	outquenu(&table);
	outquenu(&table);
	outquenu(&table);

	input_quenu(&table, 1);
	input_quenu(&table, 2);
	input_quenu(&table, 3);
	input_quenu(&table, 4);
	input_quenu(&table, 5);
	input_quenu(&table, 6);

	outquenu(&table);
	outquenu(&table);
	outquenu(&table);
	outquenu(&table);
	outquenu(&table);
	outquenu(&table);

	return 0;
}
