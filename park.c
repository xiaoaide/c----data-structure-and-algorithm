#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

struct elem {
	int num;
	int time;
};

struct stack {
	struct elem car[5];
	int top;
	int rest;
};

struct quenu {
	int num[100];
	int tail;
	int front;
	int count;
};

struct park {
	struct stack inside;
	struct quenu outside;
	struct stack temp; 
};

static int input_stack(struct stack *table, int num, int time)
{
	if (table->rest == 0) {
		printf("the stack is full\n");
		return -1;
	}

	table->top += 1;
	table->car[table->top].num = num;
	table->car[table->top].time = time;
	table->rest--;
	
	return table->top + 1;
}

static struct elem output_stack(struct stack *table)
{
	struct elem car = {0}; 

	if (table->top == -1) {
		printf("the stack is null\n");
		return car;
	}	

	car = table->car[table->top];
	table->top--;
	table->rest++;

	return car;	
}

static int input_quenu(struct quenu *table, int num)
{
	int position;

	if ((table->tail + 1) == 100 ? 0: (table->tail + 1) == table->front) {
		printf("the quenu is full\n");
		return -1;
	}	

	table->num[table->tail] = num;
	position = table->tail + 1;
	table->tail = table->tail + 1 == 100 ? 0: table->tail + 1; 
	table->count++;

	return position;
}

static int outquenu(struct quenu *table)
{
	int vale;

	if (table->tail == table->front) {
		printf("the quenu is null\n");
		return -1;
	}

	vale = table->num[table->front];	
	table->front = table->front + 1 == 100 ? 0: table->front + 1;
	table->count--;


	return vale;
}

static void leave_onecar(struct stack *inside, struct stack *temp, struct quenu *outside, int num, int time)
{
	struct elem car;
	int outnum;

	car = output_stack(inside);
	while (car.num != num) {
		input_stack(temp, car.num, car.time);	
		car = output_stack(inside);
	}

	printf("the car stop time is %d, mony is %d\n", time - car.time, 2 * (time - car.time));

	while (temp->rest != 5) {
		car = output_stack(temp);
		input_stack(inside, car.num, car.time);
	}

	if (outside->count != 0) {
		outnum = outquenu(outside);
		input_stack(inside, outnum, time);
	}

}

static void come_onecar(struct stack *inside, struct quenu *outside, int num, int time)
{
	int position;

	if (inside->rest != 0) {
		position = input_stack(inside, num, time);
		printf("the car stop at inside %d\n", position);
		return;
	}

	position = input_quenu(outside, num);
	printf("the car stop at outside %d\n", position);
}



int main (int argc, char *argv[])
{
	struct park xhy;
	char option;
	int num, time;

	xhy.inside.top = -1;
	xhy.inside.rest = 5;
	xhy.temp.top = -1;
	xhy.temp.rest = 5;
	xhy.outside.tail = xhy.outside.front = 0;
	xhy.outside.count = 0;

	while (1) {
		printf("\nplease input the operation:\n");
		scanf("%c", &option);
		getchar();
		printf("please input the car num:\n");
		scanf("%d", &num);
		getchar();
		printf("please input the car time:\n");
		scanf("%d", &time);
		getchar();

		if (option == 'a') {
			come_onecar(&xhy.inside, &xhy.outside, num, time);
		} else if (option == 'b') {
			leave_onecar(&xhy.inside, &xhy.temp, &xhy.outside, num, time);
		}
	}

	return 0;
}
