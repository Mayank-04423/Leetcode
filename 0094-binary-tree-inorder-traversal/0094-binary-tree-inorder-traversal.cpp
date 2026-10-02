class Solution {

    void inorder(TreeNode* root, vector<int>& result){
        if(!root)return;

        inorder(root->left,result);
        result.push_back(root->val);
        inorder(root->right,result);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int>result;
       inorder(root,result);
       return result;
    }
};