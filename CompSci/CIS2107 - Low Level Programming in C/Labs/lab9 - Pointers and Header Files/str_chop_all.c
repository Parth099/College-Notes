#include <stdlib.h> //for malloc

void my_strcpy(char* dest, char* src_start, int count){
    int i;
    for(i = 0; i < count; i++){
        *(dest + i) = *(src_start + i);
    }
    *(dest + i) = '\0';
}

char** str_chop_all(char *s, char c){
    char* s_sub = s;
    char* copyhead = s;
    char* copyTail = s;

    //counts space needed by counting the number of `c`
    unsigned arrSZ = 0;
    while(*s){
        if(*s == c){
            arrSZ++;
        }
        s++;
    }

    s = s_sub; //reset back to head;

    //alloc space
    //+2 as we need 1 for NIL, +1 again since one str splits into 2
    char** chopped = malloc(sizeof(char *) * (arrSZ + 2));

    //heap issue
    if(chopped == 0){
        return 0;
    }

    char** chopped_head = chopped;

    //move head to correct spot
    while(*copyhead != '\0' && *copyhead == c){
        copyhead++; //skips `c`s at the start
    }

    while(*s){ //since '\0' => 0
        if(*s == c && copyTail - copyhead > 0){ //copy if char c isnt back to back
            //allocate mem
            //store address on *chopped
            *chopped = malloc(copyTail - copyhead + 1); //+1 for the NIL

            if(chopped == 0){
                return 0; //err
            }

            //copy it down
            my_strcpy(*chopped, copyhead, copyTail - copyhead);
            chopped++;

            //move head to next valid splot
            copyhead = copyTail + 1; 
            while(*copyhead != '\0' && *copyhead == c){
                copyhead++; //skips on consective `c`s
            }
        }
        s++;
        copyTail++;
    }
    //at this point s has ended
    int finalBlockSize = s - copyhead;
    if(finalBlockSize > 0){
        *chopped = malloc(finalBlockSize +1); //copy leftover
        if(chopped == 0){
            return 0;
        }
        my_strcpy(*chopped, copyhead, finalBlockSize);
        chopped++;
    }   
    *chopped = '\0'; //term
    return chopped_head; //haha
}

// int main(int argc, char const *argv[])
// {
//     char* s = "I am ready for a nice vacation";
//     char** out = str_chop_all(s, '/');
//     while(**out != '\0'){
//         printf("%s\n", *out);
//         out++;
//     }
//     return 0;
// }
