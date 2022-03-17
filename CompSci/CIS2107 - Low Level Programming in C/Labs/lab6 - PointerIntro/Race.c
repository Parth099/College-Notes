//CIS2017 Lab7: Race
//The purpose of this program is to simulate and display the race between the tortoise and the hare using a random number
//generator and preset move types. The animal positions are accessed and modified using pointers, and the display is
//controlled using the sleep() function. Sometimes it takes a while due to slippage.


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define INT_MIN 1
#define INT_MAX 10

int randomNumberGenerator();
void tortMove(int *tPtr);
void hareMove(int *hPtr);
void printRace(int hPos,int tPos);
int min(int hMin, int tMin);

int main(){
    srand((unsigned)time(NULL));

    int hPos =1;						//hare start position is 1, cannot slip past 1
    int tPos = 1;						//tortoise start position is 1, cannot slip past 1

    puts("\tON YOUR MARK, GET SET");
    puts("\tBANG               !!!!");	//the spacing is modeled after the sample
    puts("\tAND THEY'RE OFF    !!!!");	//the spacing is modeled after the sample

    while(hPos != 70 && tPos!=70){
        sleep(1);						//slows down the race
        hareMove(&hPos);
        tortMove(&tPos);
        printRace(hPos,tPos);
        puts("");
    }

}

//Finds minimum of hare or tortoise position to decide which position to print first
int min(int hMin, int tMin){

}

//Prints the position of the H and T
void printRace(int hPos,int tPos){

}

//Controls the tortoise movement
void tortMove(int *tPtr){
 
}

//Controls the hare movement
void hareMove(int *hPtr){

}

//Generates random number from 1-10
int randomNumberGenerator(){
 
}
