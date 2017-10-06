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
    int maxDepth(TreeNode* root) {
        int res = 0;
        if(root == NULL) return res;
        else res = 1;
    
        int L = maxDepth(root->left);
        int R = maxDepth(root->right);
        res = res +( (L >= R) ? L : R );
    
        return res;
    }
};