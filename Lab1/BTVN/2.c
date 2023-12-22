#include <stdio.h>
#include <string.h>

void searchCharacter(char *s, char ch)
{
    int check = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (ch == s[i] || ch == s[i]+32 || ch == s[i]-32)
        {
            printf("Found %c at %d\n", ch, i);
            check = 1;
        }
    }
    if (!check)
    {
        printf("Not found!\n");
    }
}

int main()
{
    char s[100];
    char ch;

    scanf("%s",s);
    scanf(" %c",&ch);

    searchCharacter(s,ch);
    return 0;
}