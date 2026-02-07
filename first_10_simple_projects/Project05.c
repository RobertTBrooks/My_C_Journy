/* * TITLE: Project 05 - Password Strength Checker
 * OBJECTIVE: Learn to iterate through strings and use character classification.
 * * MAN PAGES TO READ:
 * 1. 'man 3 isupper' -> Returns non-zero if character is uppercase.
 * 2. 'man 3 isdigit' -> Returns non-zero if character is 0-9.
 *
 * TO-DO HINTS:
 * 1. Create two 'flag' variables: int hasUpper = 0; int hasDigit = 0;
 * 2. Loop through the user's string: while(pass[i] != '\0').
 * 3. If isupper(pass[i]), set hasUpper to 1. 
 * 4. After the loop, if (hasUpper && hasDigit), the password is "Strong".
 */

#include <stdio.h>      // printf, getchar, putchar, fflush
#include <ctype.h>      // islower, isupper, isdigit, ispunct
#include <string.h>     // strlen
#include <termios.h>    // terminal control (disable echo)
#include <unistd.h>     // STDIN_FILENO

/*
    "Visual booleans"

    C does not have a built-in true/false keyword (unless you use stdbool.h).
    Under the hood, booleans are just integers:

        0  -> false
        non-zero -> true

    These macros exist ONLY to make your code more readable.
*/
#define isTrue 1
#define isFalse 0

/* Function declarations (prototypes)
   These tell the compiler what functions exist before main()
*/
int PasswordChecker(char *password);
void DisableEcho(struct termios *old);
void RestoreEcho(const struct termios *old);
char *ProtectedInput(char *userInput);

int main() {
    /*
        Stack-allocated buffer for the password.
        This memory belongs to main() and stays valid
        for the entire lifetime of the program.
    */
    char userInput[100];
    
    /*
        Print password rules.
        Adjacent string literals are concatenated by the compiler.
    */
    printf(
        "Password must have the following:\n"
        "Atleast 1 Cappital letter\n"
        "Atleast 1 Lower case letter\n"
        "Atleast 1 Number (0-9)\n"
        "And 1 Special Character\n"
        "No spaces are allowed\n"
    );
    
    /*
        Loop until PasswordChecker returns true (non-zero).

        ProtectedInput() fills userInput.
        PasswordChecker() inspects its contents.
    */
    while (!PasswordChecker(ProtectedInput(userInput))) {
        printf(
            "Password didn't meet the requirments\n"
        );
        
    }

    //If you exit the loop than your password passed
    printf("Your Password is Strong!");


    return 0;
}


/*
    PasswordChecker

    Walks through each character of the password and checks:
    - uppercase letters
    - lowercase letters
    - digits
    - special characters
*/

int PasswordChecker(char *password) {

    int hasUpper = 0,hasDigit = 0,hasSpecialChar =0 ,hasLower = 0;
    int index = 0,totalLen = 0, requireLen = 8;
    

    /*
        Loop through the string until we reach the null terminator.
        strlen() returns the number of characters before '\0'.
    */
    while (index < strlen(password)) {
        
        /*
            Each ctype function returns non-zero if true.

            Ternary operator is used here purely for side effects.
            If the condition is true, increment the counter.
            Otherwise, do nothing ((void)0).
        */
        islower(password[index]) ? hasLower++ : (void)0;
        isupper(password[index]) ? hasUpper++ : (void)0;
        isdigit(password[index]) ? hasDigit++ : (void)0;
        ispunct(password[index]) ? hasSpecialChar++ : (void)0;
        
        index++;
    }
    totalLen = hasLower + hasUpper + hasDigit + hasSpecialChar;

    /*
        If ANY requirement is missing, fail.
        0 means false, non-zero means true.
        And the required length needs to be met
    */
    if ((!hasUpper || !hasLower || !hasDigit || !hasSpecialChar) && totalLen >= requireLen ) {
        return isFalse;
    } else {
        return isTrue;
    }

}

/*
    DisableEcho

    Turns off terminal echo so typed characters
    are NOT shown on screen.
*/
void DisableEcho(struct termios *old) {
    struct termios new;

    /*
        Get current terminal settings and save them in *old.
        This allows us to restore them later.
    */
    tcgetattr(STDIN_FILENO, old);

    
    //  Copy old settings into new so we only modify what we need.
    new = *old;

    /*
        Clear the ECHO flag.
        This tells the terminal:
        "Do not automatically print typed characters."
    */
    new.c_lflag &= ~ECHO;

    
    //  Apply new terminal settings immediately.
    tcsetattr(STDIN_FILENO, TCSANOW, &new);
}


/*
    RestoreEcho

    Restores terminal settings back to what they were
    before DisableEcho was called.
*/
void RestoreEcho(const struct termios *old) {
    tcsetattr(STDIN_FILENO, TCSANOW, old);
}


/*
    ProtectedInput

    Reads a password from stdin while:
    - disabling terminal echo
    - printing '*' for each character typed
    - safely storing input in caller-provided buffer
*/
char *ProtectedInput(char *userInput) {
    struct termios old;

    int i = 0;
    int ch;

    printf("\nEnter in a password: ");
    fflush(stdout); // Force prompt to appear immediately


    //  Disable echo BEFORE reading input.
    DisableEcho(&old);


    /*
        Read characters one at a time.
        Stop if:
        - Enter is pressed
        - EOF is reached
        - buffer limit is reached
    */
    while ((ch = getchar()) != '\n' && ch != EOF && i < 99) {
        userInput[i++] = ch;
        //Print masking character instead of actual input.
        putchar('*');
        fflush(stdout);
    }

    /*
        Null-terminate the string.
        This is CRITICAL in C.
    */
    userInput[i] = '\0';

    // Restore terminal echo.
    RestoreEcho(&old);
    putchar('\n');

    return userInput;
}