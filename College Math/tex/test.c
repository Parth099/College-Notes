#include <stdio.h>
int addInt(int n, int m) {
    return n+m;
}

int main(void)
{
    int functionPtr(int,int);

    functionPtr = addInt;
    //printf("%d", functionPtr(1,1));
    return 0;
}
