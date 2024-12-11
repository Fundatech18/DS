#include <stdio.h>
#include <stdlib.h>

// A utility function to find the maximum number in the array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// A utility function to perform counting sort based on the digit represented by exp
void countingSort(int arr[], int n, int exp) {
    int output[n]; // Output array
    int count[10] = {0}; // Count array to store count of occurrences of digits

    // Count occurrences of each digit
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Update count[i] so that it contains the position of the digit in the output array
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the output array back to arr[], so that arr[] contains sorted numbers at the current digit
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Function to implement radix sort
void radixSort(int arr[], int n) {
    int max = getMax(arr, n); // Find the maximum number to determine the number of digits

    // Perform counting sort for every digit (starting from least significant digit)
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// Utility function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    radixSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
