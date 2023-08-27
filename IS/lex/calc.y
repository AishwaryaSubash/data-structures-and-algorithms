%{
#include <stdio.h>
%}
%token NUM
%left '+' '-'
%left '*' '/'

%%
start: exp {
     printf("%d",$$);
};
exp: exp'+'exp {
   $$=$1+$3;
}
| exp'-'exp {
   $$=$1=$3;
}
| exp'*'exp {
   $$=$1*$3;
}
| exp'/'exp {
   if ($3==0) {
	   yyerror("error");
   }
   else {
	   $$=$1/$3;
   }
}
| '('exp')' {
   $$=$2;
}
| NUM {
   $$=$1;
};
%%

int main() {
	printf("Enter ");
	if (yyparse()==0) 
		printf("Success");
}
yyerror() {
	printf("Error");
}














