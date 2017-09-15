/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function(nums, target) {
    
    var length = nums.length;
    var ans;
    var tmp;
    
    nums.sort(function(a,b){return a - b; });
    
    for(var i = 0; i < length - 2; i++){
      
            var j = i + 1;
            var k = length - 1; //two poiters, more efficient
            
            while(j < k){
                tmp = nums[i]+nums[j]+nums[k];
                
                if(ans === undefined) ans = tmp;
                
                if(tmp == target){
                    ans = tmp;
                    return ans;
                }
                else if( tmp > target ){
                    if(tmp - target < Math.abs(ans - target)) ans = tmp;
                    k--;
                }
                else{
                    if(target - tmp < Math.abs(ans - target)) ans = tmp;
                    j++;
                }
                
            }
    }
    return ans;
};