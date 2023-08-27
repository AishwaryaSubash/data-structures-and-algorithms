#include <stdio.h>
#include <regex.h>

int match (const char *string, const char *pattern) {
	regex_t re;
	if (regcomp(&re, pattern, REG_EXTENDED | REG_NOSUB)!=0) {
		return 0;
	}
	int status = regexec(&re, string, 0, NULL, 0);
	if (status!=0) 
		return 0;
	return 1;
}
int main() {
	const char *s1 = "123";
	const char *s2 = "abc";
	const char *re = "[0-9]+";
	printf("%s, %s, %s", s1, re, match(s1, re)? "Valid":"Invalid");
	printf("%s, %s, %s", s2, re, match(s2, re)?"Valid":"Invalid");
	return 0;
}

