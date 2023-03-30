// https://leetcode.com/problems/coin-change
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;
        for (int i=1; i<amount+1; i++) {
            for (int coin : coins) {
                if (i-coin > -1)
                    dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
        return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};

int main() {
    Solution s = Solution();
    vector<int> coins = {4,7};
    cout << s.coinChange(coins, 6) << endl;
    cout << endl;
}
