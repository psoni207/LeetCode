class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        int n = nums1.size();
        int m = nums2.size();
        
        int i = 0, j = 0;
        
        while(i < n && j < m){
            if(nums1[i] == nums2[j]){
                res.push_back(nums1[i]);
                i += 1;
                j += 1;
                
                while( i < n  && nums1[i] == res[res.size() - 1]){
                    i += 1;
                }
                while(j < m && nums2[j] == res[res.size() - 1]){
                    j += 1;
                }
            }else if(nums1[i] < nums2[j]){
                i += 1;
            }else{
                j += 1;
            }
        }
        
        return res;
    }
};