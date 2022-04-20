// #include <stdio.h>
int is_empty(char *s);


void rm_empties(char **words){
    while(**words != '\0'){
        if(is_empty(*words)){ //de ref to pointer to see if its empty
            *(words) = *(words + 1); //def ref to get pointer access, replace pointer with next one in line
        }
        words++;
    }
}

int is_empty(char *s){
    while (*s != '\0')
    {
        if(*s != ' '){
            break;
        }
        s++;
    }
    //s is not at the end we know non space exists
    return (*s == '\0') ? 0 : 1;    
}

// int main(int argc, char const *argv[])
// {
//     char* s[6] = {"Hello", "bye", " ", "  ", " ", '\0'};
//     char** s1 =  s;

//     rm_empties(s);
//     while(**s1 != '\0'){
//         printf("%s\n", *s1);
//         s1++;
//     }
//     return 0;
// }
