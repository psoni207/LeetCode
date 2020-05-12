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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > result;
        
        if(root == NULL){
            return result;
        }else{
            
            queue<TreeNode*> level;
            level.push(root);
            
            while(!level.empty()){
                
                int count = level.size();
                vector<int> ans;
                
                while(count){
                    TreeNode* node = level.front();
                    level.pop();
                    
                    ans.push_back(node->val);
                    if(node->left){
                        level.push(node->left);
                    }
                    if(node->right){
                        level.push(node->right);
                    }
                    
                    count -= 1;
                }
                
                result.push_back(ans);
            }
            
            return result;
        }
        
    }
};