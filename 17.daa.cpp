#include <stdio.h>

void findMinAndMax(int arr[], int low, int high, int *min, int *max) {
    if (low == high) {
        if (*min > arr[low]) *min = arr[low];
        if (*max < arr[low]) *max = arr[low];
        return;
    }
    
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            if (*min > arr[low]) *min = arr[low];
            if (*max < arr[high]) *max = arr[high];
        } else {
            if (*min > arr[high]) *min = arr[high];
            if (*max < arr[low]) *max = arr[low];
        }
        return;
    }

    int mid = (low + high) / 2;
    findMinAndMax(arr, low, mid, min, max);
    findMinAndMax(arr, mid + 1, high, min, max);
}

int main() {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int min = arr[0];
    int max = arr[0];

    findMinAndMax(arr, 0, arr_size - 1, &min, &max);

    printf("Minimum element is %d\n", min);
    printf("Maximum element is %d\n", max);
    return 0;
}

