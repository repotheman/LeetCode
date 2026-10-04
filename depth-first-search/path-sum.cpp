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
    bool helper(TreeNode* root, int target){
 
        if(!root) return false;
 
        if(target == root->val && !root->left && !root->right) return true;
        bool left = helper(root->left, target - root->val);
        bool right = helper(root->right, target - root->val);
 
        return left || right;
    }
 
    bool hasPathSum(TreeNode* root, int targetSum) {
 
        return helper(root, targetSum);
        
    }
};