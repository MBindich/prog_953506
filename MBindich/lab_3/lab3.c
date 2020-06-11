#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **arr;
    int n, m;
    printf("Enter a: ");
    scanf("%d", &n);
    m = n;

    arr = (int**)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            arr[i][j] = rand() % 50;
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int tmp = arr[0][0];
    int k = 0;
    int l = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tmp > arr[i][j]){
                tmp = arr[i][j];
                k = i;
                l = j;
            }
        }
    }

    int **arr2;
    arr2 = (int**)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr2[i] = (int*)malloc(m * sizeof(int));
    }

    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (i == k){
            continue;
        }
        b = 0;
        for (int j = 0; j < m; j++) {
            if (j == l){
                continue;
            }
            arr2[a][b] = arr[i][j];
            b++;
        }
        a++;
    }

    for (a = 0; a < n - 1; a++){
        for (b = a + 1; b < m - 1; b++){
            int tmp = arr2[a][b];
            arr2[a][b] = arr2[b][a];
            arr2[b][a] = tmp;
        }
    }

    for (a = 0; a < n - 1; a++) {
        for (b = 0; b < m - 1; b++) {
            printf("%d\t", arr2[a][b]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < n; i++){
        free(arr[i]);
    }

    for (int i = 0; i < n - 1; i++){
        free(arr2[i]);
    }
    free(arr);
    free(arr2);
    return 0;
}
