
#include <iostream>

void coin_change_greedy(int n) {
  int coins[] = {20, 10, 5, 1};
  int i=0;

  while(n) {
    if(coins[i] > n) {
      i++;
    }
    else {
      std::cout << coins[i] << "\t";
      n = n-coins[i];
    }
  }
  std::cout << std::endl;
}

int main() {
  int i;
  for(i=1; i<=20; i++) {
    coin_change_greedy(i);
  }
  return 0;
}
