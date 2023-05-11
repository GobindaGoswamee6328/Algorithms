
#include<iostream>

using namespace std;

int coinchange(int * coins, int numOfCoins, int targetAmount) {
  int dp[targetAmount + 1] = {};
  dp[0] = 1;

  for (int i = 1; i <= targetAmount; i++) {
    for (int j = 0; j < numOfCoins; j++) {
      if (coins[j] <= i) {
        dp[i] += dp[i - coins[j]];
      }

    }
  }

  return dp[targetAmount];

}
int main() {
  int numOfCoins;
  cin >> numOfCoins;

  int * coins = new int[numOfCoins];

  for (int i = 0; i < numOfCoins; i++) {
    cin >> coins[i];
  }

  int targetAmount;
  cin >> targetAmount;

  cout << "Total permutation are" << coinchange(coins, numOfCoins, targetAmount) << endl;

  return 0;
}

