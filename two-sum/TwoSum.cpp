// https://leetcode.com/problems/two-sum/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> visited;
        int len = nums.size();

        for (int i=0; i<len; i++) {
            int n = nums[i];
            if (visited.count(target-n))
                return {visited[target-n], i};
            visited[n] = i;
        }

        return {};
    }
};


int main() {
    Solution s = Solution();
    vector<int> nums = {1,2,3,4,5,6};
    vector<int> answer = s.twoSum(nums, 7);
    for (int out : answer) {
        cout << out << " ";
    }
    cout << endl;
}
