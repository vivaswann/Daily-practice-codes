 /*
====================================================
PROBLEM STATEMENT — COLLATZ SEQUENCE ANALYSIS
====================================================

You are given a positive integer N (1 ≤ N ≤ 10^6).

Starting from N, repeatedly apply the following rules
until the value becomes 1:

1. If N is even, divide it by 2.
2. If N is odd, multiply it by 3 and add 1.

This sequence of operations is known as the Collatz
sequence.

----------------------------------------------------
TASKS
----------------------------------------------------

Write a C program that:

1. Takes N as input from the user.
2. Prints the entire Collatz sequence starting from N
   and ending at 1.
3. Counts and prints the total number of steps required
   to reach 1 (excluding the starting number).
4. Determines and prints the maximum value reached
   during the sequence.

----------------------------------------------------
CONSTRAINTS
----------------------------------------------------

- Do NOT use recursion.
- Do NOT use arrays.
- Use only loops and conditional statements.
- Use the data type `long long` to avoid overflow.

----------------------------------------------------
INPUT FORMAT
----------------------------------------------------

A single integer N.

----------------------------------------------------
OUTPUT FORMAT
----------------------------------------------------

1. The Collatz sequence in a single line, space-separated.
2. The total number of steps.
3. The maximum value reached.

----------------------------------------------------
SAMPLE INPUT
----------------------------------------------------

7

----------------------------------------------------
SAMPLE OUTPUT
----------------------------------------------------

7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
Steps: 16
Max value: 52

----------------------------------------------------
NOTE
----------------------------------------------------

The program should terminate once the value reaches 1.
Assume the sequence will always reach 1 for the given
constraints.

====================================================
*/


#include <stdio.h>

int main() {
    long long n;
    long long max;
    int steps = 0;


scanf("%lld", &n);
max = n;
printf("%lld ", n);

  
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }

      
        printf("%lld ", n);

      
        if (n > max) {
            max = n;
        }

     steps++;
    }

    
    printf("\nSteps: %d\n", steps);
    printf("Max value: %lld\n", max);

    return 0;
}
