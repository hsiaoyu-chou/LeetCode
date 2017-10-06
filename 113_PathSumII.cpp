/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        vector<int> path;
        
        hasPathSum(root, sum, path, paths);
        
        return paths;
    }
    
    void hasPathSum(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& paths) {
        if(!root) return;
        
        path.push_back(root->val);
        
        if(root->val == sum && !root->left && !root->right) paths.push_back(path);
        
        hasPathSum(root->left, sum-root->val, path, paths);
        hasPathSum(root->right, sum-root->val, path, paths);
        
        path.pop_back();//important
    }
};