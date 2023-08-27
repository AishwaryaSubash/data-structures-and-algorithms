%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>
%}
%%
"("    { putchar('('); }
")"    { putchar(')'); }
.      { /* ignore other characters */ }
%%
int main()
{
    int c;  
    int open_paren_count = 0;
    while ((c = getchar()) != EOF) {
        if (c == '(') { 
            open_paren_count++;
        } 
        else if (c == ')') {
            open_paren_count--;
            if (open_paren_count < 0) { 
                printf("Error: unmatched parentheses\n");  
                return 1;
            }  
        }  
    }
    if (open_paren_count > 0) {
        printf("Error: unmatched parentheses\n");
        return 1;
    } else {
        printf("All parentheses matched\n");
        return 0; 
    }
}

