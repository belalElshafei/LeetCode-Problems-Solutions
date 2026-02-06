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
    long long mx = 0;
    int sumOfSubTrees(TreeNode* node){
        if(node == NULL) return 0;
        if(node->left == NULL && node->right == NULL) return node->val;
        return node->val +=sumOfSubTrees(node->left)+sumOfSubTrees(node->right);
    }

    void getMaxProduct(TreeNode* node,int tot){
        if(node == NULL) return;
        mx = max(mx,(long long)(node->val * (long long)(tot-node->val)));
        getMaxProduct(node->left,tot);
        getMaxProduct(node->right,tot);
    }

    int maxProduct(TreeNode* root) {
        sumOfSubTrees(root);
        getMaxProduct(root,root->val);
        const int N = 1e9+7;
        return mx%N;
    }
};