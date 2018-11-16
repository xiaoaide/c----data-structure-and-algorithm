#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int total = 0;

static int check(int *position, int raw, int col)
{
	int col1;
	int i;

	for (i = 0; i < raw; i++) {
		col1 = position[i];	
		if (col == col1)
			return 0;
		if ((raw + col) == (i + col1))
			return 0;
		if ((raw - col) == (i - col1))
			return 0;
	}

	return 1;
}

static void printf_position(int *position)
{
	int i, j;
	
	printf("print one position:\n");
	for (i  = 0; i < 8; i++) {
		for (j = 0; j < position[i]; j++)
			printf("0");
		printf("#");
		for (j = position[i] + 1; j < 8; j++)
			printf("0");

		printf("\n");
	}
}

static void eight_queens(int *position, int raw)
{
	int col;

	for (col = 0; col < 8; col++) {
		if (check(position, raw, col)) {
			position[raw] = col;
			if (raw == 7) {
				total++;
				printf_position(position);	
				position[raw] = -1;
				return;			 
			}
			eight_queens(position, raw + 1);
			position[raw] = -1;
		}	
	}
}

int main(int argc, void *argv[])
{
	int position[8];
	int i;
	
	for (i = 0; i < 8; i++) {
		position[i] = -1;
	}

	eight_queens(position, 0);
	printf("the total is %d\n", total);
}
