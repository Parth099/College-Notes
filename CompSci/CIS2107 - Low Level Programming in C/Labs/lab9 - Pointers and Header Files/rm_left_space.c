void rm_left_space(char *s){
    char* start = s;

    //counts whitespaces
    while(*s != '\0'){
        if(*s != '\n' && *s != '\t' && *s != ' '){
            break;
        }
        s++;
    }
    //space white spaces to skip
    const int diff = s - start;
    if(diff == 0){
        return; //no whitespace detected
    }

    //copies from first non white to end now
    while(*s != '\0'){
        *start = *s;
        start++;
        s++;
    }
    //termintes string when done copying
    *start = '\0';
}
// int main(int argc, char const *argv[])
// {
//     char s[7] = "  Hi ";
//     rm_left_space(s);
//     printf("\"%s\"", s);
//     return 0;
// }
