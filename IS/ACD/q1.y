%{
  #include<stdio.h>
  #include <string.h>
  #include <stdlib.h>
//   #include "y.tab.h"
  int yylex();
  int yyerror();
  char sent[100000][100000];
  int index1 = 0;
  int val1 = 0;
%}


%token SUBJECT ADVERB VERB DT NOUN


%%
sentence: SEN {
   val1 = 1;
}
SEN: S VP O;
S: SUBJECT;
VP: AD V
 | V;
AD: ADVERB;
V: VERB;
O: N
| D N;
D: DT;
N: NOUN;
;
%%


int main()
{
   char *strings[] = {"This","Computer","never","is","run","am","tell","the","a","university","world","cheese","lies"};
   char cpy[100];
   int n = 3;
   int num_words = sizeof(strings)/sizeof(char*);


   //makes 3 word sentences
   for (int i = 0; i < num_words; i++) {
       for (int j = 0; j < num_words; j++) {
           for (int k = 0; k < num_words; k++) {
               if (i != j && i != k && j != k) {
                   char str[100];
                   int pos = 0;
                   pos += sprintf(str + pos, "%s ", strings[i]);
                   pos += sprintf(str + pos, "%s ", strings[j]);
                   pos += sprintf(str + pos, "%s", strings[k]); 
                   strcpy(sent[index1++],str);
               }
           }
       }
   }


   //makes 4 word sentences
   for (int i = 0; i < num_words; i++) {
       for (int j = 0; j < num_words; j++) {
           for (int k = 0; k < num_words; k++) {
               for (int l = 0; l < num_words; l++) {
                  if (i != j && i != k && i != l && j != k && j != l && k != l) {
                       char str[100];
                       int pos = 0;
                       pos += sprintf(str + pos, "%s ", strings[i]);
                       pos += sprintf(str + pos, "%s ", strings[j]);
                       pos += sprintf(str + pos, "%s ", strings[k]);
                       pos += sprintf(str + pos, "%s", strings[l]);
                       strcpy(sent[index1++],str);
                   }
               }
           }
       }
   }
   int sno = 0;
   printf("Accepted Strings are : ");
   for(int i = 0;i<index1;i++){
       yy_scan_string(sent[i]);
       if(yyparse() == 0 && val1 == 1){
           printf("\n %d) %s ",++sno,sent[i]);
       }
   }
   printf("\n");
}


int yyerror() {
   val1 = 0;
}

