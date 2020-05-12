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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        bool result = helperCheckSymmetric(root->left,root->right);
        return result;
    }
    
    bool helperCheckSymmetric(TreeNode* Left, TreeNode* Right){
        if(!Left && !Right){
            return true;
        }else if( Left && Right ){
            
            if(Left->val == Right->val){
                
                bool checkLR = helperCheckSymmetric(Left->left,Right->right);
                bool checkRL = helperCheckSymmetric(Left->right,Right->left);
                
                return checkLR && checkRL;
            }else{
                return false;
            }
            
        }else{
            return false;
        }
    }
};