#include "my_string.h"

void rm_empties(char** words){
    int len = 0;
    while(*(words+len) != 0){
        //printf("%s", *(words+len));
        len++;
    }

    //removal time
    int currCycle = 0;
    while(*(words+currCycle) != 0 && currCycle <= len){ //extra guard to prevent inf loops
        if(is_empty(*(words+currCycle))){
            //shift array over 1
            for(int i = currCycle; i < len - 1; i++){
                *(words + i) = *(words + i + 1);
            }
            len--;
            *(words + len) = 0; //new null;
        }
        else{
            currCycle++; //shift one only if curr element is not space
        }
        
    }
    
}

// int main(int argc, char const *argv[])
// {

//     char* words[7] = {"Hello", " ", " ", "bye", "hi", 0};
//     rm_empties(words);
//     int i = 0;
//     while(*(words + i) != 0){
//         printf("%s\n", *(words + i));
//         i++;
//     }
// }
