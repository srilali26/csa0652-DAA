#include <stdio.h>
#include <string.h>

int stringLength(char *s) {
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    return length;
}

int main() {
    char s[] = "hello";
    printf("Length of string: %d\n", stringLength(s));
    return 0;
}

