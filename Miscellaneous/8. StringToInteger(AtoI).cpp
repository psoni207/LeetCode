class Solution {
public:
    int myAtoi(string str) {
        int sign = 1;
        int n = str.size();
        
        int  i = 0;
        while( i < n && str[i] == ' '){ i += 1; }
        
        if( i == n){
            return 0;
        }
        
        if(str[i] == '-' || str[i] == '+'){
            sign = 1 - 2 * (str[i] == '-');
            i += 1;
        }
        
        int base = 0;
        while ( i < n && str[i] >= '0' && str[i] <= '9') {
            if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            
            base  = 10 * base + (str[i] - '0');
            i += 1;
        }
        return base * sign;
        
    }
};