%option noyywrap
%{
#include <stdio.h>
%}
%%
[a-zA-Z_][a-zA-Z0-9_]* {
    printf ("\n The given string is a Valid Identifier\n"); return 0; 
}
. {
    printf ("\n The given string is an Invalid Identifier\n"); return 0;
}
%%
int main () {
    printf ("\n Enter the Identifer: ");
    yylex();
    return 0;
}
