/* * TITLE: Project 02 - Grade Calculator
 * OBJECTIVE: Understand 'if-else' logic and integer comparisons.
 * * MAN PAGES TO READ:
 * 1. 'man 3 printf' -> Look for %d (integers).
 * * TO-DO HINTS:
 * 1. Get an integer input (0-100) from the user.
 * 2. Use 'if (score >= 90)' for an 'A'.
 * 3. Use 'else if' for B (80), C (70), and D (60).
 * 4. Use a final 'else' to catch failing grades (F).
 * 5. Handle edge cases: what if the user enters 110 or -5?
 */

#include <stdio.h>

int main() {
    int grade;

    printf("Enter your grade between 0 and 100: ");
    scanf("%d", &grade);
    printf("\n");
    
    while (grade == 0 || grade > 100 || grade < 0) {
        printf("Incorrect Value: %d must be between 0 and 100.\n"
            "Enter a new value: ", grade);
        scanf("%d", &grade);
        printf("\n");
    }

    if (grade >= 90) {
        printf("You Got an A!\n");

    } else if (grade >= 80 && grade < 90) {
        printf("You Got a B!\n");

    } else if (grade >= 70 && grade < 80) {
        printf("You Got a C.\n");

    } else if (grade >= 60 && grade < 70) {
        printf("You Got a D..");

    } else {
        printf("Yikes bud.. thats an F..");
    }
    
    return 0;
}