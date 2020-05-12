public class Solution {
    public int findUnsortedSubarray(int[] nums) {
        Stack < Integer > stack = new Stack < Integer > ();
        int l = nums.length, r = 0;
        for (int i = 0; i < nums.length; i++) {
            while (!stack.isEmpty() && nums[stack.peek()] > nums[i])
                l = Math.min(l, stack.pop());
            stack.push(i);
        }
        stack.clear();
        for (int i = nums.length - 1; i >= 0; i--) {
            while (!stack.isEmpty() && nums[stack.peek()] < nums[i])
                r = Math.max(r, stack.pop());
            stack.push(i);
        }
        return r - l > 0 ? r - l + 1 : 0;
    }
}


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int i = 0; 
        int j = n - 1;
        
        while(i < n - 1){
            if(nums[i] > nums[i+1]){
                break;
            }
            i++;
        }
        if(i == j){
            return 0;
        }
        
        while(j > 0){
            if(nums[j] < nums[j-1]){
                break;
            }
            j--;
        }
        
        int min_val = INT_MAX;
        int max_val = INT_MIN;
        
        for(int k = i ; k <= j ; ++k){
            min_val = min(min_val,nums[k]);
            max_val = max(max_val,nums[k]);
        }
        
        while(i > 0 && min_val < nums[i-1])
            i -= 1;
        while(j < n-1 && max_val > nums[j+1])
            j += 1;
        
        
        return (j - i + 1);
    }
};