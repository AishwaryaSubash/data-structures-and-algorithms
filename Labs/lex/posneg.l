%option noyywrap
%{
#include <stdio.h>
%}

%%
[0-9]+ {
	printf("%s is positive", yytext);
}
[-][0-9]+ {
	printf("%s is negative", yytext);
}
. {
	printf("Invalid");
}
\n {
	return 0;
}
%%

int main() {
	printf("Enter ");
	yylex();
	return 0;
}
