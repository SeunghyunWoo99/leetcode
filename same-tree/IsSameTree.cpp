// https://leetcode.com/problems/same-tree
#include <iostream>
#include <algorithm>

using namespace std;


//  Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class Solution {
public:
    bool flag = true;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p && q && p->val == q->val) {
            isSameTree(p->left, q->left);
            isSameTree(p->right, q->right);
        } else if (p == nullptr && q == nullptr) {
        } else {
            flag = false;
        }
        return flag;
    }
};

int main() {
    Solution s = Solution();
    TreeNode node15(15);
    TreeNode node7(7);
    TreeNode node20(20, &node15, &node7);
    TreeNode node9(9);
    TreeNode p(3, &node9, &node20);
    TreeNode q(3, &node9, &node20);
    cout << s.isSameTree(&p, &q) << endl;
}

