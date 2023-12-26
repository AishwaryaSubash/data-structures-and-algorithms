%{
    #include<stdio.h>
    #include<stdlib.h>
    int vow_count=0; int const_count =0;
%}
%%
[aeiouAEIOU] {
    vow_count++;
}
[a-zA-Z] {
    const_count++;
}
%%
int yywrap(){}

int main() {
    yylex();
    printf("vowels: %d\nConsonants: %d\n", vow_count, const_count); 
    return 0;
}
