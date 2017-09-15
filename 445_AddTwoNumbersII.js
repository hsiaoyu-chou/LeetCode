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
    var diff = 0;
    var stack1 = [];
    var stack2 = [];
    var stack3 = [];
    var dummyHead = new ListNode(0);
    var list3 = dummyHead;
    var tmp = 0;
    var c = 0;

    //count list length
    while(l1 !== null){
        stack1.push(l1.val); //reverse order
        l1= l1.next;
    }
    while(l2 !== null){
        stack2.push(l2.val); //reverse order
        l2= l2.next;
    }
    
    // add numbers
    while(stack1.length !== 0 || stack2.length !== 0){
    
        tmp = (stack1.length === 0)? 0 : stack1.pop();
        tmp = tmp + ((stack2.length === 0)? 0 : stack2.pop());
        tmp = tmp + c;
        
        c = Math.floor(tmp/10);
        stack3.push(tmp%10); //normal order
    }
    if( c!== 0)stack3.push(c);
    
    //generate list by stack3
    while(stack3.length !== 0){
        list3.next = new ListNode(stack3.pop());
        list3 = list3.next;
    }
    
    return dummyHead.next;
};