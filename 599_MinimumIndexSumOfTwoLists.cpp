class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int sum = 2000;
        vector<string> str;
        vector<string> res;
        int count = 0;
        
        for(int i = 0; i < list1.size(); i++){
            for(int j =0; j < list2.size(); j++){
                if(list1[i] == list2[j] && (i+j) <= sum){
                    sum = i + j;
                    str.push_back(list1[i]);
                    if((i+j) == sum) count++;
                    else count = 1;
                }
            }
        }
        
        while(count){
            res.push_back(str[str.size()-count]);
            count--;
        }
        
        return res;
        
    }
};