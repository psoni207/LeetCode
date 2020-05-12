class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int n = A.size();
        vector<bool> res(n);
        
        int sum = A[0];
        if(sum%5 == 0){
            res[0] = true;
        }
        for(int i = 1; i < n; ++i){
            if(A[i] == 1){
                sum = sum*2 + 1;
            }else{
                sum = sum*2;
            }
            
            if(sum%5 == 0){
                res[i] = true;
            }else{
                res[i] = false;
            }
            
            sum %= 5;
        }
        
        return res;
    }
};