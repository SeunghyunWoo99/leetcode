// https://leetcode.com/problems/longest-repeating-character-replacement
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int answer = k+1;
        vector<int> dp(26,0);
        int maxIndex = 0;
        
        for (int i=0, j=0; j<n; j++) {
            dp[s[j]-'A']++;
            if (dp[maxIndex] < dp[s[j]-'A']) {
                maxIndex = s[j]-'A';
            }
            if (j - i + 1 - dp[maxIndex] > k) {
                dp[s[i]-'A']--;
                i++;
            }
            answer = max(answer, j-i+1);
        }

        return answer;
    }
};

int main() {
    Solution s = Solution();
    cout << s.characterReplacement("AABABBA", 1) << endl;
}

