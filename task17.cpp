
#include <iostream>
#include <vector>
#include <iomanip>

int FindKnapsackRec(int capacity, std::vector<int> &weights, std::vector<int> &values, int n, std::vector<std::vector<int>> &dp) {
    if (n == 0 || capacity == 0)
        return 0;

    if (dp[n][capacity] != -1)
        return dp[n][capacity];

    if (weights[n - 1] <= capacity) {
        dp[n][capacity] = std::max(
            values[n - 1] + FindKnapsackRec(capacity - weights[n - 1], weights, values, n - 1, dp),
            FindKnapsackRec(capacity, weights, values, n - 1, dp));
        return dp[n][capacity];
    }
    dp[n][capacity] = FindKnapsackRec(capacity, weights, values, n - 1, dp);
    return dp[n][capacity];
}

int FindKnapsack(int capacity, std::vector<int> &weights, std::vector<int> &values, int n) {
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacity + 1, -1));
    return FindKnapsackRec(capacity, weights, values, n, dp);
}

int main() {
    std::vector<int> weights = {10, 20, 30, 40};
    std::vector<int> values = {30, 10, 40, 20};
    int capacity = 40;
    int n = 4;

    int result = FindKnapsack(capacity, weights, values, n);
    std::cout << "The maximum value of items in knapsack is: " << result << std::endl;
    return 0;
}
