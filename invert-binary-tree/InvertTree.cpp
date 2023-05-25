// https://leetcode.com/problems/invert-binary-tree
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
    void printTree(TreeNode* root) {
        if (!root)
            return;
        printTree(root->left);
        cout << root->val << " ";
        printTree(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

int main() {
    Solution s = Solution();
    TreeNode node15(15);
    TreeNode node7(7);
    TreeNode node20(20, &node15, &node7);
    TreeNode node9(9);
    TreeNode root(3, &node9, &node20);
    s.printTree(s.invertTree(&root));
}

