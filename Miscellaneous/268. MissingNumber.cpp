class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        int i = 0;
        while(i < n){
            if(nums[i] != n && i != nums[i]){
                swap(nums[i], nums[nums[i]]);
            }else{
                i += 1;
            }
        }
        
        int res = n;
        for(int i = 0; i < n; i++){
            if(i != nums[i]){
                res = i;
            }
        }
        
        return res;
    }
};