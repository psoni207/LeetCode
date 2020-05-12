/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
        
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        
        long minVal = LONG_MIN;
        long maxVal = LONG_MAX;
        
        bool result = helperCheckBst(root,minVal,maxVal);
        return result;
    }
    
    bool helperCheckBst(TreeNode* root,long minVal,long maxVal){
        if(root == NULL){
            return true;
        }else{
            if(root->val > minVal && root->val < maxVal){
                bool checkL = helperCheckBst(root->left,minVal, root->val );
                bool checkR = helperCheckBst(root->right,root->val , maxVal);
                
                return checkL && checkR;
            }else{
                return false;
            }
        }
    }
};