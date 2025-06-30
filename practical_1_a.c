#include <stdio.h>

// Function to perform linear search in an array
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == key) {
            return i; // Return the index if key is found
        }
    }
    return -1; // Return -1 if key is not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;

    int index = linearSearch(arr, n, key);

    if (index != -1) {
        printf("Linear Search: Element %d found at index %d\n", key, index);
    } else {
        printf("Linear Search: Element %d not found in the array\n", key);
    }

    return 0;
}
