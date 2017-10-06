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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        
        //cut into two list 
        //p.s. if the list has odd nodes, list2 will get one more(middle)
        ListNode* fast = head->next;
        ListNode* slow = head;
        
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        //reverse the second list
        ListNode* list2= reverseList(slow->next);
        
        //compare the first list and the second one
        while(head != slow->next){
            if(head->val != list2->val) return false;
            else{
                head = head->next;
                list2 = list2->next;
            }
        }
        return true;
        
    }
    
    ListNode* reverseList(ListNode* head){
        
        if(!head || !head->next) return head;
        
        ListNode* prev (0);
        ListNode* curr = head;
        ListNode* prec = head->next;
        
        while(prec){
            curr->next = prev;
            
            prev = curr;
            curr = prec; 
            prec = prec->next; 
        }
        
        curr->next = prev;
        
        return curr;
    }
};