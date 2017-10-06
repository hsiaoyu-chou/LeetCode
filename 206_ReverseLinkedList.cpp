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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* previous(0);
        ListNode* current = head;
        ListNode* preceding = head->next;
        
        while(preceding){
            current->next = previous;
            
            previous = current;
            current = preceding;
            preceding = preceding->next;
        }
        
        current->next = previous;
        
        return current;
        
    }
};