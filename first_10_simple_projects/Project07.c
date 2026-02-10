/* * TITLE: Project 07 - Simple Word Counter
 * OBJECTIVE: Handle multi-word input and basic logic states.
 * * MAN PAGES TO READ:
 * 1. 'man 3 fgets' -> Unlike scanf, this captures spaces! Use 'stdin'.
 *
 * TO-DO HINTS:
 * 1. Use fgets(buffer, 100, stdin) to get a full sentence.
 * 2. A word starts when you find a character that isn't a space (' ').
 * 3. A simple way: count a word every time current char is NOT a space 
 * but the NEXT char IS a space or '\0'.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define isTrue 1
#define isFalse 0

int main() {
    // set a var to make it a little more readable 
    char isSpace = ' ';
    char isEnd = '\0';
    int startedEmpty = isFalse;

    // set a buffer 
    char buffer[100];

    // Set if you in or out of a word
    int inWord = 0;

    // initilize my count to 1 
    int count = 0;


    printf("Type in what ever you want and ill get a word count!\n: ");
    fgets(buffer, 100, stdin);

    // check for an empty strong or if its all white space.
    if (buffer[0] == isSpace || buffer[0] == isEnd) {
        startedEmpty = isTrue;
    }

    /*  loop through the string to check for white space or if you entered into letters
        once the end of the white space is found and a letter is found it counts as a word
        doesn't make sure the word is real tho. 
    */
    for (int i = 0; i < strlen(buffer); i++) {
        if (buffer[i] == isSpace && startedEmpty == isFalse) {
            inWord = 0;
        } else if (inWord == 0 && isalpha(buffer[i])) {
            inWord = 1;
            count++;
            if (startedEmpty) {startedEmpty = isFalse;}
        }
        
    }

    //  if the string is empty with no words it returns early with a different message
    if (count == 0 || startedEmpty == isTrue) {
        printf("Nothing was entered. Word count: %d", count);
        return 0;
    }

    //  prints the result
    printf("Word Count is: %d", count);

    return 0;
}