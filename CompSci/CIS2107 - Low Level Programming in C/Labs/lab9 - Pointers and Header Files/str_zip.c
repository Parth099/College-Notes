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

char* str_zip(char *s1, char *s2){
    unsigned len_s1 = my_strlen(s1);
    unsigned len_s2 = my_strlen(s2);


    //new block to contain new data
    char* zipped = (char*)malloc(sizeof(char) *  (len_s1+len_s2+1));
    char* zipped_head = zipped; //we dont need this but life will be easier if we know where head is

    short bit_switch = 1;
    //copy and flip until one of them ends
    while(*s1 != '\0' && *s2 != '\0'){
        if(bit_switch){
            *zipped = *s1;
            zipped++;
            s1++;
        }
        else{
            *zipped = *s2;
            zipped++;
            s2++;
        }
        bit_switch ^= 1; //xor bit flip
    }
    //copy over rest of data 
    while(*s1 != '\0'){
        *zipped = *s1;
        zipped++;
        s1++;
    }
    while(*s2 != '\0'){
        *zipped = *s2;
        zipped++;
        s2++;
    }

    //push NUL
    *zipped = '\0';
    return zipped_head;
}

// int main(int argc, char const *argv[])
// {
//     char* s1 = "TempleUniv";
//     char* s2 = "Hello";
//     printf("\"%s\"", str_zip(s1, s2));
//     return 0;
// }
