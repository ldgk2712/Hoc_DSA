#include <stdio.h>
#include <string.h>

void insertCharacter(char *s, char ch, int index)
{
    for (int i = strlen(s); i > index; i--)
    {
        s[i] = s[i-1];
    }
    s[index] = ch;
    printf("After insert: %s\n",s);
}

int main()
{
    char s[100], ch;
    int index;

    fgets(s, sizeof(s), stdin);
    // s[strcspn(s, "\n")] = '\0';
    if (strlen(s) > 0 && s[strlen(s) - 1] == '\n') {
        s[strlen(s) - 1] = '\0';
    }

    scanf(" %c", &ch);

    scanf("%d",&index);

    insertCharacter(s,ch,index);
    return 0;
}