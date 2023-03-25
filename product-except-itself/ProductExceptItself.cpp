// https://leetcode.com/problems/product-of-array-except-self
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> answer(1,1);
        int reverseAccProduct = 1;

        for (int i=0; i<len-1; i++)
            answer.push_back(answer.back()*nums[i]);

        for (int i = len-1; i >= 0; i--) {
            answer[i] *= reverseAccProduct;
            reverseAccProduct *= nums[i];
        }

        return answer;
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {-1,1,0,-3,3};
    vector<int> answer = s.productExceptSelf(nums);
    
    cout << "[";
    for (int a : answer) {
        cout << " " << a;
    }
    cout << "]" << endl;

    return 0;
}
