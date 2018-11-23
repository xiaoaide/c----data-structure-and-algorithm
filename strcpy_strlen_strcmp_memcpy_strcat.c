#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

static void strcpy1(char *dest, char *source)
{
	int len;
	int i;
	
	if (source == NULL || dest == NULL) {
		return;
	}

	while (*source != '\0') {
		*dest = *source;
		dest++;
		source++;
	}

	*dest = '\0';
}

static int strlen1(char *s)
{
	int len;

	len = 0;

	if (s == NULL) 
		return -1;

	while (*s != '\0') {
		len++;
		s++;
	}

	return len;
}

static int strcmp1(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return -1;

	while (*s1 != '\0' && *s2 != '\0') {
		if (*s1 != *s2) 
			break;

		s1++;
		s2++;
	}

	return *s1 - *s2;
}

static char * strcat1(char *s1, char *s2)
{
	char *s, *ret_s;

	if (s1 == NULL || *s1 == '\0')
		return s2;
	if (s2 == NULL || *s2 == '\0')
		return s1;
	
	s = (char *)malloc(sizeof(char) * (strlen(s1) + strlen(s2)));
	if (!s) {
		printf("malloc failed\n");
		return NULL;
	}
	ret_s = s;

	while (*s1 != '\0') {
		*s = *s1;
		s++;
		s1++;
	}

	while (*s2 != '\0') {
		*s = *s2;
		s++;
		s2++;
	}

	*s = '\0';

	return ret_s;
}

static void * memcpy1(void *dest, const void *source, int len)
{
	char *d = (char *)dest;
	char *s = (char *)source;

	if (dest == NULL || source ==NULL)
		return NULL;

	if (source + len >= dest || dest + len >= source) {
		return NULL;
	}

	
	while (len--) {
		*d = *s;
		d++;
		s++;
	}

	return dest;
}

static void memset1(void *data, int val, int len)
{
	char *temp = (char *)data;

	if (data == NULL)
		return;

	while (len--) {
		*temp = val;
		temp++;	
	}
}

int main(int atgc, void *argv[])
{
	char *s = "13rrfrrt";
	char s1[20];
	char *s2 = "13rttfrrt";
	
	printf("the s len is %d\n", strlen1(s));

	strcpy1(s1, s);
	printf("the s1 is %s\n", s1);

	printf("s and s2 cmp is %d\n", strcmp1(s, s2));
	printf("s and s1 cmp is %d\n", strcmp1(s, s1));

	printf("s and s2 cat is %s\n", strcat1(s, s2));

	memcpy1(s1, s, 5);
	printf("s and s1 memcpy 4 is %c\n", s1[4]);

	strcpy1(s1, s);
	memset1(s1, 0x31, 5);
	printf("s1 memset1 is %s\n", s1);
}
