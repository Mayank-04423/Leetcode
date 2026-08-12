class Solution {
    bool dfs(int node, int target, int parent, vector<vector<int>>& adj,vector<bool>& visited){
        if(node==target)return true;
        visited[node]=true;
        for(int neighbour:adj[node]){
            if(neighbour!=parent && !visited[neighbour]){
                if(dfs(neighbour,target,node,adj,visited))return true;
            }
        }
    return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>>adj(n+1);

        for(auto& edge:edges){
            vector<bool>visited(n+1,false);
            if(dfs(edge[0],edge[1],-1,adj,visited)){
                return edge;
            }
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return {};
    }
};