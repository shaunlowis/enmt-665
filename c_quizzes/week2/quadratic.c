/*
QUESTION:

Write a function

void printRoots(float a, float b, float c)

that takes three floating point values and prints the solution to the quadratic equation

ax2+bx+c=0

If the equation is not a quadratic (because a is zero), the output is

`Not a quadratic`

If the roots are imaginary the output is

`Imaginary roots`

Otherwise, the output is of the form

`Roots are -1.0000 and 1.0000`

where both roots are printed with 4 decimal digits after the decimal point. The smaller root should be printed first.

The solution to ax2+bx+c=0 is:

x=−b±(√b2−4ac)2a

Notes:

In order to use the sqrt() function, you have to tell the compiler what type it is, i.e. what type parameters it takes and what type it returns. This is done by adding the line #include <math.h> right after the #include <stdio.h> line. That's all you have to do when submitting to the quiz server. However, when you're building the program on a lab machine you also need to tell the linker what libraries it must search to find the actual code for sqrt(). To do this, add the option -lm (that's a lower-case L not the number one) at the end of the compile-and-build command line. You therefore will compile with something like gcc -Werror -Wall -o q18 q18.c -lm
Remember the motto DRY ("Don't Repeat Yourself"). Writing multiple copies of the expression
(√b2−4ac) is ugly and error prone.

ANSWER:
gcc -Werror -Wall -o quadratic quadratic.c -lm

*/

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

void printRoots(float a, float b, float c)
{
    float discriminant = sqrt((b * b) - 4 * a * c);

    if (a == 0) {
        printf("Not a quadratic\n");
    } else {
        if (discriminant >= 0) {
            float x1 = ((-1 * b) - sqrt((b * b) - 4 * a * c)) / (2*a);
            float x2 = ((-1 * b) + sqrt((b * b) - 4 * a * c)) / (2*a);

            if (x1 < x2) {
                printf("Roots are %.4f and %.4f\n", x1, x2);
            } else {
                printf("Roots are %.4f and %.4f\n", x2, x1);
            }
            
        } else {
            printf("Imaginary roots\n");
        }
    }
}

int main(void)
{
    printRoots(1, -4, 3);
    printRoots(1, 2, 3);
    printRoots(0, 2, 3);
    printRoots(1, 0, -1);
}