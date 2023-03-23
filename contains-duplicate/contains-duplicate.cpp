// https://leetcode.com/problems/contains-duplicate
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> visited;

        for (int i=0; i<nums.size(); i++) {
            int n = nums[i];
            if (visited[n])
                return true;
            visited[n] = true;
        }

        return false;
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {7,1,5,3,6,1,4};
    cout << s.containsDuplicate(nums) << endl;
}
