/* * TITLE: Project 01 - Temperature Converter
 * OBJECTIVE: Master basic variables, user input, and floating-point math.
 * * MAN PAGES TO READ:
 * 1. 'man 3 printf' -> Search for "Conversion Specifiers" (specifically %f).
 * 2. 'man 3 scanf'  -> Note the use of the '&' (address-of) operator.
 *
 * TO-DO HINTS:
 * 1. Declare two 'float' variables: celsius and fahrenheit.
 * 2. Use scanf("%f", &celsius) to capture user input.
 * 3. Calculation: fahrenheit = (celsius * 9 / 5) + 32;
 * 4. Print the result using %.2f to limit the output to two decimal places.
 */

#include <stdio.h>

int main() {
    // Your code starts here:
    float celsius, fahrenheit;
    printf("Enter in your temp in Celsius to convert to Fahrenheit: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * (9.0 / 5)) + 32;

    printf("\nTemp in Fahrenheit is: %.2f\n", fahrenheit);
    
    return 0;
}