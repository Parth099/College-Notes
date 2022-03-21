//CIS2017 Lab7: Race
//The purpose of this program is to simulate and display the race between the tortoise and the hare using a random number
//generator and preset move types. The animal positions are accessed and modified using pointers, and the display is
//controlled using the sleep() function. Sometimes it takes a while due to slippage.

/*
    name: Parth Patel
    email: 13074@temple.edu
    date: 2/17/22
    course: 2107, SEC => 003

    ASSIGNMENT: LAB6 - Race

    Objective: Work with basic pointers
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define GAME_INT_MIN 1
#define GAME_INT_MAX 10

int randomNumberGenerator();
void tortMove(int *tPtr);
void hareMove(int *hPtr);
void printRace(int hPos,int tPos);


//helper
int max(int a, int b);
int min(int a, int b);
void printNSpaces(unsigned n);

int main(){
    srand(time(NULL));

    int hPos =1;						//hare start position is 1, cannot slip past 1
    int tPos = 1;						//tortoise start position is 1, cannot slip past 1

    puts("\tON YOUR MARK, GET SET");
    puts("\tBANG               !!!!");	//the spacing is modeled after the sample
    puts("\tAND THEY'RE OFF    !!!!");	//the spacing is modeled after the sample

    while(hPos < 70 && tPos < 70){
        sleep(1);						//slows down the race
        hareMove(&hPos);
        tortMove(&tPos);

        //printf("| %3d, %3d |", hPos, tPos); //debug
        printRace(hPos,tPos);
        puts("");
    }

    if(tPos >= hPos){
        puts("TORTOISE WINS!!! YAY!!!");
    }
    else{
        puts("Hare wins. Yuch.");
    }

}

//Finds minimum of hare or tortoise position to decide which position to print first
int min(int a, int b){
    if(a > b){
        return b;
    }
    return a;

}
int max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

void printNSpaces(unsigned n){
    for(unsigned i = 0; i < n; i++){
        putchar(' ');
    }
}

//Prints the position of the H and T
void printRace(int hPos,int tPos){
    int dx = abs(hPos - tPos);
    
    if(dx == 0){
        //same position
        printNSpaces(hPos - 1);
        printf("OUCH!!!");
        return;
    }

    //both arent at the the same spot

    int intervalEndPoint1 = min(hPos, tPos);
    int intervalEndPoint2 = max(hPos, tPos);
    char losing = (intervalEndPoint1 == hPos) ? 'H' : 'T';
    char winning = (losing == 'H') ? 'T' : 'H';

    //print based on precalc-ed intervals

    printNSpaces(intervalEndPoint1 - 1); //-1 offset since we start at 1 and not 0
    putchar(losing);
    printNSpaces(intervalEndPoint2 - intervalEndPoint1 - 1); //single char offset due to prev print
    putchar(winning);

    //HOW IT WORKS:
    //It calculates the number of spaces required between start, currLOSER, currWINNER, end so we dont need to a if checking useless condits
}

//Controls the tortoise movement
void tortMove(int *tPtr){
    int moveKey = randomNumberGenerator();
    if(moveKey <= 5){
        *tPtr += + 3; //fast ->
    }
    else if(moveKey <= 7){ //no need to check for less than 5 since "else if"
        *tPtr = max(*tPtr - 6, 1); //we cant move behind the start post
    }
    else{
        *tPtr += + 1; //slow ->
    }
}

//Controls the hare movement
void hareMove(int *hPtr){
    int moveKey = randomNumberGenerator();
    //using else if so i dont need to negate post-conditionals
    if(moveKey <= 2){
        return; //no move
    }
    else if(moveKey <= 4){
        *hPtr += 9; // fast
    }
    else if(moveKey == 5){
        *hPtr = max(*hPtr - 12, 1);//cant let rabbit move behind start post
    }
    else if(moveKey <= 8){
        *hPtr += 1; //slow
    }
    else{
        *hPtr = max(*hPtr - 2, 1);
    }
}

//Generates random number from 1-10
int randomNumberGenerator(){
    return GAME_INT_MIN + (rand() % GAME_INT_MAX); //thus   0<= p  % 10 <= 9 ==> 1<= (p  % 10) + 1 <= 10
}
