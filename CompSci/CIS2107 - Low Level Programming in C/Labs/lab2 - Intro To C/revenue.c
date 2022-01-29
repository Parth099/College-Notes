#include <stdio.h>  //for IO
#include <stdlib.h> //for exit
#include <math.h>  //modf

//declare
int isValidPosInt(double num);
double getDiscount(int units);

//entry
int main(){
    double itemPrice, quantity;
    printf("Welcome to \"Temple\" store");
    printf("\nEnter item Price: ");
    scanf("%lf", &itemPrice);

    if(!isValidPosInt(itemPrice)){
        printf("\nThis is not a valid item price. Please run the program again");
        printf("Thank You for using \"Temple\" store");
        exit(1);
    }

    printf("Enter quantity: ");
    scanf("%lf", &quantity);

    if(!isValidPosInt(quantity)){
        printf("\nThis is not a valid quantity order. Please run the program again");
        printf("Thank You for using \"Temple\" store");
        exit(1);
    }
    
    printf("\nThe item price is: $%.2lf", itemPrice);
    printf("\nThe order is: %.0lf item(s)", quantity);

    double discount = getDiscount(quantity);
    double itemCost = itemPrice * quantity;

    printf("\nThe cost is: $%.2lf", itemCost);
    printf("\nThe discount is: %.2lf%%", discount);
    printf("\nThe discount amount is: $%.2lf", discount * itemCost);
    printf("\nThe total is: $%.2lf", itemCost * (1 - discount));

    printf("\nThank You for using \"Temple\" store\n");

}

//functions
int isValidPosInt(double num){
    double frac, integer;
    frac = modf(num, &integer);
    if(frac != 0.0 || num <= 0){
        return 0;
    }
    return 1;
}

double getDiscount(int units){
    double discount = 0.0;
    if(units > 0 && units < 50){
        discount = 0.0;
    }
    else if(units < 100){
        discount = .1;
    }
    else if(units < 150){
        discount = .15;
    }
    else{
        discount = .25;
    }
    return discount;
}