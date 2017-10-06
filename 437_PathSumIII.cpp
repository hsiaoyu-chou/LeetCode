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
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        
        if(!root) return 0;
        
        res = pathSum_single(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
            
        return res;
    }
    
    int pathSum_single(TreeNode* root, int sum) {
        int paths = 0;
        vector<int> path;
        
        hasPathSum(root, sum, path, paths);
        
        return paths;
    }
    
    void hasPathSum(TreeNode* root, int sum, vector<int>& path, int& paths) {
        if(!root) return;
        
        path.push_back(root->val);
        
        if(root->val == sum) paths++;
        
        hasPathSum(root->left, sum-root->val, path, paths);
        hasPathSum(root->right, sum-root->val, path, paths);
        
        path.pop_back();//important
    }
    
};