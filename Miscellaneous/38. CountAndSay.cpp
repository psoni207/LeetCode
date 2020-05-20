class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        if(n == 1){
            return res;
        }
        
        res = helperCount(n,res);
        
        return res;
        
    }
    
    string helperCount(int n,string res){
        
        int i = 2;

        while(i <= n){
            
            int j = 0;
            string ans = "";
            
            while( j < res.size()){
                
                char ch = res[j++];
                int count = 1;

                while(j < res.size() && ch == res[j]){
                    j += 1;
                    count += 1;
                }
                ans.append(to_string(count));
                ans.push_back(ch);
            }

            res = ans;
            i += 1;
        }

        return res;
    }
    
    
};