#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    printf("Enter a string : ");
    scanf("%s", s);
    int i;
    while (1)
    {
        int flag = 0;
        for (i = 0; i < strlen(s) - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                int j;
                for (j = i; j < strlen(s) - 2; j++)
                    s[j] = s[j + 2];
                s[j] = '\0';
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
    printf("%s\n", s);
}