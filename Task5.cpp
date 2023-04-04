
#include<bits/stdc++.h>
using namespace std;

int main(){
    // n will store the number of denominations
    int n;
    cin >> n;

    // array of size n for storing denominations
    int deno[n];
    for(int i = 0 ; i < n ; i++){
        cin >> deno[i];
    }

    // number of test cases
    int t;
    cin >> t;

    // for each test case find min number of coins
    while(t--){
        // total amount we have
        int amount;
        cin >> amount;

        // variable for storing the number of coins
        int coins = 0;

        // since the array is already sorted in ascending order
        // traverse the denominations array in reverse direction
        for(int i = n - 1 ; i >= 0 ; i--){
            // while amount left is greater than or equal to deno[i]
            while (amount >= deno[i]) {
                // subtract deno[i] from amount
                amount = amount - deno[i];
                // increment the coins by 1
                coins++;
            }
        }

        // print the number of coins
        cout << coins << endl;
    }
    return 0;
}
