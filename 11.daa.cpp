#include <stdio.h>
#include <string.h>

void copyString(char *source, char *destination) {
    strcpy(destination, source);
}

int main() {
    char source[] = "Hello, World!";
    char destination[50];
    copyString(source, destination);
    printf("Copied string: %s\n", destination);
    return 0;
}

