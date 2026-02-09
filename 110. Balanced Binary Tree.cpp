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

    int checkDepths(TreeNode* node,int level,bool &res){      
        if(node == NULL){
            return level;
        }
    
        int left = checkDepths(node->left,level+1,res);
        int right = checkDepths(node->right,level+1,res);

        if(abs(left - right) > 1){
            res = false;
        }
        return max(left,right);
    }
    
    bool isBalanced(TreeNode* root) {
        bool res = true;
        checkDepths(root,0,res);
        return res;
    }
};