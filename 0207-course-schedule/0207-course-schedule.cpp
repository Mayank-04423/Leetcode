class Solution {
    bool hasCycle(int node,vector<vector<int>>& adj, vector<int>& state){
        if(state[node]==1)return true;
        if(state[node]==2)return false;

        state[node]=1;
        for(int neighbour:adj[node]){
            if(hasCycle(neighbour,adj,state))return true;
        }
        state[node]=2;
        return false;
    }
   
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>>adj(numCourses);

       //adj list 
       for(auto pre:prerequisites){
        adj[pre[1]].push_back(pre[0]);
       }

       vector<int>state(numCourses,0);

       for(int i=0; i<numCourses; i++){
        if(state[i]==0){
            if(hasCycle(i,adj,state))return false;
        }
       }
       return true;
    }
};