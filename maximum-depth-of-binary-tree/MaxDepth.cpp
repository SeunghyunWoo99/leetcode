// https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftMax = maxDepth(root->left);
        int rightMax = maxDepth(root->right);
        
        return max(leftMax, rightMax) + 1;
    }
};

int main() {
    Solution s = Solution();
    TreeNode node15(15);
    TreeNode node7(7);
    TreeNode node20(20, &node15, &node7);
    TreeNode node9(9);
    TreeNode root(3, &node9, &node20);
    cout << s.maxDepth(&root) << endl;
}

