/*
====================================================
PROBLEM STATEMENT — SIMPLE TEXT ANALYZER
====================================================

You are given a line of text.

----------------------------------------------------
TASK
----------------------------------------------------

Write a C program that:

1. Reads a line of text from the user.
2. Counts:
   - Total number of characters
   - Total number of words
   - Total number of lines

----------------------------------------------------
RULES
----------------------------------------------------

- A word is defined as a sequence of characters
  separated by spaces.
- Use loops and conditionals only.
- Do NOT use recursion.

----------------------------------------------------
INPUT FORMAT
----------------------------------------------------

A single line of text.

----------------------------------------------------
OUTPUT FORMAT
----------------------------------------------------

Characters: X
Words: Y
Lines: Z

----------------------------------------------------
SAMPLE INPUT
----------------------------------------------------

Hello world from C

----------------------------------------------------
SAMPLE OUTPUT
----------------------------------------------------

Characters: 18
Words: 4
Lines: 1

====================================================
*/

#include <stdio.h>

int main() {
    char text[500];
    int characters = 0;
    int words = 0;
    int lines = 1;
    int inWord = 0;

    fgets(text, sizeof(text), stdin);

    for (int i = 0; text[i] != '\0'; i++) {
        characters++;

        if (text[i] == '\n') {
            lines++;
        }

        if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t') {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            words++;
        }
    }

    printf("Characters: %d\n", characters - 1);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);

    return 0;
}

