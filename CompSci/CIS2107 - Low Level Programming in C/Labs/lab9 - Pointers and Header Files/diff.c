int diff(char *s1, char *s2){

    //store diff
    int distance = 0;
    
    //loop over s2
    while(*s2 != '\0'){
        if(*s2 != *s1){
            distance++;

        }

        //inc str1 if not end
        if(*s1 != '\0'){
            s1++;
        }
        s2++;
    }

    //if s1 is longer than s2
    while(*s1 != '\0'){
        distance++;
        s1++;
    }

    return distance;
}

// int main(){
//     char* s1 = "abckft77";
//     char* s2 = "abcfp11";

//     printf("%d", diff(s1, s2));
// }