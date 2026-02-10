/* * TITLE: Project 06 - File Content Printer
 * OBJECTIVE: Open, read, and close physical files on your disk.
 * * MAN PAGES TO READ:
 * 1. 'man 3 fopen'  -> Look for the "r" mode (read).
 * 2. 'man 3 fgetc'  -> Reads a single character until EOF (End Of File).
 * 3. 'man 3 fclose' -> Crucial for preventing memory/file leaks.
 *
 * TO-DO HINTS:
 * 1. Declare a FILE pointer: FILE *fp;
 * 2. Open it: fp = fopen("test.txt", "r");
 * 3. Check if (fp == NULL) -> This means the file doesn't exist!
 * 4. Loop: while ((ch = fgetc(fp)) != EOF) { printf("%c", ch); }
 */

#include <stdio.h>

int main() {

    // make ch just to track char's
    char ch;

    /*
        make a variable to hold file location NOTE: this will base of were the program was run.
        using a full destination will be better or just capture user input for them to choose
        the file location instead.

        but this was for practice 
    */
    const char *fileLoc = "./Test_Text_Files/Project06_ReadMe.txt";

    //  create a pointer to FILE
    FILE *fp;

    //  define the file with its location and its mode. w => Write r => Read
    fp = fopen(fileLoc, "r");

    //  check to see if the file is valid
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }


    // print out each char in the file and print it out to the consal 
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    //  close the file to avoid memory leaking
    fclose(fp);

    printf("File closed");


    return 0;
}
