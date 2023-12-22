#include <stdio.h>
#include <string.h>

void search(char s[][100], int k, int n, char *key)
{
    int check = 0;
    for (int i = 0; i < n; i++)
    {
        if (!strcmp(s[i],key))
        {
            printf("Found %s at %d\n",key,i);
            check = 1;
        }
    }
    if (!check)
    {
        printf("Not Found!\n");
    }
}

int main()
{
    int n, k;
    char s[100][100];
    char key[100];
    scanf("%d %d",&n,&k);
    for (int i = 0; i < n; i++)
    {
        scanf("%s",s[i]);
    }
    scanf("%s",key);
    search(s, k, n, key);
    return 0;
}