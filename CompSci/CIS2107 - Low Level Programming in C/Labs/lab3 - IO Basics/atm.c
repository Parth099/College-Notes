#include <stdio.h>
#include <stdlib.h>

//pre
#define PIN 3014
#define PIN_ATTEMPTS 3
#define INIT_BALANCE 5000
#define ERROR_DEFAULT -1

#define FALSE 0
#define TRUE 1

int menuChoice();
int readIntFromSTDIN();
int menuLogic(double *balance);
int checkPin(int failureRate, int *pinIn);
void pmBalance(double *balance, char action);

int main(){
    double balance = INIT_BALANCE;
    double *balPtr = &balance; //we dont want ask for a pointer ever while iteration
    unsigned int isQuit = FALSE;

    puts("\nWelcome to the Temple ATM\n");

    //pin logic --------------------
    int pinPTR;
    int isCorrectPin = checkPin(PIN_ATTEMPTS, &pinPTR); //pass in pointer to recursive call to save var declarations
    if(isCorrectPin){
        puts("\nYou have entered the PIN correctly");
    }
    else{
        printf("You have entered the PIN incorrectly %d times\n\tGoodbye!", PIN_ATTEMPTS);
        exit(0);
    }

    //menu logic --------------------
    while(!isQuit){ //force choice until they quit
        isQuit = menuLogic(balPtr); //pointer pass in
    }
}
int menuChoice(){
    printf("\nMake a numerical choice from the menu:");
    printf("\n\t1. Check Balance");
    printf("\n\t2. Withdraw Cash");
    printf("\n\t3. Deposit Cash");
    printf("\n\t4. Quit");

    int choice = readIntFromSTDIN(1, 4, "Choose from The menu Above: ");
    if(choice == ERROR_DEFAULT){
        return menuChoice(); //recursive call to force a user to make a choice
    }
    return choice;
}
//displays menu and forces a choice and returns if the user is quitting
int menuLogic(double *balance){
    int choice = menuChoice(); //forces choice
    switch (choice) //takes action from choice
    {
    case 1:
        printf("\nYour Balance is currently at $%.2lf", *balance);
        break;
    case 2:
        pmBalance(balance, '-');
        break;
    case 3:
        pmBalance(balance, '+');
        break;
    case 4:
        printf("\nThank You for using this ATM.\n\tGoodbye!");
        return TRUE;
    default:
        return FALSE;
    }
    return FALSE;
}
//checks of int from STDIN is in range [start, end]
//range is inclusive
int readIntFromSTDIN(int rangeStart, int rangeEnd, char *text){
    int i;
    printf("\n%s", text);
    scanf("%d", &i);

    if(i > rangeEnd || i < rangeStart){
        return ERROR_DEFAULT;
    }
    return i;
}

//pointer for  scanf to save memory from having a new int everytime 
int checkPin(int failureRate, int *pinIn){ //failureRate is passed in by value we can edit it 

    //two bases cases. Only two possible states of the system 
    if(failureRate == 0){
        return FALSE;
    }

    printf("You have %d attempts to enter the pin Correctly\nEnter Your Pin: ", failureRate);
    scanf("%d", pinIn);

    if(*pinIn == PIN){
        return TRUE;
    }

    if(*pinIn < 1000 || *pinIn > 9999){
        puts("A PIN is 4 digits\n");
    }

    return checkPin(--failureRate, pinIn); //dec var and then use the value
}

void pmBalance(double *balance, char action){ //plus or minus to balance
    double moneyIO;
    switch(action)
    {
        case '+':
            puts("\nYou have chosen to Deposit Money");
            break;
        case '-':
            puts("\nYou have chosen to Withdraw Money");
            break;
        default:
            exit(0); //no other actions exist;
    }
    printf("\tEnter Amount > $");
    scanf("%lf", &moneyIO);
    //user tried to take more than what they have
    if((action == '-') && moneyIO > (*balance)){
        printf("Your balance is $%.2lf, you cannot withdraw $%.2lf\n\tTry Again", (*balance), moneyIO);
        //pmBalance(balance, action); recur to ask again but this can cause a issue if bal === 0
        return; //stop function to not write to balance
    }

    switch(action)
    {
        case '+':
            *balance += moneyIO;
            break;
        case '-':
            *balance -= moneyIO;
            break;
        default:
            exit(0); //no other actions exist;
    }
    
}