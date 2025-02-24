/*
QUESTION:
If you've done COSC121 you may remember Herbert the Heffalump, who climbs scree slopes in a series of rushes. [See the definition of "scree" below.] Each rush gains him a certain amount of height rushHeight, but then, unless he is already at the top, he slips back down again by an amount slideBack. Write a function to help Herbert determine how many rushes it will take him to get to the top of a scree slope of a given height.

The function, uint32_t countRushes(float screeHeight, float rushHeight, float slideBack), should return the number of rushes it takes Herbert to get to the top. You may assume that screeHeight and slideBack are both non-negative and that rushHeight is greater than slideBack.

Consider whether any of the built in loop constructs (while, do-while, or for) are really a good fit to this problem.

Once you've got the program working with one of the loop constructs, try implementing it using the other two. [Once you have full marks you can experiment without penalty to your heart's content.]

Note: "scree" is loose gravel that tends to slide backwards underfoot as you go up a hill.

ANSWER:
gcc -o herbert -Werror herbert.c
*/

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

uint32_t countRushes(float screeHeight, float rushHeight, float slideBack)
{
    // Here i is number of rushes
    float interim_height = 0;
    float number_of_rushes = 0;

    while (interim_height < screeHeight) {
        if ((interim_height + rushHeight) >= screeHeight) {
            interim_height += rushHeight;
        } else {
            interim_height += rushHeight - slideBack;
        }

        number_of_rushes += 1;
    }

    return number_of_rushes;
}

int main(void)
{
    printf("%d\n", countRushes(100, 50, 10));
    printf("%d\n", countRushes(100, 100, 90));
    printf("%d\n", countRushes(0, 100, 30));
    printf("%d\n", countRushes(1.0, 0.5, 0.1));
}