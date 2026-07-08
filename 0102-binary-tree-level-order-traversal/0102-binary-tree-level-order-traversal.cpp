class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            //finding nodes on current level 
            int levelSize = q.size();
            vector<int> currentLevel;

            //processing that many nodes
            for(int i=0; i< levelSize; i++){
                TreeNode* curr = q.front();
                q.pop();

                currentLevel.push_back(curr->val);

                //pushing children to back
                if(curr->left!=nullptr) q.push(curr->left);
                if(curr->right!=nullptr) q.push(curr->right);
            }
            result.push_back(currentLevel);
        }
        return result;
    }
};