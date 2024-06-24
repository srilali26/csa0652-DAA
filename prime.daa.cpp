#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n, int i) {
    if (n <= 2) {
        return n == 2;
    }
    if (n % i == 0) {
        return false;
    }
    if (i * i > n) {
        return true;
    }
    return is_prime(n, i + 1);
}

int main() {
    int number = 29;
    if (is_prime(number, 2)) {
        printf("%d is prime\n", number);
    } else {
        printf("%d is not prime\n", number);
    }
    return 0;
}

