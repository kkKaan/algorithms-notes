#include <iostream>

using namespace std;

void merge(int* nums, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int leftArr[n1], rightArr[n2];
    for (int i = 0; i < n1; ++i)
    {
        leftArr[i] = nums[l + i];
    }
    for (int i = 0; i < n2; ++i)
    {
        rightArr[i] = nums[m + 1 + i];
    }

    int leftIndex = 0;
    int rightIndex = 0;

    while (leftIndex < n1 && rightIndex < n2)
    {
        if (leftArr[leftIndex] < rightArr[rightIndex])
        {
            nums[l++] = leftArr[leftIndex++];
        }
        else
        {
            nums[l++] = rightArr[rightIndex++];
        }
    }

    for (int i = leftIndex; i < n1; ++i)
    {
        nums[l++] = leftArr[leftIndex++];
    }
    for (int i = rightIndex; i < n2; ++i)
    {
        nums[l++] = rightArr[rightIndex++];
    }
}

void merge_sort(int* nums, int l, int r)
{
    if (l < r)
    {
        int midIndex = (l + r) / 2;
        merge_sort(nums, l, midIndex);
        merge_sort(nums, midIndex + 1, r);
        merge(nums, l, midIndex, r);
    }
}

int main()
{
    int nums[] = { 186, 419, 83, 408, 304 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    merge_sort(nums, 0, numsSize - 1);
    for (int i = 0; i < numsSize; ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}