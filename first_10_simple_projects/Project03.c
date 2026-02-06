/* * TITLE: Project 03 - Number Guessing Game
 * OBJECTIVE: Learn 'while' loops and how to use external library functions.
 * * MAN PAGES TO READ:
 * 1. 'man 3 rand'  -> Returns a pseudo-random integer.
 * 2. 'man 3 srand' -> Sets the seed for rand().
 * 3. 'man 3 time'  -> Used to get the current system time for the seed.
 *
 * TO-DO HINTS:
 * 1. Seed the randomizer: srand(time(NULL));
 * 2. Generate a target: int target = (rand() % 100) + 1;
 * 3. Create a 'while' loop that runs as long as (guess != target).
 * 4. Inside: tell the user if their guess is "Too High" or "Too Low".
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, target;
    char *guess_result;
    // run srand() first to start the seed. 
    // Since time changes every seconds it is a good seed to use with less setup.
    srand(time(NULL));

    //now that it ran, rand() will look for srand to produce a random number.

    target = (rand() % 100) + 1;

    printf("Pick a number from 1 to 100: ");
    scanf("%d", &guess);


    while (guess != target) {


        guess_result = (guess < target) ? "Too low\n" : "Too high\n";
        
        /** if (guess < target) {
             guess_result = "To low\n";

        } else {
            guess_result = "To high\n";

        } */

        printf(
            "\n"
            "Your guess was %s\n"
            "Guessed number: %d\n",
            guess_result,
            guess
        );
        printf("Guess again: ");
        scanf("%d", &guess);
    
    }

    if (guess == target) {
        printf(
            "\nYour Guess Was Correct!\n"
            "Your Guess was: %d and the target was %d",
            guess,
            target
        );

    }
        


    return 0;
}