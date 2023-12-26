%{
#include<stdio.h>
%}
%%
[#].* {
   printf("\n%s Preprocessor",yytext);
}
"{"|"}" {
   printf("\n%s Special Operator",yytext);
}
"int"|"char"|"float"|"double"|"void"|"if"|"for"|"while" {
  printf("\n%s is a Keyword",yytext);
}
[+|-|/|*|=|%] {
  printf("\n%s is an Operator",yytext);
}>
[-|+]?[0-9]+ {
  printf("\n%s is a Constant",yytext);
}
[printf(].*[)]|[scanf(].*[)] {
  printf("\n%s is an Inbuilt function",yytext);
}
"main()" {
  printf("\n%s is a Function",yytext);
}
[a-zA-z_][a-zA-Z0-9_]* {
  printf("\n%s is an Identifier",yytext);
}
%%
int yywrap(){}
int main() {
yylex();
return 0;
}

/* 
//input

#include <stdio.h>
void main()
{
int n1, n2 = 10;
char ch;
float f1, f2;
double d1, d2;
printf("Hello World");
} 
*/
