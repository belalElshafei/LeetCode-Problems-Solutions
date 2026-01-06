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
    map<int,int>mp;
    void traverseTree(TreeNode* node,int level){
        if(node == NULL)return;
        mp[level]+=node->val;
        traverseTree(node->left,level+1);
        traverseTree(node->right,level+1);
    }
    int maxLevelSum(TreeNode* root) {
        traverseTree(root,1);
        int mxSum = INT_MIN,levelRes = 0;
        for(auto p:mp){
            if(p.second > mxSum){
                mxSum = p.second;
                levelRes = p.first;
            }
        }
        return levelRes;
    }
};