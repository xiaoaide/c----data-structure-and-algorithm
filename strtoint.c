#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <math.h> 

static int strtoint(char *s)
{
	long long val;
	int len;
	int i;
	int negative = 0;

	if (s == NULL || *s == '\0') {
		printf("the string is null\n");
		return 0;
	}

	len = strlen(s);
	val = 0;

	if (s[0] == '-') {
		negative = 1;
	} else if (s[0] == '+') {
		negative = 0;
	} else {
		if ((s[0] - 0x30) < 0 || (s[0] - 0x30) > 9) {
			printf("the string illegal\n");
			return 0;
		}
		val = val * 10 + (s[0] - 0x30);	
	}

	for (i = 1; i < len; i++) {
		if ((s[i] - 0x30) < 0 || (s[i] - 0x30) > 9) {
			printf("the string illegal\n");
			return 0;
		}
		val = (s[i] - 0x30) + val * 10;
	}

	if (negative) 
		val = 0 - val;

	if (val > 0x7fffffffLL) 
		val = 0x7fffffffLL;
	else if (val < -0x80000000LL)
		val = -0x80000000LL;

	return val;
}


int main(int atgc, void *argv[])
{
	char *s = "-3147483647";
	
	printf("the str val is %d\n", strtoint(s));
}
