#include <stdio.h>
#include "my_string.h"

    /*
        STEPS TO COMPILE
        gcc -c *.c
        ar rcs libmy_string.a *.o
        gcc -o strtest strtest.c -L. -lmy_string
    */

int main(int argc, char const *argv[])
{

    //test for all_letters
    char *s1 = "abcdefghijklmnopqrstuvwxyz";
    char *s2 = "abcdefghijklmnopqrstuvwxa";

    puts("all_letters Test: ");
    //s1
    if(all_letters(s1)){
        printf("s1: %s contained all the letters", s1);
    }
    else{
        printf("s1: %s did not contain all the letters", s1);
    }

    puts(" ");
    //s2
    if(all_letters(s2)){
        printf("s2: %s contained all the letters", s2);
    }
    else{
        printf("s2: %s did not contain all the letters", s2);
    }

    puts("\n\nnum_in_range test");
    char start = 'a';
    char end = 'd';
    //should be 5
    printf("In s2: %s there are %d letters between %c and %c", s2, num_in_range(s2, start, end), start, end);

    puts("\n\ndiff");
    char* s3 = "Hello";
    char* s4 = "Mellow";
    printf("The diff between %s and %s is %d", s3, s4, diff(s3, s4));

    puts("\n\nshorten");
    char s5[11] = "Watermelon";
    int newSz = 5;
    printf("%s reducted to a length of %d is: ", s5, newSz);
    shorten(s5, newSz);
    printf("\"%s\"", s5);

    puts("\n\nlen_diff");
    char s6[11] = "Watermelon";
    printf("The length difference between %s and %s is %d", s3, s6, len_diff(s3, s6));

    //5

    puts("\n\nrm_left_space");
    char sp[16] = "   Hello";
    printf("\'%s\' after removing spaces is ", sp);
    rm_left_space(sp);
    printf("\'%s\'", sp);

    puts("\n\nrm_right_space");
    char sp2[16] = "Hello   ";
    printf("\'%s\' after removing spaces is ", sp2);
    rm_right_space(sp2);
    printf("\'%s\'", sp2);

    puts("\n\nrm_space");
    char sp3[16] = "   Hello   ";
    printf("\'%s\' after removing spaces is ", sp3);
    rm_space(sp3);
    printf("\'%s\'", sp3);

    puts("\n\nfind");
    char* f1 = "chairs and tables";
    char* f2 = "and";
    printf("\'%s\' is found in \'%s\' at index %d (0-based indexing)", f2, f1, find(f1, f2));

    puts("\n\nptr_to");
    printf("\'%s\' is found in \'%s\' at pointer %p", f2, f1, ptr_to(f1, f2));

    //10

    char* e1 = "    ";
    char* e2 = "crate";
    puts("\n\nis_empty");
    printf("e1: \"%s\"\nisEmpty: %d\n\n", e1, is_empty(e1));
    printf("e2: \"%s\"\nisEmpty: %d", e2, is_empty(e2));

    puts("\n\nstr_zip");
    char* z1 = "Temple";
    char* z2 = "Hello";
    printf("%s zipped with %s is '%s'", z1, z1, str_zip(z1, z2));

    puts("\n\ncapitalize");
    char sent[12] = "i like cake";
    printf("%s capitalized is ", sent);
    capitalize(sent);
    printf("'%s'", sent);

    puts("\n\nstrcmp_ign_case");
    char* c1 = "stRingS";
    char* c2 = "StrinGs";
    int result_compare = strcmp_ign_case(c1, c2);
    printf("%s compared with %s is %d", c1, c2, result_compare);
    if(result_compare == 0){
        printf("\nThey are equal");
    }


    puts("\n\ntake_last");
    char c3[6] = "mango";
    char last = 2;
    printf("The last %d chars of %s are ", last, c3);
    take_last(c3, last);
    printf("%s", c3);

    //15

    puts("\n\ndedup");
    char d1[12] = "Hi everyone";
    printf("removing duplicates from %s: %s", d1, dedup(d1));

    puts("\n\npad");
    char p1[12] = "Hello";
    int numSpaces = 7;
    printf("Padding '%s' with %d spaces is '%s'", p1, numSpaces, pad(p1, numSpaces));

    puts("\n\nends_with_ignore_case");
    char end1[7] = "Coding";
    char suff[5] = "ding";
    int result_ends = ends_with_ignore_case(end1, suff);
    if(result_ends){
        printf("'%s' ends with '%s'", end1, suff);
    }
    else{
        printf("'%s' does not end with '%s'",  end1, suff);
    }

    puts("\n\nrepeat");
    char* str = "Pointers";
    int num_rep = 4;
    char sep = '-';
    printf("%s repeated %d times sperated by %c is '%s'", str, num_rep, sep, repeat(str, num_rep, sep));

    puts("\n\nreplace");
    char* toReplace = "burger king has the best burger";
    char* replacement = "burger";
    char* replacer = "sandwich";
    printf("'%s' where '%s' is replaced with '%s' is \"%s\"", toReplace, replacement, replacer, replace(toReplace, replacement, replacer));
    
    //20

    puts("\n\nstr_connect");
    int size = 5;
    char* connect[5] = {"I", "Love", "all", "lab", "assignments"};
    char seperator = '_';
    printf("%s", str_connect(connect, size, seperator));


    puts("\n\nrm_empties");
    char* words[7] = {"Hello", " ", " ", "bye", "hi", 0};
    rm_empties(words);
    int c = 0;
    puts("Notice how no spaces are printed:");
    while(*(words + c) != 0){
        printf("%s\n", *(words + c));
        c++; //haha
    }

    puts("\n\nstr_chop_all");
    char chop_delimiter = '/';
    char* str_to_chop = "I/am/ready/for/a/nice/vacation";
    char** chopped = str_chop_all(str_to_chop, chop_delimiter);
    printf("string to chop: '%s', on delimiter %c\n", str_to_chop, chop_delimiter);
    int i = 0;
    while (**(chopped + i) != '\0')
    {
        printf("%s\n", *(chopped + i));
        i++;
    }
    
}