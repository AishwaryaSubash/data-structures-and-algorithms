//SYMBOL TABLE
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main()
{
    FILE *fp = fopen("input1.c", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    char line[256];
    int count = 0;
    while (fgets(line, sizeof(line), fp))
    {
        char *token;
        char de[1000];
        char *l = line;
        printf("\nStatement : %d", ++count);
        char *rest = strtok_r(l, ";", &l);
        while ((token = strtok_r(rest, " ", &rest)))
        {
            strcpy(de, token);
            int i;
            const int len = strlen(de);

            for (i = 0; i < len; i++)
            {
                if (!isdigit(de[i]))
                    break;
            }

            int value = len == i ? atoi(de) : 0;
            if (de[0] == '#' || de[0] == '{' || de[0] == '}')
            {
                break;
            }

            else if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 || strcmp(token, "/") == 0 || strcmp(token, "%") == 0)
            {
                printf("\nOperator\t%s", token);
            }
            else if (strcmp(token, "=") == 0)
            {
                printf("\nAssignment\t%s", token);
            }
            else if (strcmp(token, "int") == 0 || strcmp(token, "float") == 0 || strcmp(token, "char") == 0 || strcmp(token, "double") == 0)
            {
                printf("\nData Type\t%s", token);
            }
            else if (de[0] == '\'' || de[0] == '\"' || value != 0)
            {
                printf("\nValue\t\t%s", token);
            }
            else
            {
                if (isalpha(de[0]) || de[0] == '_')
                    if (de[strlen(de) - 1] == ')' || de[strlen(de) - 2] == ')')
                        break;
                    else
                        printf("\nIdentifier\t%s", token);
                else
                {
                    printf("\nInvalid\t\t%s", token);
                    break;
                }
            }
        }
        printf("\n");
    }
    fclose(fp);
    return 0;
}
