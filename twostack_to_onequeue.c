#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

struct stack {
	int data[10];
	int top;
};

struct queue {
	struct stack sk1;
	struct stack sk2;
};

static void push_stack(struct stack *sk, int data)
{
	if (sk->top == 9) {
		printf("the stack is full\n");
		return;
	}

	sk->top += 1;
	sk->data[sk->top] = data;
}

static int pop_stack(struct stack *sk)
{
	int data;

	if (sk->top == -1) {
		printf("the stack is empty\n");
		return -1;
	}

	data = sk->data[sk->top];
	sk->top -= 1;

	return data;	
}

static void push_queue(struct queue *qu, int data)
{
	int data_temp;

	if (qu->sk1.top == 9 && qu->sk2.top == 9) {
		printf("the queue is full\n");
		return;
	}

	if (qu->sk1.top == -1 && qu->sk2.top > -1) {
		while (qu->sk2.top != -1) {
			data_temp = pop_stack(&qu->sk2);
			push_stack(&qu->sk1, data_temp);
		}
		push_stack(&qu->sk1, data);
	} else if (qu->sk1.top == 9 && qu->sk2.top < 9) {
		while (qu->sk2.top < 9 && qu->sk1.top > -1) {
			data_temp = pop_stack(&qu->sk1);
			push_stack(&qu->sk2, data_temp);
		}
		push_stack(&qu->sk1, data);
	} else {
		push_stack(&qu->sk1, data);
	}
}

static int pop_queue(struct queue *qu)
{
	int data;

	if (qu->sk1.top == -1 && qu->sk2.top == -1) {
		printf("the queue is empty\n");
		return -1;
	}

	if (qu->sk2.top == -1) {
		while (qu->sk1.top != -1) {
			data = pop_stack(&qu->sk1);
			push_stack(&qu->sk2, data);		
		}
		data = pop_stack(&qu->sk2);
	} else {
		data = pop_stack(&qu->sk2);
	}


	return data;
}

static void push_queue_lianxi(struct queue *qu, int data)
{
	int temp;

	if (qu->sk1.top == 9 && qu->sk2.top != -1) {
		printf("the queue is full\n");
		return;
	}

	if (qu->sk1.top == 9 && qu->sk2.top == -1) {
		while (qu->sk1.top != -1) {
			temp = pop_stack(&qu->sk1);
			push_stack(&qu->sk2, temp);		
		}
		push_stack(&qu->sk1, data);
		return;
	}

	push_stack(&qu->sk1, data);
}

static int pop_queue_lianxi(struct queue *qu)
{
	int data;

	if (qu->sk1.top == -1 && qu->sk2.top == -1) {
		printf("the queue is empty\n");
		return -1;
	}

	if (qu->sk2.top != -1) {
		data = pop_stack(&qu->sk2);
		return data;
	}

	while (qu->sk1.top != -1) {
		data = pop_stack(&qu->sk1);
		push_stack(&qu->sk2, data);
	}

	data = pop_stack(&qu->sk2);

	return data;
}

int main(int argc, void *argv[])
{
	struct queue qu;
	int i;
	int data;

	qu.sk1.top = -1;
	qu.sk2.top = -1;

	pop_queue(&qu);

	for (i = 0; i < 21; i++) {
		push_queue_lianxi(&qu, i);
	}

	for (i = 0; i < 21; i++) {
		data = pop_queue_lianxi(&qu);
		printf("%d ", data);
	}
	printf("\n");

}
