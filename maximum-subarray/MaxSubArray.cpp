// https://leetcode.com/problems/maximum-subarray
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int minNumber = 0;
        int answer = nums[0];
        
        for (int i=1;i<len;i++) {
            nums[i] = nums[i-1] + nums[i];
        }
        for (int current : nums) {
            if (current - minNumber > answer)
                answer = current - minNumber;
            if (current < minNumber)
                minNumber = current;
        }

        return answer;
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {1,2,3,4,5};
    cout << endl << s.maxSubArray(nums) << endl;
}
