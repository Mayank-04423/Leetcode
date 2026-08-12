class Solution {
    bool bfs(vector<vector<int>>& grid, queue<pair<int,int>>& q, int& fresh){
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int,int>>dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        bool rotten = false;

        int size = q.size();
        for(int i=0;i<size;i++){
            auto[x,y]=q.front();
            q.pop();
            for(auto[dx,dy]:dirs){
                int nx = x+dx;
                int ny = y+dy;
                if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1){
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                    fresh--;
                    rotten = true;
                }
            }
        }
        return rotten;
    }
    
public:
    int orangesRotting(vector<vector<int>>& grid){
        queue<pair<int,int>>q;
        int fresh = 0;

        for(int i=0; i<grid.size();i++){
            for(int j=0; j<grid[0].size();j++){
                if(grid[i][j]==2)q.push({i,j});
                else if(grid[i][j]==1)fresh++;
            }
        }

        if(fresh==0)return 0;

        int minutes = 0;
        while(!q.empty()){
            if(bfs(grid,q,fresh))minutes++;
            else break;
        }

        return fresh==0 ? minutes : -1;
    }
};