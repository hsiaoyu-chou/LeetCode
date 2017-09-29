class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string map[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        if(digits != "") res.push_back("");
        
        for(int i = 0; i < digits.size(); i++){//every digits
            string str = map[digits[i] - '0'];
            vector<string> tmp;
            for(int j = 0; j < str.size(); j++){ //every char of str
                for(int k = 0; k < res.size(); k++){ //concat the char on every tmp string alresdy saved in res
                    tmp.push_back(res[k]+str[j]);
                }
            }
            res = tmp;
        }
        
        return res;
    }
};