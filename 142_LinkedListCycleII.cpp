/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
*   0 -x- 1 -y- 2   fast and slow met at 2 
*          \   /    slow: x+y
*           -z-     fast:x+y+z+y = 2slow = x+y+x+y => x = z
**/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *node = hasCycle(head);
        
        if(node == NULL) return NULL;
        else{
            ListNode *cycleStart = head;
            while(cycleStart != node){
                cycleStart = cycleStart->next;
                node = node -> next;
            }
            return cycleStart;
        }
        
    }
    
    ListNode *hasCycle(ListNode *head) {
        ListNode *fast, *slow;
        fast = head;
        slow = head;
        
        while (slow) 
        {   //slow walks one step, fast walks two steps 
            slow = slow->next;
            
            if (fast->next != NULL && fast->next->next != NULL) fast = fast->next->next;
            else return NULL;
        
            if (fast == slow) return slow; // if there is a cycle, they will meet
        }
    
        return NULL;
    } 
};