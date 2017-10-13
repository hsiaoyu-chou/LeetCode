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
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return -1;
        
        queue<TreeNode*> q;
        
        int a[k] = {0};
        a[0] = root->val;
        int count = 0;
        
        q.push(root);
        
        while(!q.empty()){ 
            TreeNode* tmp = q.front();
            q.pop();
            
            //deal with value
            int flag_insert = 0;
            int n = 0;
            
            for(int i = 0; i < k; i++){
                
                if(flag_insert){
                    swap(n, a[i]);
                }
                else if(tmp->val < a[i]){
                    n = a[i];
                    a[i] = tmp->val;
                    flag_insert = 1;
                    if(count < (k-1))count++;
                }
                else if(tmp->val == a[i]) break;
                else if(count < i){
                    a[i] = tmp->val;
                    count++;
                    break;
                }
            }
            
            //put unchecked nodes into the queue
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
            
        }

        return a[k-1];
    }
    
};