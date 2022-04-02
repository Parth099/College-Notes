#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <string.h>
 
int main()
{
    char str[15] = "(123)595-5050";
 
    // Returns first token
    char* token = strtok(str, "()");
 
    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, "-");
    }
 
    return 0;
}