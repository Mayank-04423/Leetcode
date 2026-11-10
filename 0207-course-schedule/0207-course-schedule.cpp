class Solution {
    bool cycle(int node,vector<vector<int>>& adj, vector<int>& state){
        if(state[node]==1)return true;
        if(state[node]==2)return false;

        state[node]=1;
        for(int i:adj[node]){
            if(cycle(i,adj,state))return true;
        }
        state[node]=2;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);

        for(auto pre:prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int>state(numCourses,0);

        for(int i=0; i<numCourses ;i++){
            if(state[i]==0){
                if(cycle(i,adj,state))return false;
            }
        }
        return true;
    }
};