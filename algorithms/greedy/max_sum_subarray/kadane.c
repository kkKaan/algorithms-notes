#include <stdio.h>

int max_sub_array(int* nums, int numsSize) 
{
    int ret = nums[0];
    int prevSum = nums[0];
    for (int i = 1; i < numsSize; ++i)
    {
        int temp = nums[i] > nums[i] + prevSum ? nums[i] : nums[i] + prevSum;
        ret = ret > temp ? ret : temp;
        prevSum = temp;
    }    
    return ret;
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Max sum of subarray: %d\n", max_sub_array(arr, size));
    return 0;
}