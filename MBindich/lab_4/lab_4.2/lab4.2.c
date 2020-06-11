#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>
#define N 100


void removeChar(char* array, int order, int len)
{
    for (int i = order; i + 1 < len; i++)
    {
        array[i] = array[i + 1];
    }
    array[len - 1] = '\0';
}

void removeSpaces(char* str, int len, void (*RemoveCharAndLen)(char*, int, int))
{
    for (int i = 0; i < len; i++)
    {
        if (str[i] == ' ')
        {
            RemoveCharAndLen(str, i, len);
            i -= 1;
        }
    }
}

int isEqual(char* str1, char* str2)
{
    unsigned short len = strlen(str1), len2 = strlen(str2);
    int sameChars = 0, sameFound = 0;

    if (len != len2)
    {
        return 1;
    }

    for (int i = 0; i < len; i++)
    {
        sameChars = 0;
        sameFound = 0;

        for (int j = 0; j < len; j++)
        {
            if (tolower(str1[i]) == tolower(str1[j]))
            {
                sameChars += 1;
            }
        }

        for (int j = 0; j < len; j ++)
        {
            if (tolower(str1[i]) == tolower(str2[j]))
            {
                sameFound += 1;
            }
        }

        if (sameChars != sameFound)
        {
            return 2;
        }
    }

    return 0;
}

int main()
{
    char buffer[N];

    FILE *file;
    file = fopen("C:/Cb_projects(2)/LR4/data.txt","r+");
    if (!file)
    {
        return 1;
    }

    int lines = 0;
    for (lines = 0; fgets(buffer, N, file) != NULL; lines += 1);

    printf("Amount of lines in file - %d\n\n", lines);

    char forCheck[lines][N];

    rewind(file);

    for (int i = 0 ; i < lines ; i ++)
    {
        fgets(forCheck[i],N,file);
        forCheck[i][N-1] = '\0';
    }
    free(file);

    for (int i = 0 ; i < lines - 1; i++)
    {
        for (int j = i + 1; j < lines; j++)
        {
            if (!isEqual(forCheck[i], forCheck[j]))
            {
                printf("%sand %s\n", forCheck[i], forCheck[j]);
            }
        }
    }
    return 0;
}
