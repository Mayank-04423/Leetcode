class Solution {

    void dfs(TreeNode* root, int row , int col , map<int , vector<pair<int, int>>>& mp){
        if(!root)return;

        mp[col].push_back({row,root->val});

        dfs(root->left,row+1 , col-1,mp);
        dfs(root->right, row+1, col+1 , mp);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, vector<pair<int,int>>>mp;
    dfs(root,0,0,mp);

    vector<vector<int>>result;

    for(auto& [col,nodes]:mp){
        sort(nodes.begin(),nodes.end());

        vector<int>column;
        for(auto& [row,val]:nodes){
            column.push_back(val);
        }
        result.push_back(column);
    }

    return result;
    }
};