/*
====================================================
PROBLEM STATEMENT — SMART ELEVATOR SCHEDULER
====================================================

A building has a single elevator serving multiple floors.

The elevator follows these rules:

1. The elevator starts at floor 0.
2. There are N elevator requests, each representing
   a floor number where a person is waiting.
3. The elevator always moves in the current direction
   (up or down) until no further requests exist in that
   direction, then reverses direction.
4. The elevator stops at every requested floor it
   passes through.
5. Each floor movement takes 1 unit of time.

----------------------------------------------------
TASKS
----------------------------------------------------

Write a C program that:

1. Takes the number of requests N.
2. Takes N floor numbers as input.
3. Simulates the elevator movement.
4. Prints the order in which floors are served.
5. Prints the total time taken to serve all requests.

----------------------------------------------------
CONSTRAINTS
----------------------------------------------------

- Do NOT use recursion.
- Use arrays to store requests.
- Elevator initially moves upward.
- All floor numbers are non-negative integers.

----------------------------------------------------
INPUT FORMAT
----------------------------------------------------

N
F1 F2 F3 ... FN

----------------------------------------------------
SAMPLE INPUT
----------------------------------------------------

5
2 8 3 6 1

----------------------------------------------------
SAMPLE OUTPUT
----------------------------------------------------

Serving floor: 1
Serving floor: 2
Serving floor: 3
Serving floor: 6
Serving floor: 8
Total time: 8

====================================================
*/


#include <stdio.h>

int main() {
    int n;
    int floors[100];
    int served[100] = {0};
    int currentFloor = 0;
    int time = 0;
    int servedCount = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &floors[i]);
    }

    while (servedCount < n) {
        int nextFloor = -1;
        int minDiff = 100000;

     
        for (int i = 0; i < n; i++) {
            if (!served[i] && floors[i] >= currentFloor) {
                int diff = floors[i] - currentFloor;
                if (diff < minDiff) {
                    minDiff = diff;
                    nextFloor = i;
                }
            }
        }

        
        if (nextFloor == -1) {
            for (int i = 0; i < n; i++) {
                if (!served[i] && floors[i] < currentFloor) {
                    int diff = currentFloor - floors[i];
                    if (diff < minDiff) {
                        minDiff = diff;
                        nextFloor = i;
                    }
                }
            }
        }

        time += minDiff;
        currentFloor = floors[nextFloor];
        served[nextFloor] = 1;
        servedCount++;

        printf("Serving floor: %d\n", currentFloor);
    }

    printf("Total time: %d\n", time);

    return 0;
}
