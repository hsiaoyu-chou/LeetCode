/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    var length = nums.length;
    var ans = [];
    var test;
    
    nums.sort(function(a, b){return a - b});
    
    for(var i = 0; i < length - 2; i++){
        if(i === 0 || nums[i] > nums[i-1]){  // in case there are duplicate triplets
            
            var j = i + 1;
            var k = length - 1; //two poiters, more efficient
            
            while(j < k){
                test = nums[i]+nums[j]+nums[k];
                if(test === 0){
                    ans.push([nums[i], nums[j], nums[k]]);
                    j++;
                    k--;
                    while(j < k && nums[j] === nums[j-1]){ j++; } // in case there are duplicate triplets
                    while(j < k && nums[k] === nums[k+1]){ k--; } // in case there are duplicate triplets
                }
                else if(test > 0){
                    k--;
                }
                else{
                    j++;
                }
                
            }
            
        }
    }
    return ans;
};

