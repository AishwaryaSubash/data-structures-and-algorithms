%option noyywrap
%{
   #include "y.tab.h"
   #include<stdlib.h>
   #include<stdio.h>
%}


%%
"This"|"Computer" {
   return SUBJECT;
}
"never" {
   return ADVERB;
}
"is"|"run"|"am"|"tell" {
   return VERB;
}
"the"|"a" {
   return DT;
}
"university"|"world"|"cheese"|"lies" {
   return NOUN;
}
[\n] ;
[\t ] ;
. {
   return yytext[0];
}
%%

