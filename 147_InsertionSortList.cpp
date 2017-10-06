/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//for each one, insert it into  the placs it should be
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* tmp = head; //checked ones
        ListNode* tail = head->next; //the one to be inserted
        int count = 1;
        
        while(tail){
            if(tail->val >= tmp->val){
                tmp = tmp->next;
                tail = tail->next;
                count++;
            }
            else{
                ListNode* curr = tail;
                ListNode* tail_next = tail->next;
                if(curr->val < head->val){
                    tmp->next = tail->next;
                    curr->next = head;
                    head = curr;
                }
                else{
                    ListNode* b4big = head;
                    
                    for(int i = 0; i < count; i++){
                        if(b4big->next->val >= curr->val){ //found
                            ListNode* big = b4big->next;
                            tmp->next = tmp->next->next;
                            b4big->next = curr;
                            curr->next = big;
                            break;
                        }
                        else{
                            b4big = b4big->next;
                        }
                    }
                }
                tail = tail_next;
                count++;
            }   
        }
        return head;
    }
};