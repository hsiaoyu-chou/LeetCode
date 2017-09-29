class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long sum = 0;
        int n = nums.size();
        long check_sum = (n + 1)*n/2;
        
        for(int i = 0; i < n; i++){
            sum = sum + nums[i];    
        }
        
        return check_sum - sum;
    }
};