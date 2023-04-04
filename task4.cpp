
#include<iostream>
using namespace std;
int countMinCoins(int n) {
   if(n<10)
      return n;
   else if(n > 9 && n < 25){
      int count = n/10;
      count += n%10;
      return count;
   } else {
      int count = n/25;
      return count + countMinCoins(n%25);
   }
}
int main() {
   int n = 88;
   cout << "Minimum number of coins required: " << countMinCoins(n);
}
