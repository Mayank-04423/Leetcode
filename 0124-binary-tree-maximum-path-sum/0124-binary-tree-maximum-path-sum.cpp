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
    int path(TreeNode* root, int& max_gain){
        if(!root)return 0;

        int left = max(0, path(root->left,max_gain));
        int right = max(0, path(root->right,max_gain));
        max_gain = max(max_gain, left + root->val + right);
        return root->val + max(left,right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int max_gain = INT_MIN;
        path(root,max_gain);
        return max_gain;
    }
};