/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        
        ListNode* tmp = head;
        
        while(tmp->next){
            if(tmp->next->val == val) tmp->next = tmp->next->next; //if eqal val, remove 
            else tmp = tmp->next; //move to next
        }
        
        return (head->val == val) ? head->next : head; //check head at the end
        
    }
};