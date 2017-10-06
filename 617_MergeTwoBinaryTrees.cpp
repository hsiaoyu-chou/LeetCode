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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        
        if(!t1) return t2;
        if(!t2) return t1;
        
        TreeNode* res = new TreeNode(0);
        
        res->val = (t1 ? t1->val : 0) + (t2 ? t2->val : 0);
        res->left = mergeTrees(t1->left, t2->left);
        res->right = mergeTrees(t1->right, t2->right);    
        
        return res;
        
    }
};