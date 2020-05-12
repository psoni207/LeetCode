class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        string res = "";
            
        if(n == 0){
            return res;
        }
        
        res = strs[0];
        
        for(int i = 1; i < n; i++){
            string str = "";
            for(int j = 0; j < res.size() && j < strs[i].size(); j++){
                if(res[j] == strs[i][j]){
                    str += res[j];
                }else{
                    break;
                }
            }
            res = str;
        }
        
        return res;
        
    }
};