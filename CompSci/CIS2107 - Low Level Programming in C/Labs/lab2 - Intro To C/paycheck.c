/*
    name: Parth Patel
    email: 13074@temple.edu
    date: 1/28/22
    course: 2107, SEC => 003

    ASSIGNMENT: LAB2
        This is Question 1 

    Problem:
        Create an Employee Logging system that catches invalid numbers and calcs their wages
        with the rules provided.
*/

#include <stdio.h>  //for IO
#include <stdlib.h> //for exit
#include <math.h>  //modf

int isValidPosInt(double num);
double getPayCheckAmt(double sal, double hrs ,double *overTime, double *netPay);

int main(){
    double employeeNum;
    double hSalary;
    double weekTime;

    printf("Welcome to \"TEMPLE HUMAN RESOURCES\"\n");
    printf("Enter Employee Number: ");
    scanf("%lf", &employeeNum);
    if(!isValidPosInt(employeeNum)){
        //if number is invalid
        printf("\nThis is not a valid Employee Number.\nPlease run the program again\n");
        printf("\nThank you for using \"TEMPLE HUMAN RESOURCES\"");
        exit(1);
    }
    printf("Enter Hourly Salary: ");
    scanf("%lf", &hSalary);

    //hours & payment/hr can be decimal
    if(hSalary < 0){
        printf("\nThis is not a valid Salary.\nPlease run the program again\n");
        printf("\nThank you for using \"TEMPLE HUMAN RESOURCES\"");
        exit(1);
    }
    printf("Enter Weekly Time: ");
    scanf("%lf", &weekTime);
    if(weekTime < 0 || weekTime > 168.0){
        //if number is invalid
        printf("\nThis is not a valid Weekly Time.\nPlease run the program again\n");
        printf("\nThank you for using \"TEMPLE HUMAN RESOURCES\"");
        exit(1);
    }
    double total, overTime = 0, regPay = 0;
    total = getPayCheckAmt(hSalary, weekTime, &overTime, &regPay);
    printf("==============================");
    printf("\nEmployee Number: %0.lf", employeeNum);
    printf("\nHourly Salary: $%0.lf", hSalary);
    printf("\nWeekly Time: %0.lf", weekTime);
    printf("\nRegular Pay: $%0.lf", regPay);
    printf("\nOvertime Pay: $%0.lf", overTime);
    printf("\nNet Pay: $%0.lf", regPay + overTime);
    printf("\n==============================");
    printf("\nThank you for using \"TEMPLE HUMAN RESOURCES\"\n");
}

int isValidPosInt(double num){
    double frac, integer;
    frac = modf(num, &integer);
    if(frac != 0.0 || num < 0){
        return 0;
    }
    return 1;
}

//used pointers to have my output yield 3 values & array is overkill
double getPayCheckAmt(double sal, double hrs ,double *overTime, double *regPay){
    if(hrs > 40){
        *overTime = (sal*1.5)*(hrs - 40);
        hrs -= (hrs - 40);
    }
   *regPay = sal * hrs;
    return (*regPay) + (*overTime);
}