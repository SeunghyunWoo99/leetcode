// https://leetcode.com/problems/number-of-1-bits/
#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int answer = 0;
        while (n != 0){
            n &= n-1;
            answer++;
        }

        return answer;
    }
};

int main() {
    Solution s = Solution();
    cout << endl << s.hammingWeight(11) << endl;

    return 0;
}
