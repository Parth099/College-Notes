void capitalize(char *s){
    const short lowerToUpperDiff = 32;
    int toBeCapped = 1;
    while(*s != '\0'){
        //cap and turn off cap bit
        if(toBeCapped && *s >=97 && *s <= 122){
            *s -= lowerToUpperDiff; //upper -> lower
            toBeCapped = 0;
        }

        //if space next element must be capped
        if(*s == ' '){
            toBeCapped = 1;
        }

        s++;
    }
}
// int main(int argc, char const *argv[])
// {
//     char s[20] = "hello world b";
//     capitalize(s);
//     printf("%s", s);
//     return 0;
// }
