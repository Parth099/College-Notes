#include <stdlib.h> //malloc

char* repeat(char *s, int x, char sep){
    char* head = s;
    int s_len;
    for(s_len = 0; *s != '\0'; s_len++, s++);

    //s_len + 1 due to `sep`
    const int blockSize = x * (s_len + 1);
    //extra space so we dont cause seg fault
    char* repeater = malloc((sizeof(char) * (blockSize)) + sizeof(char));

    if(repeater == 0){
        return 0;
    }

    char* repeaterHead = repeater;

    //loops `x` times
    for(; x > 0; x--){
        s = head;

        //copy s
        while(*s != '\0'){
            *(repeater++) = *(s++);
        }
        //copy sep
        *(repeater++) = sep;
    }
    //remove last sep
    *(--repeater) = '\0';
    return repeaterHead;
}

// int main(int argc, char const *argv[])
// {
//     char* s = "hello";
//     printf("\"%s\"", repeat(s, 2, '-'));
//     return 0;
// }
