%option noyywrap
%{
#include <stdio.h>
%}

%%
"int"|"float"|"char"|"double"|"void"|"if"|"while" {
	printf("%s is keyword",yytext);
}
[+|-|*|/|%] {
	printf("%s is an operator", yytext);
}
[-,+]?[0-9] {
	printf("%s is a constant", yytext);
	return 0;
}
"main()" {
	printf("%s is a function", yytext);
}
"printf()"|"scanf()" {
	printf("%s is an inbuilt function", yytext);
}
[a-zA-Z_][a-zA-Z0-9_] {
	printf("%s is an identifier", yytext);
}
%%

int main() {
	yylex();
	return 0;
}
