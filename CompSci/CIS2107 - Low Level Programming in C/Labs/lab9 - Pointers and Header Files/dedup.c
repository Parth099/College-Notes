#include <stdlib.h> //for calloc

char* dedup(char *s){
    char* head = s;
    int i;
    for(i = 0; *s != '\0'; i++, s++); 
    s = head; //finds the length of s;

    //there are atmost i unique chars then
    char* noDupe = calloc(i+1, sizeof(char)); //array full of '\0' //dont care if its slow for calloc

    if(noDupe == 0){
        return 0;
    }

    char* noDupeHead = noDupe;
    //loop over 
    char currChar = 0;
    int toBeInserted = 1;
    while(*s != '\0'){

        noDupe = noDupeHead; //slide new array back to its start
        toBeInserted = 1; //assume we need to insert
        currChar = *s;

        while(*noDupe != '\0'){
            //char has already been counted do not insert
            if(*noDupe == currChar){
                toBeInserted = 0; //dupe found => no insert
                break;
            }
            noDupe++; //scan next element
        }

        if(toBeInserted){
            //loop above only stops at '\0' so we can insert right there
            *noDupe = currChar;
        }

        s++;
    }

   return noDupeHead;

}

// int main(int argc, char const *argv[])
// {
//     char* s = "There's always money in the banana stand."; //Ther's alwymonitbd.
//     char* ret = dedup(s);
//     printf("%s", ret);

//     return 0;
// }
