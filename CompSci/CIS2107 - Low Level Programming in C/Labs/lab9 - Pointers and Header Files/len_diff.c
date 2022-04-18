int len_diff(char *s1, char *s2){
    int diff = 0;

    //close out the shorter one
    while(*s1 != '\0' && *s2 != '\0'){
        s1++;
        s2++;
    }

    while(*s1 != '\0'){
        s1++;
        diff++;
    }

    while(*s2 != '\0'){
        s2++;
        diff++;
    }

    return diff;
}

// int main(int argc, char const *argv[])
// {
//     char* s1 = "Philadelphia";
//     char* s2 = "Hello";

//     printf("%d", len_diff(s2, s1));
//     return 0;
// }
