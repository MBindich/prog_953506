#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void order (int input){
    system("cls");
    int amount, cost, primeCost;
    int tariffs[2][3] = {
        {160, 96, 205},//== Себестоимость
        {230, 142, 260}//== Рыночная стоимость
    };

    cost = tariffs[1][input - 1];
    primeCost = tariffs[0][input - 1];

    printf("Enter amount of material in tons: ");
    scanf("%d", &amount);

    country(amount, primeCost, cost);
}

void country(int amount, int primeCost, int cost) {
    system("cls");

    int shippingCost;
    int input;

    printf("Choose Shipping Country:");
    printf("\n1. Belarus");
    printf("\n2. Russia");
    printf("\n3. Ukraine");
    printf("\n4. Moldavia\n");

    scanf("%d", &input);
    switch (input){
        case 1: shippingCost = 200; break;
        case 2: shippingCost = 320; break;
        case 3: shippingCost = 320; break;
        case 4: shippingCost = 360; break;
    }

    details(amount, cost, primeCost, shippingCost);
}

void details(int amount, int cost, int primeCost, int shippingCost) {
    system("cls");

    int carriageAmount, input;
    if (amount % 50 == 0){
        carriageAmount = amount / 50;
    }
    else {
        carriageAmount = amount / 50 + 1;
    }

    int profit = cost * amount - shippingCost;

    printf("Tariffs:\n");
    printf("          |  Prime Cost  |  Final Cost  \n");
    printf("Cement    |     160      |      230     \n");
    printf("Gravel    |      96      |      142     \n");
    printf("Concrete  |     205      |      260     \n");

    printf("\nCurrent Order:\n");
    printf("Cost per ton                |   %d\n", cost);
    printf("Cost of order               |   %d\n", cost * amount);
    printf("Amount of carriages         |   %d\n", carriageAmount);
    printf("Delivery cost per carriage  |   %d\n", shippingCost);
    printf("Delivery cost               |   %d\n", shippingCost * carriageAmount);

    printf("\n\nAccept this order?");
    printf("\n1. Yes");
    printf("\n2. No\n");
    scanf("%d", &input);

    if (input == 1){
        printf("Profit - %d", profit);
    }

    printf("\nPress any button to continue");
    getch();
}

void credits() {
    system("cls");
    printf("2020, BSUIR, Minsk, Belarus");
    printf("\nPress any button to continue");
    getch();
}

int programExit() {
    system("cls");
    exit(0);
}

void menu(){

    system("cls");

    printf("Main menu\n\n");
    printf("1. Order Cement\n");
    printf("2. Order Gravel\n");
    printf("3. Order Concrete\n");
    printf("4. Credits\n");
    printf("5. Exit\n");

    int input;
    scanf("%d", &input);

    switch (input){
        case 1: case 2: case 3: order(input); break;
        case 4: credits(); break;
        case 5: programExit(); break;
    }
}

int main()
{
    while (1){
        menu();
    }

    return 0;
}
