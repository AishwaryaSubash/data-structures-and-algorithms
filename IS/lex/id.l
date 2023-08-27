%option noyywrap
%{
#include <stdio.h>
%}

%%
[a-zA-Z_][a-zA-Z0-9_]* {
	printf("Valid");
	return 0;
}
.* {
	printf("Invalid");
	return 0;
}
%%

int main() {
	printf("Enter ");
	yylex();
	return 0;
}
