int strcmp_ign_case(char *s1, char *s2){
    char cs1, cs2;
    while(*s1 != '\0' && *s2 != '\0'){
        //if uppercase
        if(*s1 >= 65 && *s1 <= 90){
            cs1 = *s1 + 32; //convert to upper
        }
        else{
            cs1 = *s1;
        }

        //same for s2
        if(*s2 >= 65 && *s2 <= 90){
            cs2 = *s2 + 32; //convert to upper
        }
        else{
            cs2 = *s2;
        }

        if(cs1 - cs2 < 0){
            return -1;
        }
        else if(cs1 - cs2 > 0){
            return 1;
        }

        s1++;
        s2++;
    }

    //both strings are equal since the both finished
    if(*s1 == '\0' && *s2 == '\0'){
        return 0;
    }
    //string one is longer
    if(*s1 != '\0'){
        return 1;
    }
    return -1; //string one is shorter and appears before
}
// int main(){
//     char *s1 = "Hello";
//     char *s2 = "goodbye";
//     printf("%d", intstrcmp_ign_case(s1, s2));
// }