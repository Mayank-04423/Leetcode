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
    int index =0;
    TreeNode* build(vector<int>& preorder, int minVal , int maxVal){
        if(index == preorder.size()) return nullptr;

        int val = preorder[index];
        if(val<minVal || val>maxVal)return nullptr;

        TreeNode* root = new TreeNode(val);
        index++;

        root->left = build(preorder, minVal , val);
        root->right = build(preorder, val, maxVal);

        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder,INT_MIN, INT_MAX);
    }
};