#include <stdio.h>

// Function to perform binary search in a sorted array
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid; // Return the index if key is found
        }

        if (arr[mid] < key) {
            low = mid + 1; // If key is greater, search in the right half
        } else {
            high = mid - 1; // If key is smaller, search in the left half
        }
    }

    return -1; // Return -1 if key is not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;

    int index = binarySearch(arr, 0, n - 1, key);

    if (index != -1) {
        printf("Binary Search: Element %d found at index %d\n", key, index);
    } else {
        printf("Binary Search: Element %d not found in the array\n", key);
    }

    return 0;
}
