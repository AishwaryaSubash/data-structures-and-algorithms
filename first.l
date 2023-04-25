digit ^[0-9]
letter [a-zA-Z_]

%{
#include <stdio.h>
%}

%%
{digit}*{letter}* {
printf("Invalid");
}
%%

int yywrap() {}

int main() {
	yylex();
	return 0;
}
