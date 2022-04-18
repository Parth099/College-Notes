void rm_right_space(char *s){
    char* lastValidChar = s; //last non whitespace char

    //scan entire array
    while(*s != '\0'){
        if(*s != '\n' && *s != '\t' && *s != ' '){
            lastValidChar = s;
        }
        s++;
    }

    if(*lastValidChar == '\0'){
        return; //no right white spaces
    }
    else{
        *(lastValidChar+1) = '\0'; //end string next to last valid char 
    }
}
// int main(int argc, char const *argv[])
// {
//     char s[9] = "Hello   ";
//     rm_right_space(s);
//     printf("\"%s\"", s);
//     return 0;
// }
