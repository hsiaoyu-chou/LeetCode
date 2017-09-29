/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//merge sort

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        
        if(!head || !head->next) return head; //list is null or has only 1 node
        
        //split into 2 lists (0~a and a+1~b)
        ListNode* a = head;
        ListNode* b = head->next;
        while(b && b->next){
            a = a->next;
            b = b->next->next;
        }
        
        b = a->next;
        a->next = NULL;
        
        //merge each list
        ListNode* list_a = sortList(head); 
        ListNode* list_b = sortList(b);
    
        // merge sorted l1 and sorted l2
        return mergeLists(list_a, list_b);   
    }
    
    ListNode* mergeLists(ListNode* list1, ListNode* list2){
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        
        while(list1 && list2){
            if(list1->val < list2->val){
                head->next = list1;
                list1 = list1->next;
            }
            else{
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
        }
        
        head->next = (list1)? list1 : list2;
        
        ListNode* res = dummy->next;
        delete dummy;
        
        return res;       
    }
    
};