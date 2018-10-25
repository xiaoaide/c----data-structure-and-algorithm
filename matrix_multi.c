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
	int position[4];
};

static void fast_multi(struct three_elem *A, struct three_elem *B, struct three_elem *C)
{
	int arow;
	int ap, bp, cp, ap1, bp1;
	int *colsum;

	C->m = A->m;
	C->n = B->n;
	C->num = 0;
	C->position[0] = 0;
	colsum = (int *)malloc(sizeof(int) * B->n);
	if (colsum) {
		memset(colsum, 0, sizeof(int) * B->n);
	}	

	cp = 0;
	for (arow = 0; arow < A->m; arow++) {
		if (arow > 0)
			C->position[arow] = C->position[arow - 1] + C->num;
		
		if (arow == (A->m -1)) {
			ap1 = A->num;
		} else 
			ap1 = A->position[arow + 1];

		for (ap = A->position[arow]; ap < ap1; ap++) {
			if (A->data[ap].j == (B->m - 1)) {
				bp1 = B->num;
			} else 
				bp1 = B->position[A->data[ap].j + 1];		
	
			for (bp = B->position[A->data[ap].j]; bp < bp1; bp++) {
				colsum[B->data[bp].j] += B->data[bp].data * A->data[ap].data;
			}	
		}
		
		for (bp = 0; bp < B->n; bp++) {
			if (colsum[bp]) {
				C->data[cp].i = arow;
				C->data[cp].j = bp;
				C->data[cp].data = colsum[bp];
				cp++;
				C->num++;
			}	
		}

		memset(colsum, 0, sizeof(int) * B->n);
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

static void setposition(struct three_elem *M)
{
	int i;
	int *arry;

	arry = (int *)malloc(sizeof(int) * M->m);
	if (!arry) {
		printf("malloc failed\n");
		return;
	}
	memset(arry, 0, sizeof(int) * M->m);

	for (i = 0; i < M->num; i++) {
		arry[M->data[i].i]++;
	}

	M->position[0] = 0;
	for (i = 1; i < M->m; i++) {
		M->position[i] = M->position[i - 1] + arry[i - 1];
	}
		
}

int main(int argc, void *argv[])
{
	struct three_elem A;
	struct three_elem B;
	struct three_elem C;

	A.m = 3;
	A.n = 4;
	A.num = 4;
	A.data[0].i = 0;
	A.data[0].j = 0;
	A.data[0].data = 3; 
	A.data[1].i = 0;
	A.data[1].j = 3;
	A.data[1].data = 5; 
	A.data[2].i = 1;
	A.data[2].j = 1;
	A.data[2].data = -1; 
	A.data[3].i = 2;
	A.data[3].j = 0;
	A.data[3].data = 2; 
	setposition(&A);

	B.m = 4;
	B.n = 2;
	B.num = 4;
	B.data[0].i = 0;
	B.data[0].j = 1;
	B.data[0].data = 2; 
	B.data[1].i = 1;
	B.data[1].j = 0;
	B.data[1].data = 1; 
	B.data[2].i = 2;
	B.data[2].j = 0;
	B.data[2].data = -1; 
	B.data[3].i = 2;
	B.data[3].j = 1;
	B.data[3].data = 4; 
	setposition(&B);
	
	printf("the A matrix is :\n");	
	printf_matrix(&A);
	printf("the B matrix is :\n");	
	printf_matrix(&B);
	
	fast_multi(&A, &B, &C);
	printf("the C matrix is :\n");	
	printf_matrix(&C);

}
