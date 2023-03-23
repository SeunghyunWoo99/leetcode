// https://leetcode.com/problems/best-time-to-buy-and-sell-stock
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer = 0;
        int len = prices.size();
        int minPrice = prices[0];

        for (int i=0; i<len; i++) {
            int current = prices[i];
            int currentProfit = current - minPrice;
            
            if (answer < currentProfit) {
                answer = currentProfit;
            }
            if (minPrice > current) {
                minPrice = current;
            }
        }

        return answer;
    }
};

int main() {
    Solution s = Solution();
    vector<int> prices = {7,1,5,3,6,4};
    cout << s.maxProfit(prices) << endl;
}