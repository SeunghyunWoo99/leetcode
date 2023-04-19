// https://leetcode.com/problems/merge-k-sorted-lists
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (auto list : lists)
            for (ListNode* it=list; it != nullptr; it = it->next)
                minHeap.push(it->val);

        ListNode* head = nullptr;

        for (ListNode* current = nullptr; !minHeap.empty();) {
            ListNode* node = new ListNode(minHeap.top());
            if (head == nullptr)
                head = node;
            else
                current->next = node;
            current = node;
            minHeap.pop();
        }

        return head;
    }
};

int main() {
    Solution s = Solution();
}
