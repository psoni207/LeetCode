class Solution {
    int N, M;
    
public:
    int strStr(string haystack, string needle) {
        N = haystack.size();
        M = needle.size();
        
        if(N == 0 && M == 0 || M == 0){
            return 0;
        }else if(N == 0){
            return -1;
        }
        
        vector<int> lps(M);
        computeLPS(needle, lps, M);
        
        int res = -1;
        
        int i = 0; // index for haystack 
        int j = 0; // index for needle 
        while (i < N) {
            
            if (needle[j] == haystack[i]) { 
                j += 1; 
                i += 1; 
            } 

            if (j == M) { 
                res = i - j;
                break;
                //j = lps[j - 1]; 
            }  
            else if(i < N && needle[j] != haystack[i]) { 
                //Do not match lps[0..lps[j-1]] characters, they will match anyway 
                if (j != 0) 
                    j = lps[j - 1]; 
                else
                    i += 1; 
            } 
        } 
        
        
        return res;
        
    }
    
    void computeLPS(string &pat, vector<int> &lps, int M){
        
        // length of the previous longest prefix suffix
        int len = 0; 
    
        lps[0] = 0; // lps[0] is always 0, As we are searching for Proper prefix-suffix 
  
        int i = 1; 
        while(i < M) { 
            
            if(pat[i] == pat[len]) { 
                len += 1; 
                lps[i] = len; 
                i += 1; 
            } 
            else{
                
                if (len != 0) { 
                    len = lps[len - 1]; 
                } 
                else { 
                    lps[i] = 0; 
                    i += 1; 
                } 
            }
        }
    } 
};