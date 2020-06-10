class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n-1;
        
        int res = 0;
        int area;
        while(i < j){
            area = min(height[i], height[j]) * (j - i);  
            res = max(res,area);
            if(height[i] <= height[j]){
                i += 1;
            }else{
                j -= 1;
            }
        }
        return res;
    }
};