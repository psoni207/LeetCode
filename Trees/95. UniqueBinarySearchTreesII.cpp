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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode* > res;
        
        if(n == 0){
            return res;
        }
        
        res = constructBSTs(1,n);
        return res;
    }
    
    vector<TreeNode* > constructBSTs(int start, int end){
        vector<TreeNode* > tree;
        
        if(start > end){
            tree.push_back(NULL);
            return tree;
        }
        
        for(int i = start; i <= end; i += 1){
            vector<TreeNode* > leftTree = constructBSTs(start,i-1);
            vector<TreeNode* > rightTree = constructBSTs(i+1,end);
            
            for(int j = 0; j < leftTree.size(); j += 1){
                TreeNode *left = leftTree[j];
                
                for(int k = 0; k < rightTree.size(); k += 1){
                    TreeNode *right = rightTree[k];
                    TreeNode *currNode = new TreeNode(i);
                    
                    currNode->left = left;
                    currNode->right = right;
                    tree.push_back(currNode);
                }
            }
            
        }
        
        return tree;
    }
};