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
    unordered_map<int, int>inorderMap;
    int preIndex = 0;
    TreeNode* build(vector<int>& preorder,int inStart , int inEnd){
        if(inStart>inEnd)return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root =new TreeNode(rootVal);

        int rootPos = inorderMap[rootVal];

        root->left = build(preorder ,inStart, rootPos-1);
        root->right = build(preorder, rootPos +1, inEnd);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0 ; i<inorder.size(); i++){
            inorderMap[inorder[i]]=i;
        }

        return build(preorder, 0, inorder.size()-1);
    }
};