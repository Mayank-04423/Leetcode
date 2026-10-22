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
    int postIndex;
    unordered_map<int,int>inorderMap;

    TreeNode* build(vector<int>& postorder , int start , int end){
        if(start>end)return nullptr;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inorderMap[rootVal];

        root->right = build(postorder,mid+1 , end);
        root->left = build(postorder, start , mid-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        inorderMap.clear();
        for(int i=0; i<inorder.size(); i++){
            inorderMap[inorder[i]] = i;
        }
        postIndex = postorder.size()-1;
        return build(postorder , 0 ,inorder.size()-1);

    }
};