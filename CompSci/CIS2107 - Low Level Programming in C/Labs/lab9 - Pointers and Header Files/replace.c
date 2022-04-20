#include <stdio.h>
#include <stdlib.h>

unsigned my_strLen(char *str){
    unsigned len = 0;
    while(*(str) != '\0'){
        len++;
        str++;
    }
    return len;
}

char* replace(char *s, char *pat, char *rep){

    //get sizes
    unsigned s_len, p_len, r_len;
    s_len = my_strLen(s);
    p_len = my_strLen(pat);
    r_len = my_strLen(rep);

    //worst case of each letter being a pattern
    //assume each letter must be replaced
    const int blockSize = sizeof(char) * (r_len * s_len);

    char* replaced = malloc(blockSize + 1); //+1 for my fav char \0
    if(replaced == 0){
        return 0; //mem err
    }

    char* replaced_head = replaced; //for return

    //store heads for looping
    char* pattern_head = pat;
    char* rep_head = rep;
    char* sub_s_ptr; 

    int isMatched;
    while(*s != '\0'){

        sub_s_ptr = s;
        pat = pattern_head;
        isMatched = 0; //assume no match exists

        //attempt to match
        if(*s == *pat){
            isMatched = 1; //prepare to copy
            //match
            while(*pat != '\0' && *s != '\0'){
                if(*pat != *s){
                    isMatched = 0;
                }
                pat++;
                s++;
            }
            //side case if string runs out
            if(*s == '\0' && *pat != '\0'){
                isMatched = 0;
            }

            //reset all pointers
            s = sub_s_ptr;
        }

        //if pat === stnstr(s, X, Y) for some X, Y
        if(isMatched){
            //copy over rep
            rep = rep_head;
            while(*rep != '\0'){
                *(replaced++) = *(rep++);
            }

            s += p_len - 1; //move FWD patten spaces if we copied
            //sub one since +3 in 0-based is +4 in reality

        }
        else{
            //else just copy over str
            *(replaced++) = *s;
        }
        s++;
    }
    *replaced = '\0';
    return replaced_head;
}

int main(int argc, char const *argv[])
{
    char* s = "Replace XYZ with XYZ";
    char* pat = "XYZ";
    char* rep = "AB";
    printf("\"%s\"", replace(s, pat, rep));
    return 0;
}
