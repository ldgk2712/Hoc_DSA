#include <stdio.h>
#include <string.h>

void bubbleSort(char *s, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (s[j] > s[j+1])
            {
                char temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp; 
            }
        }
    }
}

int main()
{
    char s[100];
    fgets(s, sizeof(s), stdin);
    if (s[strlen(s)-1] == '\n')
    {
        s[strlen(s)-1] = '\0';
    }   
    bubbleSort(s,strlen(s));
    printf("%s",s);
    return 0;
}