class Solution {
public:
    int romanToInt(string s) {
        
        int N = s.size();
        
        unordered_map<char,int> roman;
        roman['I']=1;
        roman['V']=5;
        roman['X']=10;
        roman['L']=50;
        roman['C']=100;
        roman['D']=500;
        roman['M']=1000;
        
        int res=0;
        int last=0, secLast=0;
        
        for(int i = N-1; i >= 0; i--){

            last = roman[s[i]];
            if(i != 0){
                secLast = roman[s[i-1]];
            }
            res += last;
            if(secLast < last){
                res -= secLast;
                i--;
            }
            secLast = 0;
        }
        
        return res;
        
    }
};