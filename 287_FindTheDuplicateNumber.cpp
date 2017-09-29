class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int fast = n;
        int slow = n;
        
        //like finding cycle in linked list
        // slow => node, num[slow-1] => slow.next
        
        while(1){
            slow = nums[slow-1];
            fast = nums[nums[fast-1]-1];
            if(slow == fast) break;
        }
        
        slow = n;
        while(slow != fast){
            slow = nums[slow-1];
            fast = nums[fast-1];
        }
        return slow;
    }

    /** another method

        int findDuplicate(vector<int>& nums) {
            int n=nums.size()-1;
            int low=1;
            int high=n;
            int mid;
            while(low<high){
                mid=(low+high)/2;
                int count=0;
                for(int num:nums){
                    if(num<=mid) count++;
                }
                if(count>mid) high=mid;
                else low=mid+1; 
            }
            return low;
        }

    **/
};