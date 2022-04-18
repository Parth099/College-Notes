int find(char *h, char *n){

    char* hSubPtr = h;

    //ptrs to start of arr
    char* hDefault = h;
    char* nDefault = n;
    //loop over main str h
    while(*h != '\0'){

        //start search
        if(*h == *n){

            //hSubPtr for backtracking to orig pos
            hSubPtr = h;
            //move pointer until NUL or chars are not same
            while(*h != '\0' && *n != '\0' && *h == *n){
                h++;
                n++;
            }

            //if n has hit NIL str has been found
            if(*n == '\0'){
                //sub of n - nDefault since we count that many chars from first occurence
                return (h - hDefault) - (n - nDefault); //distance from start (0-based)
            }

            //move pointers back to regular positions
            h = hSubPtr;
            n = nDefault;

        }
        h++;
    }
    //if loop ends w/o ret no charset exists
    return -1;

}
// int main(int argc, char const *argv[])
// {
//     char* h = "Hello";
//     char* n = "ello";
//     printf("%d", find(h, n));
//     return 0;
// }
