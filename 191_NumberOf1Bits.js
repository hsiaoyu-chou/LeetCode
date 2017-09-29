/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
    var ans = 0;
    /**if n is more than 32 bit, n&1 will be wrong
    * ex: n = 2147483648
    *
    
    while(n > 0){
        if(n & 1) ans ++;
        n = n >> 1;
    }
    
    */
    
    if( n === 0 ) return ans;
    var str = n.toString(2);
    ans = str.match(/1/g).length;
    
    return ans;
};