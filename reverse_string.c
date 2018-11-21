#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

static void reverse_order(char *s)
{
	int len;
	int right, left;
	char temp;
	
	len = strlen(s);
	
	right = len - 1;
	left = 0;

	while (right > left) {
		temp = s[left];
		s[left] = s[right];
		s[right] = temp;
		right--;
		left++;
	}
}


int main(int atgc, void *argv[])
{
	char s[] = "abcdef";

	reverse_order(s);	
	printf("%s\n", s);
}
