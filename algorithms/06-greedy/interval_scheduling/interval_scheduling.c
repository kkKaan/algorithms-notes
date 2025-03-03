#include <stdio.h>

// This algorithm assumes endTimes are sorted in ascending order
int greedy_activity_selection(int* startTimes, int* endTimes, int n)
{
    int res = 0;
    int currentTime = 0;
    // If end times (with their starts) are not sorted, sort them before this loop
    for (int i = 0; i < n; ++i)
    {
        if (currentTime <= startTimes[i])
        {
            currentTime = endTimes[i];
            ++res;
        }
    }

    return res;
}

int main()
{
    int startTimes[] = { 1, 9, 11 };
    int endTimes[] = { 10, 12, 20 };
    int n = sizeof(startTimes) / sizeof(startTimes[0]);

    int result = greedy_activity_selection(startTimes, endTimes, n);
    printf("Maximum number of activities that can be performed: %d\n", result);

    return 0;
}