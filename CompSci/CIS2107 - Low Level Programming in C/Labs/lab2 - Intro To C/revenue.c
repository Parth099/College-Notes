/*
    name: Parth Patel
    email: 13074@temple.edu
    date: 1/28/22
    course: 2107, SEC => 003 

    ASSIGNMENT: LAB2
        This is Question 2

    Problem:
        Create a store that can handle bad[numeric] inputs that properly applies discounts
        according to predefined rules and then calcs the total price intaking the discount in the
        calculation.
*/

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
        printf("\nThis is not a valid item price.\nPlease run the program again\n");
        printf("Thank You for using \"Temple\" store");
        exit(1);
    }

    printf("Enter quantity: ");
    scanf("%lf", &quantity);

    if(!isValidPosInt(quantity)){
        printf("\nThis is not a valid quantity order.\nPlease run the program again\n");
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