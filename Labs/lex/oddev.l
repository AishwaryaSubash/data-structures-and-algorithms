%option noyywrap
%{
#include <stdio.h>
%}

%%
[0-9]*[02468] {
	printf("%s is even", yytext);
}
[0-9]+ {
	printf("%s is odd", yytext);
}
. {
	printf("%s is invalid", yytext);
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
