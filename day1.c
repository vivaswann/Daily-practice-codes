//Find the first repeating element

#include <stdio.h>

int main() {
    int arr[] = {4, 7, 1, 3, 7, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        int repeated = 0;

        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                repeated = 1;
                break;
            }
        }

        if (repeated) {
            printf("First repeating element is: %d\n", arr[i]);
            return 0;
        }
    }

    printf("No repeating element\n");
    return 0;
}
