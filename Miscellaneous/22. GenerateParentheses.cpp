class Solution {
    private:
    vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        int left = 0;
        int right = 0;
        string str = "";
        
        helperSolve(str,left,right,n);
        return res;
    }
    
    void helperSolve(string str, int left, int right, int n){
        if(right == n){
            res.push_back(str);
        }else{
            if(left < n){
                helperSolve(str + '(', left + 1, right, n);
            }
            if(right < left){
                helperSolve(str + ')', left, right + 1, n);
            }
        }
        
    }
};