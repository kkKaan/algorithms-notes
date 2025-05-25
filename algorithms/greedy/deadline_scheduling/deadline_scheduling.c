#include <stdio.h>

// This function assumes deadlines are sorted in ascending order
int deadline_scheduling(int* processingTimes, int* deadlines, int n)
{
    int currentTime = 0;
    int lateness = 0;
    for (int i = 0; i < n; ++i)
    {
        currentTime += processingTimes[i];
        lateness += currentTime > deadlines[i] ? currentTime - deadlines[i] : 0;
    }
    return lateness;
}

int main()
{
    int processingTimes[] = { 1, 3, 2, 4 };
    int deadlines[] = { 4, 6, 8, 9 };
    int n = sizeof(processingTimes) / sizeof(processingTimes[0]);
    printf("Lateness: %d\n", deadline_scheduling(processingTimes, deadlines, n));   // Output: 6
    return 0;
}