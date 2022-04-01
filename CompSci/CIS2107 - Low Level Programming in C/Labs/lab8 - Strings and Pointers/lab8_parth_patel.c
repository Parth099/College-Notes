/*
 * Name:	Parth Patel
 * Section:	03
 * Lab:  	CIS2107_Lab08_Manual 
 * Goal: 	To design and implement functions taking pointers as arguments 
			to process characters and strings.
 */


#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//functions prototypes
void upperLower(const char * s);
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4);
void compareStr(const char *s1, const char *s2);
void comparePartialStr(const char *s1, const char *s2, int n);
void randomize(void);
int tokenizeTelNum(char *num);
void reverse(char *text);
int countSubstr (char * line, char * sub);
int countChar (char * line, char c);
int countWords(char *string);
void countAlpha(char *string);
void startsWithB(char *string[]);
void endsWithed(char *string[]);

//helpers

//globals
const char **article = {"the", "a", "one", "some", "any"};
const char **subject = {"boy", "girl", "dog", "town", "car"};
const char **verb = {"drove", "jumped", "ran", "walked", "skipped"};
const char **prepo[] = {"to", "from", "over", "under", "on"};

int main() {

    //random generator
    srand(time(NULL));

    //test for upperLower
    puts("UpperLower:");
    const char test[] = "This iS A Test";
    upperLower(test);


    //test for convertStrtoInt
    printf("\n\nThe sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));

    //test for convertStrtoFloat
    printf("\n\nThe sum of 4 strings is: %.2f", convertStrtoFloat("3.5", "4.5", "5.5", "6.5"));


    puts("\n");
    //test for compareStr
    compareStr("Test1", "Test2");

    //test for comparePartialStr
    comparePartialStr("Test1", "Test2", 4);

    //test for randomize
    randomize();
/*
    //test for tokenize number
    char str[] = "(267) 436-6281";
    tokenizeTelNum(str);

    //test for reverse
    char line[] = "Hello world";
    reverse(line);

    //test for countSubstr
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\n\nNumber of Substrings %s inside %s: %d\n", substring, line1, countSubstr(line1, substring));

    //test for countChar
    char w = 'w';
    printf("\nNumber of character %c inside %s: %d\n", w, line1, countChar(line1, w));

    //test for countAlpha
    char str1[] = "Hello it's me.";
    countAlpha(str1);

    //test for countWords
    char countstring[] = "hello world!";
    printf("\n\nNumber of words in string is: %d\n", countWords(countstring));

    //test for startsWithB
    char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
    startsWithB(series);

    //test for endsWithed
    endsWithed(series);
*/
}

// 1.(Displaying Strings in Uppercase and Lowercase) 
void upperLower (const char * s) {
    
    //new pointer declared because we need `s` for later
    const char *sPtr = s;

    //loop active until string ends
    while(*sPtr != '\0'){
        printf("%c", toupper(*sPtr));
        sPtr++;
    }

    puts("");
    //move the pointer back to location 0
    sPtr = s;
    while(*sPtr != '\0'){
        printf("%c", tolower(*sPtr));
        sPtr++;
    }
}

// 2.(Converting Strings to Integers for Calculations) 
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4) {
    return atoi(s1) + atoi(s2) + atoi(s3) + atoi(s4);
}

//3.(Converting Strings to Floating Point for Calculations) 
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4) {
    return atof(s1) + atof(s2) + atof(s3) + atof(s4);
}

//4.(Comparing Strings) 
void compareStr(const char *s1, const char *s2) {
    int result = strcmp(s1, s2);
    if(result < 0){
        puts("s1 is less than s2");
    }
    else if(result > 0){
        puts("s1 is greater than s2");
    }
    else{
        puts("s1 is equal to s2");
    }
}

//5.(Comparing Portions of Strings) 
void comparePartialStr(const char *s1, const char *s2, int n) {
    short result;
    for(int i = 0; i < n; i++){
        result = *s1 - *s2; //char to int cast and then subtraction of char ascii values
        if(result != 0) break;
        s1++;
        s2++;
    }

    //easier not to use strcmp here.
    if(result < 0){
        puts("s1 is less than s2");
    }
    else if(result > 0){
        puts("s1 is greater than s2");
    }
    else{
        puts("s1 is equal to s2");
    }
    
}

int randInt(int limit){
    return (rand() % limit)+ 1;
}

//6.(Random Sentences) 
void randomize(void) {
   printf("%d %d %d %d", randInt(5), randInt(5), randInt(5), randInt(5));
}

//7.(Tokenizing Telephone Numbers) 
int tokenizeTelNum(char *num) {
  
  
}

//8.(Displaying a Sentence with Its Words Reversed) 
void reverse(char *text) {
    

}

//9.(Counting the Occurrences of a Substring) 
int countSubstr (char * line, char * sub) {
  
  
}

//10.(Counting the Occurrences of a Character) 
int countChar (char *line, char c) {
  
  
}


//11.(Counting the Letters of the Alphabet in a String) 
void countAlpha(char *string) {
 
 
}

//12.(Counting the Number of Words in a String) 
int countWords(char *string) {
   
   
}

//13.(Strings Starting with "b") 
void startsWithB(char *string[]) {

 

}

//14.(Strings Ending with "ed") 
void endsWithed(char *string[]) {


}