beginning ^[a-zA-Z_]
condt [a-zA-Z0-9_]*
neg ^[^a-zA-Z_]
new [^a-zA-Z_0-9]

%{
#include<stdio.h>    
%}

%%
{begining}{condt} {
    printf("Valid");
}
{neg}{condt} {
    printf("Invalid");
}
%%

int yywrap(){}
int main(){
    yylex();
    return 0;
}
