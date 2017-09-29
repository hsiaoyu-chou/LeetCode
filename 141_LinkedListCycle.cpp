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
    bool hasCycle(ListNode *head) {
        ListNode *fast, *slow;
        fast = head;
        slow = head;
        
        while (slow) 
        {   //slow walks one step, fast walks two steps 
            slow = slow->next;
            
            if (fast->next != NULL && fast->next->next != NULL) fast = fast->next->next;
            else return false;
        
            if (fast == slow) return true; // if there is a cycle, they will meet
        }
    
        return false;
    }
};