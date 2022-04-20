#include <stdint.h>
//assumes ints are 4 bytes
int all_letters(char* s){
    //cross plat 32 bit
    uint32_t letterBits = 0;
    char currLetter = *s;
    while(currLetter != '\0'){

        //normalize currLetter
        if(currLetter >= 97 && currLetter <= 122){
            currLetter -= 'a';
        }
        else if(currLetter >= 65 && currLetter <= 90){
            currLetter -= 'A';
        }

        //sets the kth bit to one if sees letter
        //if letterhold == 2^26 - 1 we are done
        if(currLetter >= 0 && currLetter <= 25){
            letterBits = letterBits | (1 << currLetter);
        }

        currLetter = *(++s);
    }
    //if the first 25 bits are on we return 1
    //67108863 = 2^26 - 1 ==> sum of first active bits
    return (letterBits == 67108863) ? 1 : 0;
}

// int main(int argc, char const *argv[])
// {
//     char *s = "abcdefghijklmnopqrstuvwxyz";
//     char *s2 = "abcdefghijklmnopqrstuvwx";

//     printf("%d %d", all_letters(s), all_letters(s2));
//     return 0;
// }

