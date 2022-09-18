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

// Recursive soln
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        recurTree(root);        
        return root;
    }
    
    void recurTree(TreeNode* root) {
        // base case
        if (root == nullptr) return;
        
        // recursive step
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        recurTree(root->left);
        recurTree(root->right);
    }
};

// Iterative Soln
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> invert;
        
        if (root != nullptr) invert.push(root);
        
        while (!invert.empty()) {
            TreeNode* curr = invert.front();
            invert.pop();
            
            TreeNode* temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;
                
            if (curr->left != nullptr) invert.push(curr->left);
            if (curr->right != nullptr) invert.push(curr->right);
        }
        
        return root;
    }
};