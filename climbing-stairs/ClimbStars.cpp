// https://leetcode.com/problems/climbing-stairs
#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int a = 0;
        int b = 1;
        int answer;
        for (int i=1; i<n+1; i++) {
            answer = a+b;
            a = b;
            b = answer;
        }

        return answer;
    }
};


int main() {
    Solution s = Solution();
    cout << endl << s.climbStairs(45) << endl;

    return 0;
}
