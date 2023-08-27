%option noyywrap
%{
#include<stdio.h>
%}
%%
[0-9]+ {
    printf("\npositive\n");
}
[-][0-9]+ {
    printf("\nnegative\n");
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
