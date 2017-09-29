/**
 * @param {number} n
 * @return {string[]}
 */

var helper = function(str, left, right, result){
    if(left === 0 && right === 0){ // all used
        result.push(str);
        return;
    }
    else if(left === right){ //already paired, have to begin from left
        helper(str+'(', left-1, right, result);
    }
    else if(left === 0){ // left are all used, only right left
        helper(str+')', left, right-1, result);
    }
    else{ 
        helper(str+'(', left-1, right, result);
        helper(str+')', left, right-1, result);
    } 
};

var generateParenthesis = function(n) {
    var result = [];
    helper("", n, n, result);
    return result;
};
