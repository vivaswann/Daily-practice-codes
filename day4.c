/*You are given an integer N (1 ≤ N ≤ 12) representing an hour on a 12-hour clock.

The clock behaves abnormally:

If the current hour is even, the clock moves forward by 1 hour.

If the current hour is odd, the clock moves backward by 1 hour.

Starting from hour N, the clock updates its hour exactly N times.

Write a C program to print the final hour displayed on the clock.

Rules:

The clock wraps around (after 12 comes 1, before 1 comes 12).

Do not use arrays or recursion.

Input:
An integer N

Output:
An integer representing the final hour on the clock.

Example:

Input:
5

Output:
4*/

#include <stdio.h>

int main() {
    int n, hour;

    printf("Enter hour: ");
    scanf("%d", &n);

    hour = n;

    for (int i = 1; i <= n; i++) {
        if (hour % 2 == 0) {
            hour = hour + 1;   
        } else {
            hour = hour - 1;   
        }
        if (hour > 12)
            hour = 1;
        if (hour < 1)
            hour = 12;
    }

    printf("Final hour: %d", hour);

    return 0;
}
