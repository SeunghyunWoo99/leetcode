// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string str;
        int answer = 0;
        for (char c : s) {
            auto index = str.find(c);
            if (index != string::npos) {
                str += c;
                str.erase(0, index+1);
            } else {
                str += c;
                answer = max(answer, (int)str.size());
            }
        }

        return answer;
    }
};

int main() {
    Solution s = Solution();
    cout << s.lengthOfLongestSubstring("12314567890") << endl;
}

