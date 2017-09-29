/**
 * @param {number[]} nums
 * @return {string}
 */
var largestNumber = function(nums) {
    var ans = '';
    var str = [];
    for(var i in nums){
        str.push(nums[i].toString());
    }
    str = str.sort(function(a, b){return Number(b+a) - Number(a+b)}); //descending

    for(var j in str){
        if( ans === '0' && str[j] === '0') ans = '0';
        else ans = ans + str[j];
    }
    
    return ans;
    
};