#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define QU_LEN 10

struct queue {
	int data[QU_LEN];
	int head;
	int rear;
};

struct stack {
	struct queue qu1;
	struct queue qu2;
};

static int push_queue(struct queue *qu, int data)
{
	int position;

	position = qu->rear + 1;
	if (position == QU_LEN) 
		position = 0;
	if (position == qu->head) {
		return 0;
	}

	qu->data[qu->rear] = data;
	qu->rear = position;

	return 1;
}

static int pop_queue(struct queue *qu)
{
	int position;
	int data;

	if (qu->head == qu->rear) {
		return -1;
	}	

	data = qu->data[qu->head];
	position = qu->head + 1;
	if (position == QU_LEN)
		position = 0;

	qu->head = position;

	return data;
}

static void push_stack(struct stack *sk, int data)
{
	int ret;

	ret = push_queue(&sk->qu1, data);
	if (!ret) {
		printf("the stack is full\n");
		return;
	}
}

static int pop_stack(struct stack *sk)
{
	int data, data_temp;

	data = pop_queue(&sk->qu1);
	if (data == -1) {
		printf("the stack is empty\n");
		return -1;
	}
	
	if (sk->qu1.head == sk->qu1.rear) {
		return data;
	} else {

		push_queue(&sk->qu2, data);
		while (sk->qu1.head < ((sk->qu1.rear - 1) == -1? QU_LEN - 1 : sk->qu1.rear - 1)) {
			data = pop_queue(&sk->qu1);
			push_queue(&sk->qu2, data);
		}

		data = pop_queue(&sk->qu1);

		while ((data_temp = pop_queue(&sk->qu2)) != -1) {
			push_queue(&sk->qu1, data_temp);
			printf("%d ", data_temp);
		}

		return data;
	}
}

int main(int argc, void *argv[])
{
	struct stack sk;
	int i, data;

	sk.qu1.head = sk.qu1.rear = 0;
	sk.qu2.head = sk.qu2.rear = 0;

	printf("push_stack\n");
	for (i = 0; i < 6; i++) {
		push_stack(&sk, i);
	}	

	printf("pop_stack\n");
	for (i = 0; i < 6; i++) {
		data = pop_stack(&sk);
//		printf("%d ", data);
	}
	printf("\n");	
}
