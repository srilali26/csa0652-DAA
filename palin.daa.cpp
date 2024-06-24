#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(char str[], int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return is_palindrome(str, start + 1, end - 1);
}

int main() {
    char string[] = "racecar";
    int length = strlen(string);
    if (is_palindrome(string, 0, length - 1)) {
        printf("%s is a palindrome\n", string);
    } else {
        printf("%s is not a palindrome\n", string);
    }
    return 0;
}

