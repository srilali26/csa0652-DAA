#include <stdio.h>
#include <string.h>

void reverseString(char *s) {
    int length = strlen(s);
    for (int i = 0; i < length / 2; i++) {
        char temp = s[i];
        s[i] = s[length - i - 1];
        s[length - i - 1] = temp;
    }
}

int main() {
    char s[] = "hello";
    reverseString(s);
    printf("Reversed string: %s\n", s);
    return 0;
}

