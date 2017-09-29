/**
 * @param {number} num
 * @return {string}
 */
var toHex = function(num) {
    var ans = '';
    var hex = ['0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'];
    var count = 0;
    
    if(num === 0) ans = "0";
    
    else{
        while(num != 0 && count < 8){   //32-bit
            ans = hex[num & 15]+ ans;     // &1111      
            num = (num >> 4);
            count ++;
        }
    }
 
    return ans;
};