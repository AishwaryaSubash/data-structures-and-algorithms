%option noyywrap
%{
#include <stdio.h>
int vc=0, cc=0;
%}

%%
[aeiouAEIUO] {
	vc++;
}
[A-Za-z] {
	cc++;
}
%%

int main() {
	yylex();
	printf("v: %d\n c:%d", vc, cc);
	return 0;
}
