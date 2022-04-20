int ends_with_ignore_case(char *s, char *suff){
    char* suffHead = suff;

    int s_len = 0, suff_len = 0;
    for(s_len; *s != '\0'; s++, s_len++); //len of s
    for(suff_len; *suff != '\0'; suff++, suff_len++);

    if(s_len < suff_len){
        return 0; //not possible
    }

    //prepare to compare
    s -= suff_len; //move s to its last `suff-len` spaces
    suff = suffHead;

    char lValue, rValue;
    //check each letter
    while (*s != '\0')
    {
        lValue = *(s++);
        rValue = *(suff++);

        if(lValue >= 65 && lValue <= 90){
            lValue += 32; //lowercase
        }

        if(rValue >= 65 && rValue <= 90){
            rValue += 32; //lowercase
        }

        if(lValue != rValue){
            return 0;
        }
    }

    //if it gets to this point end of s == suff
    return 1;

}
// int main(int argc, char const *argv[])
// {
//     char* s = "coDinG";
//     char* suff = "INg";

//     printf("%d", ends_with_ignore_case(s, suff));
//     return 0;
// }
