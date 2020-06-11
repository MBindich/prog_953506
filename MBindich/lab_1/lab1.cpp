#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <windows.h>

using namespace std;

char getCubeChar(int k){
    int maneCounter = 0;
    int i = 1;
    int val = 0;
    //int strCounter = 0;
    char numStr[50];

    while (true){
        val = pow(i, 3);
        itoa(val, numStr, 10);
        printf("%s", numStr);

        int j = 0;
        while (numStr[j] != '\0'){
            maneCounter++;
            if (k == maneCounter){
                return numStr[j];
            }
            j++;
        }
        i++;
    }
}

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("Âגוהטעו k - ");
    char char_k[10];
    scanf("%s", char_k);
    int k = atoi(char_k);

    char res = getCubeChar(k);
    printf("\n%d Öטפנא ןמסכוהמגאעוכüםמסעט - %c", k, res);
    return 0;
}
