class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        int res = -1;
        for(int i = 0; i < n; i++){
            int ind = abs(nums[i]);
            if(nums[ind] < 0){
                res = ind;
                break;
            }else{
                nums[ind] = -nums[ind];
            }
        }
        return res;
        
    }
};