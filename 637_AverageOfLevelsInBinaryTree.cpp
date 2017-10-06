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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            long tmp = 0;
            int s = q.size();
            for(int i = 0; i < s; i++){
                //deal with all nodes of the same level
                TreeNode* t = q.front();
                q.pop();
                tmp = tmp + t->val;
                
                //push the childern into the queue
                if(t->left) q.push(t->left); 
                if(t->right) q.push(t->right);
            }
            res.push_back((double)tmp/s);
        }
        return res;
    }
};