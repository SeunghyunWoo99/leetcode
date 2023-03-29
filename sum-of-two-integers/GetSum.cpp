// https://leetcode.com/problems/sum-of-two-integers/
#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int xorResult = a ^ b;
        int carry = (unsigned int)(a & b) << 1;
        int temp = xorResult;
        while (carry != 0) {
            temp = xorResult ^ carry;
            carry = (unsigned int)(xorResult & carry) << 1;
            xorResult = temp;
        }
        return xorResult;
    }
};


int main() {
    Solution s = Solution();
    cout << endl << s.getSum(-1,1) << endl;

    return 0;
}
