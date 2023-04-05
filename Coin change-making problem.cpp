
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMinCoins(vector<int> const &S, int target)
{
    if (target == 0) {
        return 0;
    }

    if (target < 0) {
        return INT_MAX;
    }

    int coins = INT_MAX;

    for (int i: S)
    {
        int result = findMinCoins(S, target - i);

        if (result != INT_MAX) {
            coins = min(coins, result + 1);
        }
    }

    return coins;
}

int main()
{
    vector<int> S = { 1, 2, 3, 4 };

    int target = 15;

    int coins = findMinCoins(S, target);
    if (coins != INT_MAX)
    {
        cout << "The minimum number of coins required to get the desired change is "
             << coins;
    }

    return 0;
}
