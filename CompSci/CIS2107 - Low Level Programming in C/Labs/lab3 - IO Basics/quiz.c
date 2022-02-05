#include <stdio.h>
void f1();
void f2();

int main(){
    f2();
}

void f1(){
    int limit = 0;
    printf("Enter the value of num: ");
    scanf("%d", &limit);

    int odd = 0, even = 0;
    for(int i = 1; i <= limit; i++){
        if(i & 1){ //bitwise and to check last bit
            odd += i;
        }
        else{
            even += i;
        }
    }
    printf("Sum of all odd numbers = %d\nSum of all even numbers = %d\n", odd, even);
}

void f2(){
    int daysIn; //store init value ONLY
    printf("Enter the number of days: ");
    scanf("%d", &daysIn);

    int days = daysIn;
    int years, weeks;
    years = days / 365; //int div
    days %= 365;
    weeks = days / 7;
    days %= 7;

    printf("%d days is equivalent to %d years, %d weeks and %d days", daysIn, years, weeks, days);
}