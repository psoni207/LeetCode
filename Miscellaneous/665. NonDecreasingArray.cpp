class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int res = 0;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] < nums[i-1]){
                res += 1;
                if(i == 1 || nums[i-2] <= nums[i]){
                    nums[i-1] = nums[i];
                }else{
                    nums[i] = nums[i-1];
                }
            }
        }
        
        return (res <= 1 ? true: false );
    }
};