#include <stdio.h>
#include "words.h"

int main()
{
    if (isAlphaChar('c'))
        printf("C is alpha.\n");
    
    if (isAlpha("Casa"))
        printf("Casa is alpha.\n");

    if (isAlphaNumericChar('8'))
        printf("8 is alpha numeric.\n");
    
    if (isAlpha("Casa9"))
        printf("Casa9 is alpha numeric.\n");
    
    if (isAlphaChar('7'))
        printf("7 is alpha.\n");
    
    if (isAlpha("Casa7"))
        printf("Casa7 is alpha.\n");

    if (isAlphaNumericChar(','))
        printf(", is alpha numeric.\n");
    
    if (isAlpha(","))
        printf(", is alpha numeric.\n");

    if (compare("Word", "Word"))
        printf("Word is equal to Word.\n");

    if (compare("word", "Word"))
        printf("word is equal to Word.\n");

    char word1[] = "hello world";
    char word2[] = "HELLO WORLD";
    char word3[] = "marcelo";
    char word4[] = "123456789";

    printf(":%s, %s, %s, %s\n", word1, word2, word3, word4);

    toUpper(word1);
    toLower(word2);
    capitalize(word3);
    title(word4);

    printf(":%s, %s, %s, %s\n", word1, word2, word3, word4);

    title(word1);
    title(word2);
    title(word3);

    printf(":%s, %s, %s, %d\n", word1, word2, word3, lenght(word4));

    return 0;
}