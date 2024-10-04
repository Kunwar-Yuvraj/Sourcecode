#include <stdio.h>
#include <stdlib.h>

/**
 * Swap two elements.
 *
 * @param a Pointer to the first element.
 * @param b Pointer to the second element.
 */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Partition the array using the last element as the pivot.
 *
 * @param arr Array to be partitioned.
 * @param low Starting index.
 * @param high Ending index.
 * @return The partition index where the pivot is placed.
 */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pivot element
    int smaller_index = low - 1;  // Index of smaller element

    for (int current_index = low; current_index <= high - 1; current_index++) {
        if (arr[current_index] < pivot) {
            smaller_index++;
            swap(&arr[smaller_index], &arr[current_index]);
        }
    }

    swap(&arr[smaller_index + 1], &arr[high]);
    return smaller_index + 1;
}

/**
 * Perform QuickSort on the array.
 *
 * @param arr Array to be sorted.
 * @param low Starting index.
 * @param high Ending index.
 */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int partition_index = partition(arr, low, high);  // Partition index

        // Recursively sort elements before and after partition
        quickSort(arr, low, partition_index - 1);
        quickSort(arr, partition_index + 1, high);
    }
}

/**
 * Main function to drive the program.
 *
 * Prompts the user to input the size and elements of the array,
 * sorts the array using QuickSort, and displays the sorted array.
 */
int main() {
    int array_size;

    // Prompt user for input and validate
    printf("Enter the size of the array: ");
    if (scanf("%d", &array_size) != 1 || array_size <= 0) {
        fprintf(stderr, "Invalid array size.\n");
        return EXIT_FAILURE;
    }

    // Dynamically allocate memory for the array
    int* arr = (int*)malloc(array_size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    // Input array elements
    printf("Enter %d elements of the array: ", array_size);
    for (int i = 0; i < array_size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Invalid input.\n");
            free(arr);
            return EXIT_FAILURE;
        }
    }

    // Perform QuickSort on the input array
    quickSort(arr, 0, array_size - 1);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < array_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free dynamically allocated memory
    free(arr);

    return EXIT_SUCCESS;
}
