#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

static char *cut_blankspace(char *s)
{
	int i, j;
	int first = 0;
	int len;
	char s1[50];

	if (s == NULL)
		return NULL;

	len = strlen(s);
	j = 0;
	for (i = 0; i < len; i++) {
		if (i == 0 && s[i] == ' ') {
			continue;
		} else if (s[i] != ' ') {
			s1[j] = s[i];
			first = 0;
			j++;
		} else if (s[i] == ' ' && first == 0 && i != len - 1) {
			s1[j] = s[i];
			j++;
			first = 1;	
		} else if (s[i] == ' ' && first == 1) {
			continue;
		}
	}
	s1[j] = '\0';

	strcpy(s, s1);
	return s;
}

int main(int argc, void *argv)
{
	char s[] = " I  love  you  a "; 
	char *s1;

	s1 = cut_blankspace(s);
	printf("%s%s\n", s1, s);
}
