%option noyywrap
%{
#include<stdio.h>
%}
%%
[0-9]*[02468] {
    printf("\neven");
}
[0-9]+ {
    printf("\nodd");
}
. {
    printf("\nInvalid input");
}
\n {
    return 0;
}
%%

int main() {
    printf("Enter input:");
    yylex();
}
