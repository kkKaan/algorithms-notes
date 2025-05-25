#include <iostream>

using namespace std;

void merge(int* arr, int l, int m, int r, int& count)
{
    int lIndex = 0, rIndex = 0, arrIndex = l;
    int lArr[m - l + 1], rArr[r - m];

    for (int i = 0; i < m - l + 1; ++i)
    {
        lArr[i] = arr[l + i];
    }
    for (int i = 0; i < r - m; ++i)
    {
        rArr[i] = arr[m + 1 + i];
    }

    while ((lIndex < m - l + 1) && (rIndex < r - m))
    {
        if (lArr[lIndex] > rArr[rIndex])
        {
            arr[arrIndex++] = rArr[rIndex++];
            count += m - l + 1 - lIndex;
        }
        else
        {
            arr[arrIndex++] = lArr[lIndex++];
        }
    }

    for (int i = lIndex; i < m - l + 1; ++i)
    {
        arr[arrIndex++] = lArr[lIndex++];
    }
    for (int i = rIndex; i < r - m; ++i)
    {
        arr[arrIndex++] = rArr[rIndex++];
    }
}

void merge_sort(int* arr, int l, int r, int& count)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        merge_sort(arr, l, m, count);
        merge_sort(arr, m + 1, r, count);
        merge(arr, l, m, r, count);
    }
}

int inversion_count(int* arr, int size)
{
    int count = 0;
    merge_sort(arr, 0, size - 1, count);
    return count;
}

int main()
{
    int arr[4] = { 8, 4, 2, 1 };
    // int count = 0;
    // merge_sort(arr, 0, 3, count);
    // cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << ' ' << arr[3] << ' ' << endl;
    // cout << count << endl;
    int res = inversion_count(arr, 4);
    cout << res << endl;
}
