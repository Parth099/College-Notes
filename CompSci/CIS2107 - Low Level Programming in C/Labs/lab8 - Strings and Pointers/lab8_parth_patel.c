/*
 * Name:	Parth Patel
 * Section:	03
 * Lab:  	CIS2107_Lab08_Manual 
 * Goal: 	To design and implement functions taking pointers as arguments 
			to process characters and strings.
 */

#define SIZE_OF_SERIES 5

#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

//functions prototypes
void upperLower(const char * s);
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4);
void compareStr(const char *s1, const char *s2);
void comparePartialStr(const char *s1, const char *s2, int n);
void randomize(void);
void tokenizeTelNum(char *num);
void reverse(char *text);
int countSubstr (char * line, char * sub);
int countChar (char * line, char c);
int countWords(char *string);
void countAlpha(char *string);
void startsWithB(char *string[]);
void endsWithed(char *string[]);

//helpers
char* genSentence(void);
char* copyToStrFrom(char* dest, char*  word);
void pushChar(char* dest, char c);

//globals
const char article[5][5] = {"the", "a", "one", "some", "any"};
const char subject[5][5]  = {"boy", "girl", "dog", "town", "car"};
const char verb[5][8]  = {"drove", "jumped", "ran", "walked", "skipped"};
const char prepo[5][6]  = {"to", "from", "over", "under", "on"};



int main() {

    //random generator
    srand(time(NULL));

    //test for upperLower
    puts("UpperLower:");
    const char test[] = "This iS A Test";
    upperLower(test);


    //test for convertStrtoInt
    puts("\n\nString -> int:");
    printf("The sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));

    //test for convertStrtoFloat
    puts("\n\nString -> float:");
    printf("The sum of 4 strings is: %.2f", convertStrtoFloat("3.5", "4.5", "5.5", "6.5"));


    puts("\n\nCompareStr");
    //test for compareStr
    compareStr("Test1", "Test2");

    //test for comparePartialStr
    puts("\nCompareStr - Partial");
    comparePartialStr("Test1", "Test2", 4);

    //test for randomize
    puts("");
    randomize();

    puts("\n");
    //test for tokenize number
    char str[] = "(267) 436-6281";
    tokenizeTelNum(str);

    puts("\nReverse Words");
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
    puts(" ");
    char countstring[] = "hello world!";
    printf("\n\nNumber of words in string is: %d\n", countWords(countstring));

    puts("\nwords starting with 'b':"); //not "B"
    char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
    startsWithB(series);


    //test for endsWithed
    puts("\nwords ending with 'ed':");
    endsWithed(series);
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
    return (rand() % limit);
}

void pushChar(char* dest, char c){
    *dest = c;
}

char* genSentence(void) {
    const int LIMIT = 5;
    //article, noun, verb, preposition, article and noun.
    static char sentence[50]; //50 to ensure no segfaults
    char *endPoint = sentence;
    //copy article
    strcpy(endPoint, article[randInt(LIMIT)]);
    endPoint = sentence + (strlen(sentence)); //move pointer fwd LEN space to drop a space
    pushChar(endPoint, ' ');
    endPoint++;

    strcpy(endPoint, subject[randInt(LIMIT)]);
    endPoint = sentence + (strlen(sentence)); //move pointer fwd LEN space to drop a space
    pushChar(endPoint, ' ');
    endPoint++;

    strcpy(endPoint, verb[randInt(LIMIT)]);
    endPoint = sentence + (strlen(sentence)); //move pointer fwd LEN space to drop a space
    pushChar(endPoint, ' ');
    endPoint++;

    strcpy(endPoint, prepo[randInt(LIMIT)]);
    endPoint = sentence + (strlen(sentence)); //move pointer fwd LEN space to drop a space
    pushChar(endPoint, ' ');
    endPoint++;

    strcpy(endPoint, article[randInt(LIMIT)]);
    endPoint = sentence + (strlen(sentence)); //move pointer fwd LEN space to drop a space
    pushChar(endPoint, ' ');
    endPoint++;

    strcpy(endPoint, subject[randInt(LIMIT)]);
    endPoint = sentence + (strlen(sentence)); //move pointer fwd LEN space to drop a space
    pushChar(endPoint, '.');
    endPoint++;

    *sentence = toupper(*sentence);
    pushChar(endPoint, '\0');
    return sentence;
}
//6.(Random Sentences) 
void randomize(void){
    for(int i = 0; i < 20; i++){
        printf("%s ", genSentence());
    }
}

//7.(Tokenizing Telephone Numbers) 
void tokenizeTelNum(char *num) {
    char* token = strtok(num, "()");
    int areaCode;
    unsigned long number = 0;
    int lengthOfToken = 0;
    if(token != NULL){
        areaCode = atoi(token);
    }
    token = strtok(NULL, " -");
    while(token != NULL){

        number *= pow(10, lengthOfToken+1);
        lengthOfToken = strlen(token);
        number += atoi(token);

        token = strtok(NULL, " -");
    }

    printf("%-13s: %d\n%-13s: %lu", "Area Code", areaCode, "Phone Number", number);
}

//8.(Displaying a Sentence with Its Words Reversed) 
void reverse(char *text) {
    size_t length = strlen(text);
    char stringRev[length]; //buffer
    char* token = strtok(text, " .!?");

    //rev the tokens
    while(token != NULL){
        printf("%s\n", strrev(token));
        token = strtok(NULL, " .!?");
    }

}

//9.(Counting the Occurrences of a Substring) 
int countSubstr (char * line, char * sub) {
    int lenSub = strlen(sub);
    int count = 0;
    char* lnPtr = line;
    while((*lnPtr) != '\0'){
        if(strncmp(lnPtr, sub, lenSub) == 0){
            count++;
        }
        lnPtr++;
    } 
    return count;
}

//10.(Counting the Occurrences of a Character) 
int countChar (char *line, char c) {
    int count = 0;
    
    while(*line != '\0'){
        if(*line == c){
            count++;
        }
        line++;
    }
    return count;
}


//11.(Counting the Letters of the Alphabet in a String) 
void countAlpha(char *string) {
    printf("\n%-9s| %-15s", "Letter", "Occurrences");

    int count[26] = {0};
    char curr;

    while(*string != '\0'){
        curr = tolower(*string);
        if(curr >= 'a' && curr <= 'z'){
            count[curr - 'a'] += 1; 
        }
        string++;
    }
    
    for(short i = 0; i < 26; i++){
        if(count[i] > 0)
            printf("\n%-10c %-15d", 'a'+i, count[i]);
    }
}

//12.(Counting the Number of Words in a String) 
int countWords(char *string) {
   int count = 0;
   const char* pattern = " .?!";
   char* token = strtok(string, pattern);

   while(token != NULL){
       count++;
       token = strtok(NULL, pattern);
   }

   return count;
}

//13.(Strings Starting with "b") 
void startsWithB(char *string[]) {
    //array size is a #define const

    for(int i = 0; i < SIZE_OF_SERIES; i++){
        if(*(string[i]+0) == 'b'){ //i put in the  +0 to make it more readable
            printf("%s\n", string[i]);
        }
    }

}

//14.(Strings Ending with "ed") 
void endsWithed(char *string[]) {
    size_t strLength;
    char* lastTwoLetters;
    for(int i = 0; i < SIZE_OF_SERIES; i++){
        strLength = strlen(string[i]);
        if(strLength < 2){
            continue;
        }
        //moves the current string to its 2nd-last char position
        lastTwoLetters = string[i]+(strLength-2);

        //compare string with last two letters
        if(strcmp(lastTwoLetters, "ed") == 0){
            printf("%s\n", string[i]);
        }
    }
}