#include <stdio.h>
#include <string.h>

#define SIZE 26

void solve1(char *s)
{
    int hashTable[SIZE] = {0};
    for (int i = 0; i < strlen(s); i++)
    {
        hashTable[s[i]-'a'] = 1;
    }
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        if (hashTable[ch - 'a'] == 0)
        {
            printf("%c at %d is missing!\n",ch,ch-'a');
        }
    }
    printf("abcdefghijklmnopqrstuvwxyz");
}

int binarySearch(char *s, char key)
{
    int l = 0;
    int r = strlen(s)-1;
    while (l <= r)
    {
        int m = (l+r)/2;
        if (s[m] < key)
        {
            l = m+1;
        }
        else if (s[m] > key)
        {
            r = m-1;
        }
        else
        {
            return m;
        }
    }
    return -1;
}
void solve2(char *s)
{
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        if (binarySearch(s, ch) == -1)
        {
            printf("%c at %d is missing!\n",ch,ch-'a');
            printf("abcdefghijklmnopqrstuvwxyz");
        } 
    }
}

int main()
{
    char s[100];
    fgets(s, sizeof(s), stdin);
    if (strlen(s) > 0 && s[strlen(s)-1] == '\n')
    {
        s[strlen(s)-1] == '\0';
    }
    solve2(s);
    return 0;
}