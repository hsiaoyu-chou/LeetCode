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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || !head->next || m == n) return head;
        
        ListNode* prev = new ListNode(0);
        prev->next =head;
        
        ListNode* curr;
        ListNode* prec;
        ListNode* res = head;

        for(int i = 1; i < m ; i++){
            prev = prev->next;
        }
        
        ListNode* tmp = prev;
        curr = prev->next;
        prec = curr->next;
        
        for(int i = m; i < n ; i++){
            curr->next = prev;
            
            prev = curr;
            curr = prec;
            prec = prec->next;
        }
        
        //count == n
        curr->next = prev;
        
        //n->next = prec 
        tmp->next->next = prec;
        
        //m->next = curr
        tmp->next = curr; 
        
        if(m == 1) res = curr;
            
        return res;
    }
};