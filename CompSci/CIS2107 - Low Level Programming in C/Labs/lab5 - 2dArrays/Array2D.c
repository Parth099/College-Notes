/*
    name: Parth Patel
    email: 13074@temple.edu
    date: 2/17/22
    course: 2107, SEC => 003

    ASSIGNMENT: LAB5 - 2d_Arrays

    Problem: Create user-defined 2-d arrays and use loops to display their props;
*/

//headers
#include <stdio.h>

//declarations
int max(int row, int col, const int arr[row][col]);
long long rowSum(int rowToSum, int row, int col, const int arr[row][col]); //long long to avoid overflow
long long columnSum(int colToSum, int row, int col, const int arr[row][col]);
int isSquare(int row, int col);
void displayOutputs(int row, int col, int arr[row][col]);
//quite sad we cannot use pointers
void writeToArray(int row, int col, int arr[row][col]);


int main(void)
{
    //read into memory 2d array
    int rowLen, colLen;

    puts("Let's create a 2Dim array!\n");
    printf("\t%s", "How many rows? ");
    scanf("%d", &rowLen);
    printf("\t%s", "How many cols? ");
    scanf("%d", &colLen);
    puts("");

    //write to array
    int arr[rowLen][colLen];
    writeToArray(rowLen, colLen, arr);

    //max
    printf("\nThe max is: %d\n", max(rowLen, colLen, arr));

    //sum of rows
    for(size_t rowtoSum = 0; rowtoSum < rowLen; rowtoSum++){
        printf("\nSum of row %lu: %lld", rowtoSum + 1, rowSum(rowtoSum, rowLen, colLen, arr));
    }

    puts("");
    //sum of cols
    for(size_t coltoSum = 0; coltoSum < rowLen; coltoSum++){
        printf("\nSum of column %lu: %lld", coltoSum + 1, columnSum(coltoSum, rowLen, colLen, arr));
    }
    puts("\n");

    //display array
    if(rowLen == 1){
        puts("Here is your 1Dim array:");
    }
    else{
        puts("Here is your 2Dim array:");
    }
    displayOutputs(rowLen, colLen, arr);
}

void writeToArray(int row, int col, int arr[row][col]){
    for(size_t i = 0; i < row; i++){
        for(size_t j = 0; j < col; j++){
            printf("\tenter [%lu][%lu]: ", i, j);
            scanf("%d", &arr[i][j]); //(*(arr + i))+j
        }
    }
}

void displayOutputs(int row, int col, int arr[row][col]){
    for(size_t i = 0; i < row; i++){
        putchar('['); 
        size_t j;
        for(j = 0; j < col-1; j++){
            printf("%d, ", arr[i][j]);
        }
        printf("%d", arr[i][j]); //offset printf to avoid index checking
        puts("]"); //puts for new line
    }
}

int max(int row, int col, const int arr[row][col]){
    if(row < 1 || col < 1){
        return -1;
    }
    //if ensures [0][0] exists
    int maxEle = arr[0][0];
    for(size_t i = 0; i < row; i++){
        for(size_t j = 0; j < col; j++){
            if(arr[i][j] > maxEle){
                maxEle = arr[i][j];
            }
        }
    }
    return maxEle;
}

long long rowSum(int rowToSum, int row, int col, const int arr[row][col]){
    if(rowToSum >= row){
        return -1;
    }
    long long sum = 0;
    for(size_t c = 0; c < col; c++){//c++
        sum += arr[rowToSum][c];
    }
    return sum;
}

long long columnSum(int colToSum, int row, int col, const int arr[row][col]){
    if(colToSum >= col){
        return -1;
    }
    long long sum = 0;
    for(size_t r = 0; r < row; r++){
        sum += arr[r][colToSum];
    }
    return sum;
}

int isSquare(int row, int col){
    return row == col;
}