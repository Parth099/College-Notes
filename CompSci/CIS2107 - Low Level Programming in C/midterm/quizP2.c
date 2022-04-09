#include <stdio.h>
#define SIZE 10
#define COLS 10
#define ROWS 5

void circumference(double radius); 
void area(double radius); 
void volume(double radius); 

int main(){
    void (*funcs[3])() = {&circumference, &area, &volume};
    int flag = 1;
    int usrCh = 0;
    double radius;
    printf("\nWhat is your Radius? ");
    scanf("%lf", &radius);
    while(flag){
        puts("\nPick an action:");
        puts("\t1. Get Circumference");
        puts("\t2. Get Area");
        puts("\t3. Get Volume");
        puts("\t4. Quit");

        printf("\nYour Choice: ");
        scanf("%d", &usrCh);

        if(usrCh >= 1 && usrCh <= 3){
            (funcs[usrCh-1])(radius);
        }
        else if(usrCh == 4){
            flag = 0;
        }
        else{
            puts("Lets try this whole thing again!!");
        }
    }
}


void circumference(double radius){
    printf("%lf", radius);
}
void area(double radius){
    printf("A");
}
void volume(double radius){
    printf("V");
}