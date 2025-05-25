#include <stdio.h>

int coin_change(int* coins, int coinsSize, int amount)
{
    if (!amount)
        return 0;

    int current = 0;
    int coinNo = 0;
    int lastIndex = coinsSize - 1;

    while (current < amount)
    {
        int i = lastIndex;
        while (i >= 0 && coins[i] > amount - current)
            --i;

        if (i < 0)   // Can't make exact change
            return -1;

        current += coins[i];
        ++coinNo;
        lastIndex = i;
    }

    return (current == amount) ? coinNo : -1;
}

int main()
{
    // Ensure that the coins are sorted in ascending order
    int coins[] = { 1, 2, 5 };
    int coinsSize = sizeof(coins) / sizeof(coins[0]);
    int amount = 11;

    int result = coin_change(coins, coinsSize, amount);
    if (result != -1)
        printf("Minimum number of coins required: %d\n", result);
    else
        printf("Change not possible\n");

    return 0;
}