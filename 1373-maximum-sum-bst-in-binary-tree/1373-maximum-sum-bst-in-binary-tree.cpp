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
    int maxSum = 0;

    struct nodeInfo{
        bool isBST;
        int minVal, maxVal, sum;
    };
        nodeInfo dfs(TreeNode* root){
        if(!root)return{true,INT_MAX, INT_MIN, 0};

        auto left = dfs(root->left);    
        auto right = dfs(root->right);

        if(left.isBST && right.isBST && left.maxVal < root->val && right.minVal > root->val){
            int currSum = left.sum + right.sum + root->val;
            maxSum = max(currSum , maxSum);

            return{true, min(root->val, left.minVal), max(root->val, right.maxVal), currSum};
        }

        return {false, 0,0,0};
    }

    public:
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxSum;
    }     
};