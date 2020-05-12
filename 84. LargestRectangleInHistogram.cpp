class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        stack<int> st;
        
        int i = 0;
        int res = 0;
        
        while(i < n){
            if(st.empty() || heights[st.top()] <= heights[i] ){
                st.push(i);
                i += 1;
            }else{
                int ind = st.top();
                st.pop();
                int area = heights[ind]*(st.empty() ? i : i - st.top() - 1);
                
                res = max(res,area);
            }
        }
        
        while(!st.empty()){
             int ind = st.top();
             st.pop();
             int area = heights[ind]*(st.empty() ? i : i - st.top() - 1);
                
             res = max(res,area);
        }
        
        return res;
        
    }
};