class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        int n = s.size();
        
        unordered_map<char,char> umap;
        umap['('] = ')';
        umap['{'] = '}';
        umap['['] = ']';
        
        
        int i = 0;
        while(i < n){
            
            if(s[i] == '(' || s[i] == '{' || s[i] == '[' ){
                st.push(s[i]);
            }else{
                if(!st.empty() && umap[st.top()] == s[i]){
                    st.pop();
                }else{
                    return false;
                }
            }
            i += 1;
        }
        
        if(st.empty()){
            return true;
        }
        return false;
        
    }
};