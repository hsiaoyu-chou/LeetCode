/**
 * @param {number} n
 * @return {boolean}
 */
var canWinNim = function(n) {
     // (1+3, 2+2, 3+1), can always make 4, therefore any n % 4 == 0 will lose
    if(n%4 === 0) return false;
    return true;
};