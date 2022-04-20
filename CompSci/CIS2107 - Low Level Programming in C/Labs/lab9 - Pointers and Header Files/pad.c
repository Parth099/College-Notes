#include <stdlib.h>

char* pad(char *s, int d){

    char* head = s;
    int i;
    for(i = 0; *s != '\0'; i++, s++); 
    s = head; //finds the length of s;

    if(d < i){
        d = i; //just copy it
    }

    char* newStr = malloc(sizeof(char) * (d+1));
    if(newStr == 0){
        return 0; //error in dyn mem
    }
    char* newhead = newStr;

    *(newStr+d) = '\0';

    int j;
    //copy over s
    for(j = 0; *s != '\0'; j++){
        *(newStr++) = *(s++);
    }

    //need to pad left over space from loop over
    for(j; j < d; j++){
        *(newStr++) = ' ';
    }

    return newhead;

}
// int main(int argc, char const *argv[])
// {
//     char* s = "hi";
//     printf("\"%s\"", pad(s, 4));
//     return 0;
// }

