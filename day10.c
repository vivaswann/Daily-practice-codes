/*
====================================================
PROBLEM STATEMENT — KAPREKAR ROUTINE (6174)
====================================================

Kaprekar's constant is a number (6174) discovered by
mathematician D. R. Kaprekar.

The routine works as follows for any 4-digit number
(not all digits equal):

1. Rearrange the digits to form the largest possible number.
2. Rearrange the digits to form the smallest possible number.
3. Subtract the smaller number from the larger one.
4. Repeat the process with the resulting number.

This process always reaches 6174 in a finite number
of steps.

----------------------------------------------------
TASK
----------------------------------------------------

Write a C program that:

1. Takes a 4-digit number as input.
2. Applies Kaprekar’s routine repeatedly.
3. Prints each step of the process.
4. Prints the number of steps taken to reach 6174.

----------------------------------------------------
RULES
----------------------------------------------------

- Input must be a 4-digit number.
- Not all digits should be the same.
- Do NOT use arrays for sorting.
- Use only loops, conditionals, and arithmetic.

----------------------------------------------------
SAMPLE INPUT
----------------------------------------------------

3524

----------------------------------------------------
SAMPLE OUTPUT
----------------------------------------------------

5432 - 2345 = 3087
8730 - 0378 = 8352
8532 - 2358 = 6174
Steps taken: 3

====================================================
*/

#include <stdio.h>

int main() {
    int n;
    int steps = 0;

    scanf("%d", &n);

    while (n != 6174) {
        int a, b, c, d;
        int max, min;

        a = n / 1000;
        b = (n / 100) % 10;
        c = (n / 10) % 10;
        d = n % 10;

      
        int x, y, z, w;
        x = a; y = b; z = c; w = d;

       
        max = 0;
        for (int i = 0; i < 4; i++) {
            int m = x;
            if (y > m) m = y;
            if (z > m) m = z;
            if (w > m) m = w;

            max = max * 10 + m;

            if (x == m) x = -1;
            else if (y == m) y = -1;
            else if (z == m) z = -1;
            else w = -1;
        }

        
        x = a; y = b; z = c; w = d;

        min = 0;
        for (int i = 0; i < 4; i++) {
            int m = 9;
            if (x != -1 && x < m) m = x;
            if (y != -1 && y < m) m = y;
            if (z != -1 && z < m) m = z;
            if (w != -1 && w < m) m = w;

            min = min * 10 + m;

            if (x == m) x = -1;
            else if (y == m) y = -1;
            else if (z == m) z = -1;
            else w = -1;
        }

        printf("%04d - %04d = %04d\n", max, min, max - min);

        n = max - min;
        steps++;
    }

    printf("Steps taken: %d\n", steps);

    return 0;
}

