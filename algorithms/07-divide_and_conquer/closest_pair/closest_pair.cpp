#include <cfloat>
#include <iostream>

using namespace std;

struct Point
{
    int x;
    int y;
};

void merge(Point* nums, int l, int m, int r, int index)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    Point leftArr[n1], rightArr[n2];
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
        if (index == 0)
        {
            if (leftArr[leftIndex].x < rightArr[rightIndex].x)
            {
                nums[l++] = leftArr[leftIndex++];
            }
            else
            {
                nums[l++] = rightArr[rightIndex++];
            }
        }
        else
        {
            if (leftArr[leftIndex].y < rightArr[rightIndex].y)
            {
                nums[l++] = leftArr[leftIndex++];
            }
            else
            {
                nums[l++] = rightArr[rightIndex++];
            }
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

void merge_sort(Point* nums, int l, int r, int index)
{
    if (l < r)
    {
        int midIndex = (l + r) / 2;
        merge_sort(nums, l, midIndex, index);
        merge_sort(nums, midIndex + 1, r, index);
        merge(nums, l, midIndex, r, index);
    }
}

double distance(Point p1, Point p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double min(double a, double b)
{
    return (a < b) ? a : b;
}

double brute_force(Point* ps, int size)
{
    double min = DBL_MAX;
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            double temp = distance(ps[i], ps[j]);
            if (temp < min)
            {
                min = temp;
            }
        }
    }
    return min;
}

double strip_closest(Point* strip, int size, double d)
{
    double min = d;
    merge_sort(strip, 0, size - 1, 1);

    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
        {
            if (distance(strip[i], strip[j]) < min)
                min = distance(strip[i], strip[j]);
        }
    }

    return min;
}

// A recursive function to find smallest distance, point array is sorted on x coordinate.
double closest_util(Point* p, int n)
{
    if (n <= 3)
        return brute_force(p, n);

    int mid = n / 2;
    Point midP = p[mid];

    double dl = closest_util(p, mid);
    double dr = closest_util(p + mid, n - mid);
    double d = min(dl, dr);

    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        if (abs(p[i].x - midP.x) < d)
            strip[j++] = p[i];
    }

    return min(d, strip_closest(strip, j, d));
}

int main()
{
    // // Merge sort test
    // Point points[] = {
    //     { 2,  3  },
    //     { 12, 30 },
    //     { 40, 50 },
    //     { 5,  1  },
    //     { 12, 10 },
    //     { 3,  4  },
    //     { 1,  2  }
    // };
    // int n = sizeof(points) / sizeof(points[0]);
    // merge_sort(points, 0, n - 1, 0);
    // for (int i = 0; i < n; ++i)
    // {
    //     cout << points[i].x << " " << points[i].y << endl;
    // }

    Point points[] = {
        { 2,  3  },
        { 12, 30 },
        { 40, 50 },
        { 5,  1  },
        { 12, 10 },
        { 3,  4  },
        { 1,  2  }
    };
    int n = sizeof(points) / sizeof(points[0]);
    merge_sort(points, 0, n - 1, 0);
    cout << "The smallest distance is " << closest_util(points, n) << endl;

    return 0;
}