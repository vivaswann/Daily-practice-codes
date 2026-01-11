/*
====================================================
PROBLEM STATEMENT — SMART TRAFFIC SIGNAL SIMULATION
====================================================

A smart traffic signal operates at a four-way junction.
Each road has a certain number of vehicles waiting.

The signal follows these rules:

1. The road with the highest number of vehicles
   gets the green light.
2. Green light duration is calculated as:
      time = vehicles * 2 seconds
3. If two or more roads have the same number of
   vehicles, priority is given in this order:
      Road A > Road B > Road C > Road D
4. After one road completes its green cycle, its
   vehicle count becomes 0.
5. The system continues until all roads have 0 vehicles.

----------------------------------------------------
TASKS
----------------------------------------------------

Write a C program that:

1. Takes vehicle counts for 4 roads (A, B, C, D).
2. Simulates the traffic signal operation.
3. Prints the order in which roads get the green light
   along with the duration for each.
4. Ends when all roads are cleared.

----------------------------------------------------
CONSTRAINTS
----------------------------------------------------

- Do NOT use arrays.
- Do NOT use recursion.
- Use only loops and conditionals.
- Assume all inputs are non-negative integers.

----------------------------------------------------
INPUT FORMAT
----------------------------------------------------

Four integers representing vehicles on:
Road A, Road B, Road C, Road D

----------------------------------------------------
SAMPLE INPUT
----------------------------------------------------

10 5 10 3

----------------------------------------------------
SAMPLE OUTPUT
----------------------------------------------------

Road A -> Green for 20 seconds
Road C -> Green for 20 seconds
Road B -> Green for 10 seconds
Road D -> Green for 6 seconds

====================================================
*/

#include <stdio.h>

int main() {
    int a, b, c, d;
    int max;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    while (a > 0 || b > 0 || c > 0 || d > 0) {

        max = a;
        if (b > max) max = b;
        if (c > max) max = c;
        if (d > max) max = d;

        if (a == max && a > 0) {
            printf("Road A -> Green for %d seconds\n", a * 2);
            a = 0;
        }
        else if (b == max && b > 0) {
            printf("Road B -> Green for %d seconds\n", b * 2);
            b = 0;
        }
        else if (c == max && c > 0) {
            printf("Road C -> Green for %d seconds\n", c * 2);
            c = 0;
        }
        else if (d == max && d > 0) {
            printf("Road D -> Green for %d seconds\n", d * 2);
            d = 0;
        }
    }

    return 0;
}
