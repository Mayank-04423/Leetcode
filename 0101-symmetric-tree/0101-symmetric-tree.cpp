class Solution {
public:
        bool checkMirror(TreeNode*p,TreeNode*q){   
        //empty 
        if(p ==nullptr && q ==nullptr) return true;
        //either one empty
        if(p==nullptr || q==nullptr)return false;
        //exist but non equal values
        if(p->val != q->val) return false;

        //matching left and right subtrees
        return checkMirror(p->left,q->right) && checkMirror(p->right,q->left);
    }

    bool isSymmetric(TreeNode* root) {
       if(root == nullptr) return true;

       return checkMirror(root->left, root->right);
    }
};