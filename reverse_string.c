#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

static void reverse_order(char *s)
{
	int len;
	int right, left;
	char temp;

	if (s == NULL)
		return;
	
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

static void reverse_order1(char *s)
{
	char *p = s;
	char temp;

	if (s == NULL)
		return;

	while (*s != '\0') {
		s++;
	}
	s--;

	while (p < s) {
		temp = *s;
		*s = *p;
		*p = temp;
		s--;
		p++;	
	}
}

static void recur_string(char *s)
{
	if (*s != '\0') {
		recur_string(s + 1);
	}
	printf("%c", *s);
}

static void reverse_lianxi(char *s)
{
	char *str;
	char temp;

	if (!s) {
		printf("the s invalid\n");
		return;
	}
	
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

static void reverse_lianxi1(char *s)
{
	char *head, *end;
	char temp;

	if (s == NULL)
		return;

	head = end = s;

	while (*end != '\0')
		end++;

	end--;

	while (head < end) {
		temp = *head;
		*head = *end;
		*end = temp;
		end--;
		head++;
	}	
}

static void recur_string_lianxi(char *s)
{
	char *str;

	if (*s == '\0') {
		return;
	} else {
		str = s + 1;
		recur_string_lianxi(str);
		printf("%c", *s);
	}
}

static void recur_string_lianxi1(char *s)
{
	if (*s == '\0') {
		return;
	}

	recur_string_lianxi1(s + 1);
	printf("%c ", *s);
}


int main(int atgc, void *argv[])
{
	char s[] = "abcdef";

	//reverse_order1(s);	
	reverse_lianxi1(s);
	printf("%s\n", s);

	printf("recur_string:\n");
	recur_string_lianxi1(s);
	printf("\n");
}
