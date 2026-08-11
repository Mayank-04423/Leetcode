class Solution {
    bool hasCycle(int node, vector<vector<int>>& adj, vector<int>& state,vector<int>& order){
        if(state[node]==1)return true;
        if(state[node]==2)return false;

        state[node]=1;
        for(int neighbour:adj[node]){
            if(hasCycle(neighbour,adj,state,order))return true;
        }
        state[node]=2;
        order.push_back(node);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);

        for(auto pre:prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int>state(numCourses,0);
        vector<int>order;

        for(int i=0; i<numCourses; i++){
            if(state[i]==0){
                if(hasCycle(i,adj,state,order))return {};
            }
        }
        reverse(order.begin(),order.end());
       return order;
    }
};