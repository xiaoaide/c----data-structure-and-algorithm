#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define MAX_DIGIT_NUM 4
#define MAX_NUM  30

struct elem {
	int data;
	int keys[MAX_DIGIT_NUM];
	int next;
};

struct static_list {
	int head;
	struct elem *list;
	int len;
};

static void creat_list(struct static_list *lb, int len)
{
	int i;

	lb->list = (struct elem *)malloc(sizeof(struct elem) * len);
	if (!lb->list) {
		printf("malloc failed\n");
		return;
	}

	lb->len = len;
	lb->head = 0;

	for (i = 0; i < len; i++) {
		lb->list[i].next = i + 1;
	}
	lb->list[len - 1].next = -1;
}

static void distribution(struct static_list *lb, int bit, int head[], int end[])
{
	int i, j;

	for (i = 0; i < 10; i++) {
		head[i] = -1;
		end[i] = -1;
	}

	for (i = lb->head; i != -1; i = lb->list[i].next) {
		for (j = 0; j < 10; j++) {
			if (lb->list[i].keys[bit] == j) {
				if (head[j] != -1) {
					lb->list[end[j]].next = i;	
				} else {
					head[j] = i;
				} 
				end[j] = i;
				break;
			}
		}
	}
}

static void togethor(struct static_list *lb, int head[], int end[])
{
	int i, e, j;

	i = 0;
	while (head[i] == -1)
		i++;

	lb->head = head[i];
	e = end[i];
	i++;
	for ( ; i < 10; i++) {
		if (head[i] != -1) {
			lb->list[e].next = head[i];
			e = end[i];
		}
	}

	lb->list[e].next = -1;
}

static void sort(struct static_list *lb)
{
	int i;
	int head[10];
	int end[10];

	for (i = 0; i < MAX_DIGIT_NUM; i++) {
		distribution(lb, i, head, end);
		togethor(lb, head, end);
	}
}

static void set_keys(int keys[], int data)
{
	int i;

	for (i = 0; i < MAX_DIGIT_NUM; i++) {
		keys[i] = data % 10;
		data /= 10;
	}
}

static void printf_list(struct static_list *lb)
{
	int i;

	for (i = lb->head; i != -1; i = lb->list[i].next) {
		printf("%d ", lb->list[i].data);
	}

	printf("\n");
}

int main(int atgc, void *argv[])
{
	struct static_list lb;
	int i;
	int len;
	int data;
	
	printf("input the len size:\n");
	scanf("%d", &len);

	creat_list(&lb, len);
	
	for (i = 0; i < len; i++) {
		printf("please input the data :\n");
		scanf("%d", &data);
		lb.list[i].data = data;	
		set_keys(lb.list[i].keys, data);
	}
	printf_list(&lb);

	sort(&lb);
	printf_list(&lb);
}
