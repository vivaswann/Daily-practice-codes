#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char password[100];
    int hasUpper = 0, hasLower = 0, hasDigit = 0;
    int hasSpecial = 0, hasSpace = 0;
    int failCount = 0;

    fgets(password, sizeof(password), stdin);

    password[strcspn(password, "\n")] = '\0';

    int len = strlen(password);

    if (len < 8)
        failCount++;

    for (int i = 0; i < len; i++) {
        if (isupper(password[i]))
            hasUpper = 1;
        else if (islower(password[i]))
            hasLower = 1;
        else if (isdigit(password[i]))
            hasDigit = 1;
        else if (password[i] == ' ')
            hasSpace = 1;
        else
            hasSpecial = 1;

        
        if (i >= 2 &&
            password[i] == password[i - 1] &&
            password[i] == password[i - 2]) {
            failCount++;
            break;
        }
    }

    if (!hasUpper) failCount++;
    if (!hasLower) failCount++;
    if (!hasDigit) failCount++;
    if (!hasSpecial) failCount++;
    if (hasSpace) failCount++;

    if (failCount == 0) {
        printf("Strong\n");
    } else if (failCount <= 2) {
        printf("Moderate\n");
    } else {
        printf("Weak\n");
    }

    return 0;
}
