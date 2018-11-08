#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

struct node {
	int i;
	int j;
	int data;
	struct node *right;
	struct node *down;
};

struct cross_list {
	int m;
	int n;
	int num;
	struct node **rlist;
	struct node **clist;
};


static void creat_list(struct cross_list *lb)
{
	int num;
	int i, j;
	int data;
	struct node *nd;
	struct node *pre;

	printf("please input the m:\n");
	scanf("%d", &lb->m);
	printf("please input the n:\n");
	scanf("%d", &lb->n);

	lb->rlist = (void *)malloc(sizeof(struct node *) * lb->m);
	if (!lb->rlist) {
		printf("malloc failed\n");
		return;
	}
	memset(lb->rlist, 0,sizeof(struct node *) * lb->m);

	lb->clist = (void *)malloc(sizeof(struct node *) * lb->n);
	if (!lb->clist) {
		printf("malloc failed\n");
		return;
	}
	memset(lb->clist, 0,sizeof(struct node *) * lb->n);

	num = 0;
	for (i = 0; i < lb->m; i++) {
		for (j = 0; j < lb->n; j++) {
			printf("please input the data\n");
			scanf("%d", &data);
			if (data) {
				nd = (struct node *)malloc(sizeof(struct node));		
				if (!nd) {
					printf("malloc failed\n");
					return;
				}
				nd->i = i;
				nd->j = j;
				nd->data = data;
				nd->right = NULL;
				nd->down = NULL;
				if (lb->rlist[i] == NULL || nd->j < lb->rlist[i]->j) {
					nd->right = lb->rlist[i];
					lb->rlist[i] = nd;
				} else {
					pre = lb->rlist[i];
					while (pre->right != NULL && nd->j > pre->right->j)
						pre = pre->right;	
					nd->right = pre->right;
					pre->right = nd;
				}

				if (lb->clist[j] == NULL || nd->i < lb->clist[j]->i) {
					nd->down = lb->clist[j];
					lb->clist[j] = nd;
				} else {
					pre = lb->clist[j];
					while (pre->down != NULL && nd->i > pre->down->i)
						pre = pre->down;	
					nd->down = pre->down;
					pre->down = nd;
				}
				
				num++;
			}
		}
	}
	
	lb->num = num;
}

static void printf_matrix(struct cross_list *lb)
{
	int i, j;
	struct node *nd;
	
	for (i = 0; i < lb->m; i++) {
		nd = lb->rlist[i];
		while (nd != NULL) {
			printf("%d,%d,%d ", nd->i, nd->j, nd->data);
			nd = nd->right;
		}
		printf("\n");
	}
	
}

static void matrix_add(struct cross_list *M, struct cross_list *N)
{
	int i;
	int m;
	struct node *Nnd;
	struct node *Mnd;
	struct node **Clast;
	struct node *pre;
	struct node *new;
	struct node *temp;

	Clast = (void *)malloc(M->n * sizeof(struct node *));
	if (!Clast) {
		printf("malloc failed\n");
		return;
	}	

	for (i = 0; i < M->n; i++) {
		Clast[i] = M->clist[i];
	}

	m = N->m;
	for (i = 0; i < m; i++) {
		Nnd = N->rlist[i];
		Mnd = M->rlist[i];
		pre = NULL;
		while (Nnd != NULL) {
			new = (struct node *)malloc(sizeof(struct node));
			if (!new) {
				printf("malloc failed\n");
				return;
			}
			new->i = Nnd->i;
			new->j = Nnd->j;
			new->data = Nnd->data;
			new->right = NULL;
			new->down = NULL;

			if (Mnd == NULL || Mnd->j > new->j) {
				if (pre == NULL) {
					new->right = Mnd;
					M->rlist[i] = new;
				} else {
					pre->right = new;
					new->right = Mnd;
				}		
				pre = new;

				if (M->clist[new->j] == NULL || new->i < M->clist[new->j]->i) {
					new->down = M->clist[new->j];
					M->clist[new->j] = new;
				} else {
					new->down = Clast[new->j]->down;
					Clast[new->j]->down = new;
				}		
				Clast[new->j] = new;
			} else if (new->j > Mnd->j) {
				pre = Mnd;
				Mnd = Mnd->right;	
				continue;
			} else if (new->j == Mnd->j) {
				Mnd->data += new->data;
				if (!Mnd->data) {
					if (pre == NULL) {
						M->rlist[i] = Mnd->right;
					} else {
						pre->right = Mnd->right;
					}
					
					if (M->clist[Mnd->j] = Mnd) {
						M->clist[Mnd->j] = Clast[Mnd->j] = Mnd->down;
					} else {
						Clast[Mnd->j]->down = Mnd->down;
					}	

					temp = Mnd;
					Mnd = Mnd->right;
					free(temp);
				} else {
					Mnd = Mnd->right;
				} 
			}

			Nnd = Nnd->right;
		}
	}
}

int main(int argc, void *argv[])
{
	struct cross_list M;
	struct cross_list N;

	printf("please input matrix M:\n");
	creat_list(&M);
	printf("output matrix M:\n");
	printf_matrix(&M);

	printf("please input matrix N:\n");
	creat_list(&N);
	printf("output matrix N:\n");
	printf_matrix(&N);

	matrix_add(&M, &N);
	printf("output  add M + N :\n");
	printf_matrix(&M);
}
