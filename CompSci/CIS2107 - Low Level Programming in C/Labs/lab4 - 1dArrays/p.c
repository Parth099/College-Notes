#include <stdio.h>

int main(void)
{
	int a = 7;
	int *aPtr = &a; //pointer to a 
	printf("Address: %p\nValue: %d\n", aPtr, a);
	//aPtr is the same as &a
	
	//Pointers also have a pointer. 
	printf("Pointer Addess: %p", &aPtr);
}