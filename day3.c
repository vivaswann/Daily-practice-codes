//Write a C program using only <stdio.h> that takes a user's name and prints it in a staircase pattern, but instead of starting from 'A' every time, it starts from the previous letter in the name.

#include <stdio.h>

int main() {
    char name[100];
    char start = 'A';

    printf("Enter name: ");
    scanf("%s", name);

    for (int i = 0; name[i] != '\0'; i++) {
        char target = name[i];

        
        if (target >= 'a' && target <= 'z') {
            target = target - 32;
        }

      
        if (start <= target) {
            for (char curr = start; curr <= target; curr++) {
                printf("%c\n", curr);
            }
        } else {
            for (char curr = start; curr >= target; curr--) {
                printf("%c\n", curr);
            }
        }


        start = target;
        printf("---\n");
    }

    return 0;
}