#include <stdio.h>

int get_largest_element(int arr[], int n) {
    int largest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

int main() {
    int array[] = {10, 20, 30, 5, 60};
    int size = sizeof(array) / sizeof(array[0]);
    printf("Largest element: %d\n", get_largest_element(array, size));
    return 0;
}

