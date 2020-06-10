class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        
        int i = 0;
        while(i < n){   
            if(nums[i] > 0 && nums[nums[i]-1] > 0 && i != nums[i]-1){
                int ind = nums[i]-1;
                swap(nums[i],nums[ind]);
                nums[ind] = -nums[ind];
            }else{
                i += 1;
            }
        }
        
        i = 0;
        while(i < n){
            if(abs(nums[i]) != i + 1){
                res.push_back(i+1);
            }
            i += 1;
        }
        
        return res;
        
    }
};