class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int c1 = m - 1;
        int c2 = n - 1;
        int i = m + n -1;
        
        //put from the largest (from tail)
        while(c1 >= 0 && c2 >= 0){
            if(nums1[c1] > nums2[c2]){
                nums1[i] = nums1[c1];
                c1--;
            }
            else{
                nums1[i] = nums2[c2];
                c2--;
            }
            i--;
        }
        
        while(c2 >= 0){
            nums1[i] = nums2[c2];
            c2--;
            i--;
        }
        
    }
};