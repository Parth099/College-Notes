void rm_space(char *s){

    char* start = s;
    char* firstNonSpace = s;
    char* lastNonSpace = s;

    //get first non space
    while(*s != '\0'){
        if(*s != '\n' && *s != '\t' && *s != ' '){
            firstNonSpace = s;
            break;
        }
        s++;
    }

    //keep taking non spaces until we are done;
    s = start;
    while(*s != '\0'){
        if(*s != '\n' && *s != '\t' && *s != ' '){
            lastNonSpace = s;
        }
        s++;
    }

    int i;
    //copy over string of valid length
    for(i = 0; i < lastNonSpace - firstNonSpace + 1; i++){
        *start = *(firstNonSpace + i);
        start++;
    }
    //NUL copy
    *start = '\0';


}

// int main(int argc, char const *argv[])
// {
//     char s[12] = "   Hello   ";
//     rm_space(s);
//     printf("\"%s\"", s);
//     return 0;
// }
