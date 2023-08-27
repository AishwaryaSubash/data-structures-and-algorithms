#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("input.c", "r");
    if (fp == NULL)
    {
        printf("Error");
        return 1;
    }
    char line[100];
    int co = 0;
    while (fgets(line, sizeof(line), fp))
    {
        char de[100];
        char *token;

        char cpyline[100];
        strcpy(cpyline, line);

        char *l = line;
        char *rest = strtok_r(l, ";", &l);
        printf("Statement %d\n", co++);
        while ((token = strtok_r(rest, " ", &rest)))
        {
            strcpy(de, token);
            int len = strlen(de);
            int i;
            for (i = 0; i < len; i++)
            {
                if (!isdigit(de[i]))
                    break;
            }

            int value = len == i ? atoi(de) : 0;
            if (de[0] == '#')
            {
                printf("Preprocessor %s\n", cpyline);
                break;
            }
            else if (de[0] == '{' || de[0] == '}')
            {
                printf("Spcl op %s\n", de);
            }
            else if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 || strcmp(token, "/") == 0 || strcmp(token, "%") == 0)
            {
                printf("Operator %s\n", de);
            }
            else if (strcmp(token, "="))
            {
                printf("Assignment %s\n", de);
            }
            else if (strcmp(token, "int") == 0 || strcmp(token, "float") == 0 || strcmp(token, "double") == 0 || strcmp(token, "char") == 0)
            {
                printf("Datatype %s\n", de);
            }
            else if (de[0] == '\"' || de[0] == '\'' || value != 0)
            {
                printf("Value %s\n", de);
            }
            else
            {
                if (isalpha(de[0]) || de[0] == '_')
                    if (de[len - 1] == ')' || de[len - 2] == ')')
                        printf("Function %s\n", de);
                    else
                        printf("Id %s\n", de);
                else
                {
                    printf("Invalid\n");
                    break;
                }
            }
        }
    }
}
