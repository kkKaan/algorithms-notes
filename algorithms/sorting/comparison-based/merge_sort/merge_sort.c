#include <stdio.h>

// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int* arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    int i = 0;   // Initial index of first subarray
    int j = 0;   // Initial index of second subarray
    int k = l;   // Initial index of merged subarray

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1)
        arr[k++] = L[i++];

    // Copy the remaining elements of R[], if there are any
    while (j < n2)
        arr[k++] = R[j++];
}

// l is for left index and r is right index of the sub-array of arr to be sorted
void merge_sort(int* arr, int l, int r)
{
    if (l < r)
    {
        // Same as (l + r) / 2, but avoids overflow for large l and r
        int m = l + (r - l) / 2;

        // Sort first and second halves
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    int arr[] = { 186, 419, 83, 408 };
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    for (int i = 0; i < arrSize; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    merge_sort(arr, 0, arrSize - 1);

    printf("Sorted array is \n");
    for (int i = 0; i < arrSize; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}