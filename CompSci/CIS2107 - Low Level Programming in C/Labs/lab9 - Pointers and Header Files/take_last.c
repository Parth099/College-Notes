void take_last(char *s, int n){
    char* head = s;
    int i;
    for(i = 0; *s != '\0'; i++, s++); //moves s to the end and counts size
    
    if(i <= n){
        return; //end if size is already good
    }
    
    char* tail = s;
    s = head; //set s back to head 
    head = tail - n; //moves new head to start copying
    
    //copy until head is not '\0'
    for(int i = 0; head != tail ; i++){
        *s = *head;
        head++;
        s++;
    }
    *s = '\0';  //end string 
}
// int main(int argc, char const *argv[])
// {
//     char s[256] = "hello";
//     take_last(s, 3);
//     printf("%s", s);
//     return 0;
// }
