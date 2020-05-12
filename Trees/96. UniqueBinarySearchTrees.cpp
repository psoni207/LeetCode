class Solution {
public:
    int numTrees(int n) {
        
        if(n == 0){
            return 0;
        }
        
        int result = helperFindUniqueBST(n);
        return result;
    }
    
    int helperFindUniqueBST(int n){
        if( n == 0){
            return 1;
        }
        if(n <= 2){
            return n;
        }else{
            int result = 0;
            for(int i = 1; i <= n; i++){
                
                result += helperFindUniqueBST(i-1)*helperFindUniqueBST(n-i);
            }
            return result;
        }
    }
};