#include <stdlib.h>

unsigned my_strlen(char* s){
    unsigned sz = 0;
    while (*s != '\0')
    {
        sz++;
        s++;
    }
    return sz;
}

char *str_connect(char **strs, int n, char c){
    unsigned totalLen = 0;

    //sums up the total length of all the strings
    for(int i = 0; i < n; i++){
        totalLen += my_strlen(*(strs + i)); 
    }

    //blocksize : number of chars req
    //n spacers
    //1 NUL
    const int blockSize = totalLen + n + 1; 
    char* connected = malloc(sizeof(char) * blockSize);

    if(connected == 0){
        return 0;
    }

    char* connected_head = connected;
    char* currentStr = 0; //deref to address

    for(int i = 0; i < n; i++){
        //copy over current string
        currentStr = *(strs+i);

        while(*currentStr != '\0'){
            //de ref to pointer, increment and return 
            *(connected++) = *(currentStr++);
        } 
        *(connected++) = c; //place splitter
    }


    //move 1 back and comsume last seperator
    *(--connected) = '\0';
    return connected_head;
}

// int main(int argc, char const *argv[])
// {
//     int size = 3;
//     char* s[3] = {"Washington", "Adams", "Jefferson"};
//     char sep = '+';

//     printf("\"%s\"", str_connect(s, size, sep));

//     return 0;
// }
