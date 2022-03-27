# Midterm Practice
## C Program Life Cycle
Ref: [[2.01 CLang]]
1. Edit
2. Preprocess
3. Compile
4. Link
5. Load
6. Execute

## Snippets
### Example A
```c
#include <stdio.h>

int main(){
	int arr[4];
	arr[5] = 1048576;
	printf("2^20 = %d", arr[5]);
	return 0;
}
```
This error would **not** be caught by a compiler. 

### Example B
```c
int arr[3] = {1} //this is {1, 0, 0} 
```

### Examples C
```c
int main(int argc, char const *argv[])
{     
	int x = 20, *y, *z;     
	y = &x;     
	z = y;  
	
	*y++;     
	*z++; 
	x++; 
	
	printf("x = %d, y = %d, z = %d", x, y, z);     
	//x = 21, y = 1094711344, z = 1094711344 
}
```

We notice that `z` is **not** dependent on `y`. The way to think about is that both `y` and `z` point to a space. Just because one of them is moved does not mean the other one will move. 