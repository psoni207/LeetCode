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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        
        if(root == NULL){
            return result;
        }else{
            
            stack<TreeNode*> call_stack;
            stack<int> rev_postorder;
            
            TreeNode* node = root;
            while( node!= NULL || !call_stack.empty() ){
                
                if(node != NULL){
                    
                    call_stack.push(node);
                    rev_postorder.push(node->val);
                    
                    node = node->right;
                }else{
                    
                    node = call_stack.top();
                    call_stack.pop();
                    
                    node = node->left;
                }
            }
            
            while(!rev_postorder.empty()){
                int temp = rev_postorder.top();
                
                result.push_back(temp);
                rev_postorder.pop();
            }
        }
        
        return result;
    }
};