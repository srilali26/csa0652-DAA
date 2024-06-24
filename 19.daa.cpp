#include <stdio.h>

typedef struct {
    int weight;
    int value;
    float ratio;
} Item;

void knapsack(Item items[], int n, int capacity) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    int total_weight = 0;
    float total_value = 0.0;

    for (int i = 0; i < n; i++) {
        if (total_weight + items[i].weight <= capacity) {
            total_weight += items[i].weight;
            total_value += items[i].value;
        } else {
            int remaining = capacity - total_weight;
            total_value += items[i].value * ((float)remaining / items[i].weight);
            break;
        }
    }

    printf("Maximum value in Knapsack = %.2f\n", total_value);
}

int main() {
    int capacity = 50;
    Item items[] = {{10, 60, 6.0}, {20, 100, 5.0}, {30, 120, 4.0}};
    int n = sizeof(items) / sizeof(items[0]);

    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    knapsack(items, n, capacity);
    return 0;
}

