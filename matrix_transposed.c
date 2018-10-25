#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

struct data {
	int i;
	int j;
	int data;
};

struct three_elem {
	struct data data[4];
	int m;
	int n;
	int num;
};

static void generic(struct three_elem *T, struct three_elem *M)
{
	int row, num, p;

	T->m = M->n;
	T->n = M->m;
	T->num = M->num;

	p = 0;
	for (row = 0; row < T->n; row++) {
		for (num = 0; num < M->num; num++) {
			if (M->data[num].j == row) {
				T->data[p].j = M->data[num].i;
				T->data[p].i = M->data[num].j;
				T->data[p].data = M->data[num].data;
				p++;
			}
		}	
	}
}

static void fast(struct three_elem *T, struct three_elem *M)
{
	int arry[2];
	int position[2];
	int i, row, p;

	T->n = M->m;
	T->m = M->n;
	T->num = M->num;

	for (i = 0; i < 2; i++) {
		arry[i] = 0;
	}

	for (i = 0; i < M->num; i++) {
		arry[M->data[i].j]++;
	}

	position[0] = 0;
	for (i = 1; i < 2; i++) {
		position[i] = position[i - 1] + arry[i -1];
	}

	for (i = 0; i < M->num; i++) {
		row = M->data[i].j;
		p = position[row];
		T->data[p].i = M->data[i].j;
		T->data[p].j = M->data[i].i;
		T->data[p].data = M->data[i].data; 
		position[row]++;
	}
}

static void printf_matrix(struct three_elem *M)
{
	int i;

	for (i = 0; i < M->num; i++) {
		printf("(%d, %d, %d)\t", M->data[i].i, M->data[i].j, M->data[i].data);
	}
	printf("\n");
}

int main(int argc, void *argv[])
{
	struct three_elem M;
	struct three_elem T;
	
	M.num = 4;
	M.m = 3;
	M.n = 2;
	M.data[0].i = 0;
	M.data[0].j = 1;
	M.data[0].data = 1;
	M.data[1].i = 1;
	M.data[1].j = 1;
	M.data[1].data = 3;
	M.data[2].i = 2;
	M.data[2].j = 0;
	M.data[2].data = 6;
	M.data[3].i = 2;
	M.data[3].j = 1;
	M.data[3].data = 5;

	generic(&T, &M);
	printf("the customary matrix M is:\n");
	printf_matrix(&M);	
	printf("the  matrix T is:\n");
	printf_matrix(&T);	

	fast(&T, &M);
	printf("the customary matrix M is:\n");
	printf_matrix(&M);	
	printf("the  matrix T is:\n");
	printf_matrix(&T);	


}
