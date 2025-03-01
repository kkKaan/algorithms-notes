#include <stdio.h>

#define N 4

void gale_shapley(int preferences[2 * N][N])   // man first version
{
    int freeCount = N;
    int menPrefIndexes[N] = { 0 };
    int womensPartner[N] = { [0 ... N - 1] = -1 };
    int isMenMatched[N] = { 0 };

    while (freeCount > 0)
    {
        for (int i = 0; i < N; ++i)
        {
            if (isMenMatched[i])
                continue;

            if (womensPartner[preferences[i][menPrefIndexes[i]] % N] == -1)
            {
                womensPartner[preferences[i][menPrefIndexes[i]] % N] = i;
                --freeCount;
                isMenMatched[i] = 1;
            }
            else
            {
                // check if new offer better than current one
                int prefWoman = preferences[i][menPrefIndexes[i]];
                int currMan = womensPartner[prefWoman % N];
                for (int j = 0; j < N; ++j)
                {
                    if (preferences[prefWoman][j] == i)
                    {
                        // new offer is better than current match
                        womensPartner[prefWoman % N] = i;
                        isMenMatched[i] = 1;
                        isMenMatched[currMan] = 0;
                        break;
                    }
                    else if (preferences[prefWoman][j] == currMan)
                    {
                        // current man is better than the offer do nothing
                        break;
                    }
                }
            }
            ++menPrefIndexes[i];
        }
    }
    for (int i = 0; i < N; ++i)
    {
        printf("man: %d, woman: %d\n", womensPartner[i], i + N);
    }
}

int main()
{
    int preferences[2 * N][N] = {
        { 7, 5, 6, 4 },
        { 5, 4, 6, 7 },
        { 4, 5, 6, 7 },
        { 4, 5, 6, 7 },
        { 0, 1, 2, 3 },
        { 0, 1, 2, 3 },
        { 0, 1, 2, 3 },
        { 0, 1, 2, 3 }
    };
    gale_shapley(preferences);
    return 0;
}