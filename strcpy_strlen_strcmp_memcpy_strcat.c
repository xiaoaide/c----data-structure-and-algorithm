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

static void strcpy1_lianxi(char *dest, char *source)
{
	if (dest == NULL || source == NULL) {
		return;
	}

	while (*source != '\0') {
		*dest = *source;
		dest++;
		source++;
	}

	*dest = '\0';
}

static void strcpy_lianxi2(char *dest, char *source)
{
	if (dest == NULL || source == NULL)
		return;

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

static int strlen_lianxi(char *s)
{
	int len = 0;

	if (s == NULL)
		return -1;

	while (*s != '\0') {
		len++;
		s++;
	}

	return len;
}

static int strlen_lianxi1(char *s)
{
	int len = 0;

	if (s == NULL)
		return -1;
	
	if (*s == '\0') {
		return 0;
	}

	return strlen_lianxi1(s + 1) + 1;

}

static int strlen_lianxi2(char *s)
{
	int len = 0;

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

static int strcmp_lianxi(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return -1;

	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0') {
		s1++;
		s2++;
	}

	if (*s1 == '\0' && *s2 == '\0')
		return 0;

	return *s1 - *s2;
}

static int strcmp_lianxi1(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return -1;

	while (*s1 != '\0' && *s2 != '\0') {
		if (*s1 != *s2)
			return *s1 - *s2;
		s1++;
		s2++;
	} 

	if (*s1 == '\0' && *s2 == '\0')
		return 0;
	else 
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

static void strcat_lianxi(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return;

	while (*s1 != '\0')
		s1++;

	while (*s2 != '\0') {
		*s1 = *s2;
		s1++;
		s2++;
	}

	*s1 = '\0';
}

static void strcat_lianxi1(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return;

	while (*s1 != '\0') {
		s1++;
	}

	while (*s2 != '\0') {
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
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

static void memcpy_lianxi(void *dest, void *source, int len)
{
	char *dst;
	char *src;
	int i;
	
	if (dest == NULL || source == NULL)
		return;

	if (dest + len >= source || source + len >= dest)
		return;

	dst = (char *)dest;
	src = (char *)source;

	for (i = 0; i < len; i++) {
		*dst = *src;
		dst++;
		src++;
	}	
}

static void memcpy_lianxi1(void *dest, void *source, int len)
{
	char *des, *src;

	if (dest == NULL || source == NULL) 
		return;

	if (dest + len >= source || source + len >= dest)
		return;

	des = (char *)dest;
	src = (char *)source;

	while (len--) {
		*des = *src;
		des++;
		src++;
	}
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

static void memset_lianx(void *data, int val, int len)
{
	char *da;

	if (data == NULL)
		return;

	da = (char *)data;
	while (len > 0) {
		*da = val;
		da++;
		len--;
	}
	
}

int main(int atgc, void *argv[])
{
	char *s = "13rrfrrt";
	char s1[20];
	char *s2 = "13rttfrrt";
	
	printf("the s len is %d\n", strlen_lianxi(s));
	printf("the s len is %d\n", strlen_lianxi1(s));
	printf("the s len is %d\n", strlen_lianxi2(s));

	strcpy_lianxi2(s1, s);
	printf("the s1 is %s\n", s1);

	printf("s and s2 cmp is %d\n", strcmp_lianxi1(s, s2));
	printf("s and s1 cmp is %d\n", strcmp_lianxi1(s, s1));

	strcat_lianxi1(s1, s2);
	printf("s1 and s2 cat is %s\n", s1);

	memcpy_lianxi1(s1, s, 5);
	printf("s and s1 memcpy 4 is %c\n", s1[4]);

	strcpy_lianxi2(s1, s);
	memset_lianx(s1, 0x31, 5);
	printf("s1 memset1 is %s\n", s1);
}
