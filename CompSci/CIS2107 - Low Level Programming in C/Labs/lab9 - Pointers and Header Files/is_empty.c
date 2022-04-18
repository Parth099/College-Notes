int is_empty(char *s){
    while (*s != '\0')
    {
        if(*s != ' '){
            break;
        }
        s++;
    }
    //s is not at the end we know non space exists
    return (*s == '\0') ? 1 : 0;    
}

// int main(){
//     char* s = "    ";
//     char* p = " p";

//     printf("%d %d", is_empty(s), is_empty(p));
// }