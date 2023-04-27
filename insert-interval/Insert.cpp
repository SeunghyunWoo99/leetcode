// https://leetcode.com/problems/insert-interval/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        int prevEnd = -1;
        int start = newInterval[0];
        int end = newInterval[1];
        int i = 0;

        if (intervals.size() == 0) {
            answer.push_back(newInterval);
            return answer;
        }
        
        for (i = 0; i<intervals.size(); i++) {
            vector<int> interval = intervals[i];
            int currentStart = interval[0];
            int currentEnd = interval[1];
            if (prevEnd < start && start < currentStart) {
                answer.push_back({start, max(end, currentEnd)});
                break;
            } else if (currentStart <= start && start <= currentEnd) {
                answer.push_back({currentStart, max(end, currentEnd)});
                break;
            } else {
                answer.push_back(interval);
                prevEnd = currentEnd;
            }
        }
        int j = i;
        for (j = i; j < intervals.size(); j++) {
            vector<int> interval = intervals[j];
            int currentStart = interval[0];
            int currentEnd = interval[1];
            if (prevEnd < end && end < currentStart) {
                answer.back().back() = end;
                j--;
                break;
            } else if (currentStart <= end && end <= currentEnd) {
                answer.back().back() = currentEnd;
                break;
            } else {
                prevEnd = currentEnd;
                continue;
            }
        }

        for (int k=j+1; k<intervals.size(); k++) {
            answer.push_back(intervals[k]);
        }

        // if newInterval[start] is bigger than last index of intervals[i][end]
        if (intervals.back().back() < start) {
            answer.push_back(newInterval);
        }

        return answer;
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int> > intervals = {};
    vector<int> newInterval = {1,2};
    s.insert(intervals, newInterval);
}
