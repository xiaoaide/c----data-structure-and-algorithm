#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

static void reverse_string(char *s)
{
	int len;
	int right;
	int left;
	char temp;

	if (s == NULL) {
		return;
	}

	len = strlen(s);	
	left = 0;
	right = len - 1;

	while (left < right) {
		temp = s[left];
		s[left] = s[right];
		s[right] = temp;
		left++;
		right--;	
	}
	
}

static char * inttostr(int val)
{
	char *s;
	int i;
	int temp;
	
	s = (char *)malloc(20 * sizeof(char));
	if (!s) {
		printf("malloc failed\n");
		return NULL;
	}

	temp = val;

	if (val < 0) {
		i = 1;
		val = 0 - val;
	} else {
		i = 0;
	}

	while (val % 10) {
		s[i] = 0x30 + val % 10;
		i++;
		val /= 10;	
	}	

	s[i] = '\0';

	if (temp < 0) {
		reverse_string(&s[1]);
		s[0] = '-';
	} else {
		reverse_string(s);
	}


	return s;
}

static void reverse_string_lianxi(char *s)
{
	char *str;
	char temp;

	str = s;
	while (*s != '\0') {
		s++;
	}
	s--;

	while (str < s) {
		temp = *str;
		*str = *s;
		*s = temp;
		s--;
		str++;
	}
}

static void inttostr_lianxi(char *s, int val)
{
	int negative = 0;
	char *str;

	if (!s)
		return;

	if (val < 0) {
		negative = 1;
		val = 0 - val;
	}

	str = s;
	while (val % 10) {
		*s = val % 10 + 0x30;
		val /= 10;
		s++;
	}

	if (negative) {
		*s = '-';
		s++;
	}

	*s = '\0';

	reverse_string_lianxi(str);
}

static void inttostr_lianxi1(char *s, int val)
{
	char *str;
	int negative = 0;

	str = s;

	if (val < 0) {
		negative = 1;
		val = 0 - val;
	}

	while (val / 10 != 0) {
		*str = val % 10 + 0x30;
		str++;
		val = val / 10;
	}

	*str = val % 10 + 0x30;
	str++;
	if (negative) {
		*str = '-';
		str++;
	}
	*str = '\0';

	reverse_string_lianxi(s);
}

int main(int atgc, void *argv[])
{
	int val;
	char *s;
	char s1[20];

	val = -3456;
//	s = inttostr(val);
	inttostr_lianxi1(s1, val);

	printf("the s is %s\n", s1);
	
}
