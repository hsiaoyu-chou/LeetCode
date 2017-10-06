/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//node is the node to be removed

class Solution {
public:
    void deleteNode(ListNode* node) {
        *node = *node->next; //make node->next replace node
    }
};