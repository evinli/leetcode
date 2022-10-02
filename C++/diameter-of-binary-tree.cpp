/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        height(root, ans);

        return ans;
    }

    int height(TreeNode* root, int& ans) {
        // base case
        if (root == nullptr) return 0;

        int leftHeight = height(root->left, ans);
        int rightHeight = height(root->right, ans);
        ans = max(ans, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);

    }
};