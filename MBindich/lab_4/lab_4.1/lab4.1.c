#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

void removeDouble (double* array, int order, int* len)
{
    for (int i = order; i + 1 < *len; i++)
    {
        array[i] = array[i + 1];
    }

    *len -= 1;
    array[*len] = '\0';
}

void removeInt (int* array, int order, int* len)
{
    for (int i = order; i + 1 < *len; i++)
    {
        array[i] = array[i + 1];
    }

    *len -= 1;
    array[*len] = '\0';
}

void removeChar (char* array, int order, int len)
{
    for (int i = order; i + 1 < len; i++)
    {
        array[i] = array[i + 1];
    }

    array[len - 1] = '\0';
}

void removeCharAndLen (char* array, int order, int* len)
{
    for (int i = order; i + 1 < *len; i++)
    {
        array[i] = array[i + 1];
    }

    *len -= 1;
    array[*len] = '\0';
}

int verify(char* str, int len)
{
    if (len > 100)
    {
        return 1;
    }

    for (int i = 0; i < len; i ++)
    {
        if ((str[i] == 42) || (str[i] == 43) || (str[i] == 45) || (str[i] == 47))
        {
            if ((i == 0) || (i == len - 1))
            {
                return 2;
            }

            switch (str[i-1])
            {
            case (42):
            {

            }
            case (43):
            {

            }
            case (45):
            {

            }
            case (47):
            {
                return 3;
                break;
            }
            }
        }
        else if ((str[i] < 48) || (str[i] > 57))
        {
            return 4;
        }
    }

    return 0;
}


void RemoveSpaces(char* str, int* len, void (*removeCharAndLen)(char*, int, int*))
{
    for (int i = 0; i < *len; i++)
    {
        if (str[i] == ' ')
        {
            removeCharAndLen(str, i, *&len);
            i -= 1;
        }
    }
}

int main()
{
    char* str = (char* )malloc(100 * sizeof(char));
    if (!str)
    {
        return 1;
    }

    int len = 0;

    int* numOfMultOrDiv = malloc(sizeof(int));
    if (!numOfMultOrDiv)
    {
        return 1;
    }
    *numOfMultOrDiv = 0;

    for (;;)
    {
        printf ("Enter your arithmetic expression (max lenght == 100):\n");
        fgets(str, 100, stdin);

        len = strlen(str) - 1;

        RemoveSpaces(str, &len,removeCharAndLen);

        str[len + 1] = '\0';
        str[len] = '\0';

        printf("\nlenght = %d\n",len);

        if (!verify(str,len))
        {
            printf("\n%s\n",str);
            break;
        }

        printf("\nCheck = %d\n", verify(str,len));
        printf("\n\nInvalid input\n\n");
        getchar();
        getchar();
    }

    int* numOfOperations = malloc(sizeof (int));
    if (!numOfOperations)
    {
        return 1;
    }
    *numOfOperations = 0;

    for(int i = 1; i < len-1; i++)
    {
        switch (str[i])
        {
        case (42):
        {

        }
        case (43):
        {

        }
        case (45):
        {

        }
        case (47):
        {
            *numOfOperations += 1;
            if ((str[i] == '*') || (str[i] == '/'))
            {
                *numOfMultOrDiv += 1;
            }
            break;
        }
        }
    }


    char* operations = (char* )malloc(((*numOfOperations) + 1) * sizeof(char));
    if (!operations)
    {
        return 1;
    }

    operations[*numOfOperations] = '\0';

    for(int i = 0, order = 0; i < len; i++)
    {
        switch(str[i])
        {
        case (42):
        {

        }
        case (43):
        {

        }
        case (45):
        {

        }
        case (47):
        {
            operations[order] = str[i];
            order += 1;
            break;
        }
        }
    }


    double* numbers = (double* )malloc(((*numOfOperations) + 1) * sizeof(double));

    for(int i = 1, startOfNum = 0, order = 0; i <= len; i++)
    {
        if ((str[i] == '*') || (str[i] == '+') || (str[i] == '/') || (str[i] == '-') || (i == len))
        {
            numbers[order] = 0;
            for (int j = startOfNum; j < i; j++)
            {
                numbers[order] += (str[j] - '0')*pow(10, i - 1 - j);
            }

            startOfNum = i + 1;
            order += 1;
        }
    }

    *numOfOperations += 1;

    for (int i = 0, j = 0; j < *numOfMultOrDiv; i++)
    {
        if (operations[i] == '*')
        {
            numbers[i] *= numbers[i+1];
            removeDouble(numbers, i + 1, numOfOperations);
            removeChar(operations, i, (short)sizeof(operations)/sizeof(char));
            i -= 1;
            j += 1;
        }
        else if (operations[i] == '/')
        {
            numbers[i] /= numbers[i+1];
            removeDouble(numbers, i + 1, numOfOperations);
            removeChar(operations, i, (short)sizeof(operations)/sizeof(char));
            i -= 1;
            j += 1;
        }
    }


    for (int i = 0; *numOfOperations > 1; i++)
    {
        if (operations[i] == '+')
        {
            numbers[i] += numbers[i+1];
            removeDouble(numbers, i + 1, numOfOperations);
            removeChar(operations, i, (short)sizeof(operations)/sizeof(char));
            i -= 1;
        }
        else if (operations[i] == '-')
        {
            numbers[i] -= numbers[i+1];
            removeDouble(numbers, i + 1, numOfOperations);
            removeChar(operations, i, (short)sizeof(operations)/sizeof(char));
            i -= 1;
        }
    }

    printf("\n\n\nAnswer: %.2f\n\n", numbers[0]);

    free (numOfMultOrDiv);
    free (numbers);
    free (operations);
    free (numOfOperations);
    free (str);
    return 0;
}
