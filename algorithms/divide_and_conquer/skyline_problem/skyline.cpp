#include <iostream>

struct Building
{
    int left;
    int height;
    int right;
};

struct Point
{
    int x;
    int height;
};

// Merge two skylines into one
void merge_skylines(Point* result, Point* left, Point* right, int& resultSize, int leftSize, int rightSize)
{
    int i = 0, j = 0, currIndex = 0;
    int currHeight = 0, leftHeight = 0, rightHeight = 0;

    // Similar to merge in merge sort
    while (i < leftSize && j < rightSize)
    {
        Point* next;

        // Choose next point from left or right skyline
        if (left[i].x < right[j].x)
        {
            next = &left[i];
            leftHeight = left[i].height;
            i++;
        }
        else if (left[i].x > right[j].x)
        {
            next = &right[j];
            rightHeight = right[j].height;
            j++;
        }
        else
        {
            // Same x-coordinate
            leftHeight = left[i].height;
            rightHeight = right[j].height;
            next = &left[i];   // Arbitrary choice since x is the same
            i++;
            j++;
        }

        // Update current height - max of left and right skylines
        int newHeight = (leftHeight > rightHeight) ? leftHeight : rightHeight;

        // Add point if height changes
        if (newHeight != currHeight)
        {
            result[currIndex].x = next->x;
            result[currIndex].height = newHeight;
            currIndex++;
            currHeight = newHeight;
        }
    }

    // Add remaining points from left skyline
    while (i < leftSize)
    {
        result[currIndex++] = left[i++];
    }

    // Add remaining points from right skyline
    while (j < rightSize)
    {
        result[currIndex++] = right[j++];
    }

    resultSize = currIndex;
}

// Main divide and conquer function
void get_skyline(Building buildings[], int start, int end, Point result[], int& resultSize)
{
    // Base case: single building
    if (start == end)
    {
        // Left edge of building
        result[0].x = buildings[start].left;
        result[0].height = buildings[start].height;

        // Right edge of building
        result[1].x = buildings[start].right;
        result[1].height = 0;

        resultSize = 2;
        return;
    }

    // Divide buildings into two halves
    int mid = (start + end) / 2;

    // Arrays to store left and right skylines
    Point leftSkyline[100], rightSkyline[100];
    int leftSize = 0, rightSize = 0;

    // Recursively get skylines for each half
    get_skyline(buildings, start, mid, leftSkyline, leftSize);
    get_skyline(buildings, mid + 1, end, rightSkyline, rightSize);

    // Merge the two skylines
    merge_skylines(result, leftSkyline, rightSkyline, resultSize, leftSize, rightSize);
}

int main()
{
    Building buildings[8] = {
        { 1,  11, 5  },
        { 2,  6,  7  },
        { 3,  13, 9  },
        { 12, 7,  16 },
        { 14, 3,  25 },
        { 19, 18, 22 },
        { 23, 13, 29 },
        { 24, 4,  28 }
    };

    Point skyline[100];   // Result array
    int skylineSize = 0;

    get_skyline(buildings, 0, 7, skyline, skylineSize);

    // Print the skyline
    std::cout << "Skyline points: " << std::endl;
    for (int i = 0; i < skylineSize; i++)
    {
        std::cout << "(" << skyline[i].x << ", " << skyline[i].height << ") ";
    }
    std::cout << std::endl;

    return 0;
}