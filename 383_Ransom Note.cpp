class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int i = 0;
        while(ransomNote[i]){

            int n = magazine.find(ransomNote[i]);
            if(n == string::npos)return false;
            else{
                magazine[n] = 0;
            }
            
            i++;
        }
        return true;
    }
};