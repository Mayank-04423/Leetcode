class Solution {
    void preorder(TreeNode* root , vector<int>&result){
        while(!root)return;

        result.push_back(root->val);
        preorder(root->left,result);
        preorder(root->right,result);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>result;
        preorder(root, result);
        return result;
    }
};