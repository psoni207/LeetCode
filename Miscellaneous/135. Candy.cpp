class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        vector<int> res(n,1);
        
        for(int i = 1; i < n ; i++){
            if(ratings[i - 1] < ratings[i]){
                res[i] = res[i -1] + 1;
            }
        }
        
        int sum = res[n - 1];
        for(int i = n - 2; i >=0; i--){
            if(ratings[i] > ratings[i + 1] && res[i] <= res[i + 1]){
                res[i] = res[i + 1] + 1;
            }
            sum += res[i];
        }
        
        
        return sum;
    }
};