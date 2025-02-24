/*
QUESTION:
Write a function

void printPrimesInRange(uint32_t n1, uint32_t n2)

that prints all the prime numbers between n1 and n2 inclusive.

A simplistic algorithm with nested loops is all that's expected here. 
The outer loop iterates through all integers in the range n1 to n2 inclusive. 
The inner loop iterates through all the integers from 2 to n - 1 inclusive, 
checking if each one is a factor of the current number n whose 'primeness' is being assessed. 

More efficient algorithms exist, however, and you're welcome to try to find one if you wish.

ANSWER:
gcc -o primes -Werror primes.c
*/

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

void printPrimesInRange(uint32_t n1, uint32_t n2)
{
    // Have a case for 2:
    if (n1 <= 2) {
        printf("2\n");
        n1 = 3;
    }

    // Now for any range greater than 2, number should only be divisible by itself.
    for (int32_t i = n1; i <= n2; i++) {
        bool curr_i_prime = true;

        for (int32_t j = 2; j < i; j++) {
            if (i % j == 0) {
                curr_i_prime = false;
            }
        }

        if (curr_i_prime) {
            printf("%d\n", i);
        }
        
    }
}

int main(void)
{
    printPrimesInRange(2, 40);
}