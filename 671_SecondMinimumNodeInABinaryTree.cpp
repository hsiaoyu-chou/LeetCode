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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        
        queue<TreeNode*> q;
        int a = root->val;
        int b = -1;
        q.push(root);
        
        while(!q.empty()){ 
            TreeNode* tmp = q.front();
            q.pop();
            
            if(tmp->val < a){
                b = a;
                a = tmp->val;
            }
            else if(tmp->val > a){
                if(tmp->val < b) b = tmp->val;
                if(b == -1 ) b = tmp->val;
            }
            
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
            
        }

        return b;
    }
    
};