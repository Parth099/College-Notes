#include <stdio.h>
#define SIZE 10
#define COLS 10
#define ROWS 5

void print2DArr(int x[][COLS], int nrows);
void fill2DArr(int x[][COLS], int nrows);
void zeroEdges(int x[][COLS], int nrows);

int main(){
    int x[2][COLS] = {{0}, {0}};
    fill2DArr(x, 2);
    zeroEdges(x, 2);
    print2DArr(x, 2);
}

void print2DArr(int x[][COLS], int nrows){
    for(size_t r = 0; r < nrows; r++){
        for(size_t c = 0; c < COLS; c++){
            printf("%4d ", x[r][c]);
        }
        puts(" ");
    }
}

void fill2DArr(int x[][COLS], int nrows){
    int count = 0;
    for(size_t r = 0; r < nrows; r++){
        for(size_t c = 0; c < COLS; c++){
            x[r][c] = count;
            count++;
        }
    }
}

void zeroEdges(int x[][COLS], int nrows){
    for (size_t c = 0; c < COLS; c++)
    {
        x[0][c] = 0;
        x[nrows-1][c] = 0;
    }
    for (size_t r = 1; r < nrows-1; r++)
    {
        x[r][0] = 0;
        x[r][COLS - 1] = 0;
    }
}