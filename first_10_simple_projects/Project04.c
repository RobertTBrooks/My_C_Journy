/* * TITLE: Project 04 - String Reverser
 * OBJECTIVE: Understand character arrays and the 'null terminator' (\0).
 * * MAN PAGES TO READ:
 * 1. 'man 3 strlen' -> Returns the number of characters (excluding \0).
 *
 * TO-DO HINTS:
 * 1. Declare a char array: char word[100];
 * 2. Use scanf("%s", word) to get a single word.
 * 3. Get the length using strlen(word).
 * 4. Use a 'for' loop to print. IMPORTANT: The last index is (length - 1).
 * 5. Loop condition: for (int i = length - 1; i >= 0; i--)
 */

#include <stdio.h>
#include <string.h>

char *String_Reverser(char *string_to_rev);
char *String_Reverser_strlen(char *reversed_str, char *user_input);

int main() {
    // Set my string arrays [MAX_SIZE_OF_ARRY] <- in here you can set the char count allowed
    char user_input[100];
    char string_to_rev[100];
    // For getting the index for my reversed string to track the placment 
    
    printf("Type in a word and ill reverse it!: ");
    // Using fgets to not ignore spaces and read it generally is safer
    fgets(user_input, sizeof(user_input), stdin);
    
    // 99 to keep it from overflowing and leaving 1 for '\0' to terminate array
    // scanf("%99s", user_input);
    printf("\n");

    // Making a copy for visual return 
    // using strncpy and ensuring a terminator '\0'
    strncpy(string_to_rev, user_input, sizeof(string_to_rev) - 1);
    string_to_rev[sizeof(string_to_rev) - 1] = '\0';

    //Running this fuction will alter the memory address of 
    // the userinput that was created 
    String_Reverser(string_to_rev);


    //Print results
    printf(
        "You word was: %s\n"
        "The Reversed is: %s\n",
        user_input,
        string_to_rev
    );

    return 0;
}

char *String_Reverser(char *string_to_rev) {
    //this function is to use points and no strlen method
    //This function will effect the original data since its using a pointer!

    // strip \n off the end of the input to prevent the out from making a new line
    string_to_rev[strcspn(string_to_rev, "\n")] = '\0';

    char *start = string_to_rev;
    char *end = string_to_rev;

    //find the End
    //this uses a pointer to look into its memory location NOT a copy of a char
    while (*end != '\0') {
        end++;
    }

    end--; // step back from '\0'


    // now lets swop the chars in place instead of a for loop copy
    while (start < end) {
        char temp_start = *start;

        *start = *end;
        *end = temp_start;

        start++;
        end--;
    }

    

    return string_to_rev;

}


// First tried with strlen just here collecting dust now
char *String_Reverser_strlen(char *reversed_str, char *user_input) {
    int index_count = 0;

    // Go backwards in the users input and place the char's into the return array.
    for (int i = strlen(user_input) - 1; i >= 0; i--) {

        //[index++] will place in the current index 0 and after placing it then +1
        //while i returns the back end of the user input index tracks the front.
        reversed_str[index_count++]=user_input[i];
    }

    //sets a terminator at the end of the string.
    reversed_str[index_count] = '\0';

    return reversed_str;
}