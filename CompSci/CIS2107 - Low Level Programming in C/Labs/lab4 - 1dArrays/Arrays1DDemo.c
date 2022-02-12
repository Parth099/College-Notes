/*
    name: Parth Patel
    email: 13074@temple.edu
    date: 2/11/22
    course: 2107, SEC => 003

    ASSIGNMENT: LAB4 - 1d Arrays

    Problem:
        Demonstrate control of 1-D Arrays in C
*/
#include <stdio.h>
#include <stdlib.h> //for rand numbering
#include <time.h> //for time()
#include <stdbool.h>


#define SIZE 40
#define PRINT_CHUNK_LIMIT 10

//signatures
void fillArray(int arr[], int size, int range_start, int range_end);
int findWithRange(int arr[], int size, int lo, int hi);
void reverseArray(int arr[], int size);
void reverseSelectedRangeWithinArray(int arr[], int size, int left, int right);
int findSequence(int arr[], int size);
bool isValidRange(int lo, int hi);

void printIntArr(int arr[], int size);


int main(void){
    srand(time(NULL)); //allowes for more random behavor

    int arr[SIZE]; //no need to fill with 0
    fillArray(arr, SIZE, 1, 100);

    printf("\nThe Array:\n");
    printIntArr(arr, SIZE);
    int r_start = 10, r_end = 19;
    int max = findWithRange(arr, SIZE, r_start, r_end);
    printf("\nMax between %d and %d is %d\n\n", r_start, r_end, max);

    reverseArray(arr, SIZE);
    printf("\nThe Reversed Array:\n");
    printIntArr(arr, SIZE);

    int s_start = 10, s_end = 19;
    reverseSelectedRangeWithinArray(arr, SIZE, s_start, s_end);
    printf("\nReversing between %d and %d\n", s_start, s_end);
    printIntArr(arr, SIZE);

    int foundIndex = findSequence(arr, SIZE);
    if(foundIndex > 0){
        printf("Sequence found at %d\n", foundIndex);
    }
    else{
        printf("Sequence not found\n");
    }
}

//prints a new line every N lines
void printIntArr(int arr[], int size){
    for(unsigned int i = 1; i < size+1; i++){
        printf("%4d  ", arr[i-1]);
        if(i % PRINT_CHUNK_LIMIT == 0){
            puts("");
        }
    }
}

void fillArray(int arr[], int size, int range_start, int range_end){
    for(unsigned int i = 0; i < size; i++){
        arr[i] = range_start + (rand() % range_end);
    }
}

bool isValidRange(int lo, int hi){
        //all invalid inputs
    if(lo > hi || lo < 0 || hi < 0 || hi >= SIZE){
        return false;
    }
    //valid but equal
    if(lo == hi && lo < SIZE && lo > 0){
        return true;
    }
    return true;
}

int findWithRange(int arr[], int size, int lo, int hi){
    bool isValid = isValidRange(lo, hi);
    if(isValid == false){
        return -1;
    }
    int max = arr[lo];
    for(unsigned int p = lo; p <= hi; p++){
        max = (max < arr[p]) ? arr[p] : max; //replace max if new number is over max
    }
    return max;
}

//reverses by flipping index
//index i becomes SIZE - i
void reverseArray(int arr[], int size){
    int revAddr = size - 1; //reverse address //-1 for 0 based calc
    int temp;
    for(unsigned int i = 0; i < size / 2; i++, revAddr--){
        temp = arr[i];
        arr[i] = arr[revAddr];
        arr[revAddr] = temp;
    }
}


//same logic as function above
void reverseSelectedRangeWithinArray(int arr[], int size, int left, int right){
    bool isValid = isValidRange(left, right);
    if(isValid == false || left == right){
        return;
    }

    int temp;
    for(unsigned int i = 0; i <= (right - left) / 2; i++){
        temp = arr[left + i];
        arr[left + i] = arr[right - i];
        arr[right - i] = temp;
    }
}

int findSequence(int arr[], int size){
    int ele1, ele2;
    printf("\nEnter two Integers to Search for: ");
    scanf("%d %d", &ele1, &ele2);

    for(unsigned int i = 0; i < size - 1; i++){
        if(arr[i] == ele1 && arr[i+1] == ele2){
            return i;
        }
    }
    return -1;
}