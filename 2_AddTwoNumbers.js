/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    var l3 = new ListNode(0);
    var node = l3;
    var tmp;
    var c = 0;
    
    while( l1 !== null || l2 !== null){ //add until both l1 and l2 end
        tmp = (l1 === null)? 0 : l1.val;
        tmp = tmp + ((l2 === null)? 0 : l2.val);
        tmp = tmp + c;
        node.next = new ListNode(tmp%10);
        c = Math.floor(tmp/10);
        node = node.next; //move the the next
        if(l1 !== null) l1 = l1.next; //move the the next
        if(l2 !== null) l2 = l2.next; //move the the next
    }
    
    if(c != 0){ //remember the last carry
        node.next = new ListNode(c);
        node = node.next;
    }
    
    return l3.next; //don't return the beginning 0
};