#include <stdio.h>
#include <string.h>

int main(){
    char c = 'a';
    printf("%c\n", c+1);

    char* s = "aaa";
    printf("%c\n" , *(s+1) + 1);

    char* str = "hello";

    //using ASCII table, and a pointer to str, print str in uppercase.
   

    return 0;
}