from typing import Any  # For type hints, optional but recommended.


def bubble_sort(arr: list[Any]) -> list[Any]:
    """Sorts a list of integers in place using the bubble sort algorithm.

    This implementation iterates (this is the iterative version) through the list 
    repeatedly, swapping adjacent elements if they are in the wrong order. The algorithm
    terminates early if no swaps occur during a complete pass through the list.

    Args:
        arr (list[Any]): A list of integers to be sorted.

    Returns:
        list[Any]: The same list with its elements sorted in ascending order.

    """
    n = len(arr)
    for i in range(n):
        swapped = False  # Track if any swaps occur during this pass.
        # Traverse the list up to the last unsorted element.
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                # Swap elements if they are in the wrong order.
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        # If no swaps occurred, the list is sorted.
        if not swapped:
            break
    return arr


if __name__ == "__main__":
    # To validate or test with some inputs, you may use here.
    arr = [64, 34, 25, 12, 22, 11, 90]
    print(bubble_sort(arr))  # Output: [11, 12, 22, 25, 34, 64, 90]
