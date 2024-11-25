%{
   #include<stdio.h>
%}
%token NUM
%left '-''+'
%left '*''/'

%%
start: exp {
   printf("%d\n",$$);
}
exp: exp'+'exp {
   $$=$1+$3;
}
| exp'-'exp {
   $$=$1-$3;
}
| exp'*'exp {
   $$=$1*$3;
}
| exp'/'exp {
   if($3==0)
       yyerror("error");
   else {
       $$=$1/$3;
   }
}
| '('exp')' {
   $$=$2;
}
| NUM {
   $$=$1;
}
;
%%
int main()
{
   printf("Enter the Expr. in terms of integers\n");
   if(yyparse()==0)
      printf("Success\n");
}
yyerror() {
   printf("Error\n");
}
