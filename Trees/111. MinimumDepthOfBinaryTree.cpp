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
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int result = helperFindMinDepth(root);
        return result;
    }
    
    int helperFindMinDepth(TreeNode* root){
        if(root == NULL){
            return 0;
        }else{
            int leftD = helperFindMinDepth(root->left);
            int rightD = helperFindMinDepth(root->right);
            
            if(root->left && root->right){
                return 1 + min(leftD,rightD);
            }else if(root->left){
                return 1 + leftD;
            }else{
                return 1 + rightD;
            }
        }
    }
};