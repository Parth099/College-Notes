void shorten(char *s, int new_len){
    int i;

    //iter while we dont hit new len or a NIL
    for(i = 0; i < new_len && (*s != '\0'); i++){
        s++;
    }
    //append NIL where iteration ended
    *(s) = '\0';
}


// int main(int argc, char const *argv[])
// {
//     char s[12] = "Hello World";
//     shorten(s, 5);
//     printf("%s", s);
// }
