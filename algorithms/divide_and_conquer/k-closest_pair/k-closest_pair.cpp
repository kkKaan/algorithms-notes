#include <iostream>

using namespace std;

struct Point
{
    int x;
    int y;
};

struct PointPair
{
    Point p1;
    Point p2;
    double distance;
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
    int mergeIndex = l;

    while (leftIndex < n1 && rightIndex < n2)
    {
        if (index == 0)
        {
            if (leftArr[leftIndex].x < rightArr[rightIndex].x)
            {
                nums[mergeIndex++] = leftArr[leftIndex++];
            }
            else
            {
                nums[mergeIndex++] = rightArr[rightIndex++];
            }
        }
        else
        {
            if (leftArr[leftIndex].y < rightArr[rightIndex].y)
            {
                nums[mergeIndex++] = leftArr[leftIndex++];
            }
            else
            {
                nums[mergeIndex++] = rightArr[rightIndex++];
            }
        }
    }

    while (leftIndex < n1)
    {
        nums[mergeIndex++] = leftArr[leftIndex++];
    }

    while (rightIndex < n2)
    {
        nums[mergeIndex++] = rightArr[rightIndex++];
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

// Insert a pair into sorted array of k pairs
void insert_pair(PointPair* pairs, int& size, int k, Point p1, Point p2)
{
    double dist = distance(p1, p2);

    // If we have fewer than k pairs, just add it
    if (size < k)
    {
        pairs[size].p1 = p1;
        pairs[size].p2 = p2;
        pairs[size].distance = dist;
        size++;

        // Sort pairs by distance (bubble sort for simplicity)
        for (int i = size - 1; i > 0; i--)
        {
            if (pairs[i].distance < pairs[i - 1].distance)
            {
                PointPair temp = pairs[i];
                pairs[i] = pairs[i - 1];
                pairs[i - 1] = temp;
            }
            else
            {
                break;
            }
        }
    }
    // If distance is less than the largest in our k pairs, replace it
    else if (dist < pairs[k - 1].distance)
    {
        pairs[k - 1].p1 = p1;
        pairs[k - 1].p2 = p2;
        pairs[k - 1].distance = dist;

        // Sort pairs by distance (bubble sort for simplicity)
        for (int i = k - 1; i > 0; i--)
        {
            if (pairs[i].distance < pairs[i - 1].distance)
            {
                PointPair temp = pairs[i];
                pairs[i] = pairs[i - 1];
                pairs[i - 1] = temp;
            }
            else
            {
                break;
            }
        }
    }
}

void find_k_closest_pairs(Point* p, int n, int k, PointPair* result)
{
    int pairCount = 0;

    // First sort by x-coordinate
    merge_sort(p, 0, n - 1, 0);

    // Brute force to find all pairs and keep k closest
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            insert_pair(result, pairCount, k, p[i], p[j]);
        }
    }
}

int main()
{
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
    int k = 3;   // Find 3 closest pairs

    PointPair closestPairs[k];
    find_k_closest_pairs(points, n, k, closestPairs);

    // Print the k closest pairs
    cout << "The " << k << " closest pairs are: " << endl;
    for (int i = 0; i < k; i++)
    {
        cout << "Pair " << i + 1 << ": (" << closestPairs[i].p1.x << "," << closestPairs[i].p1.y << ") and "
             << "(" << closestPairs[i].p2.x << "," << closestPairs[i].p2.y << ") "
             << "with distance: " << closestPairs[i].distance << endl;
    }

    return 0;
}