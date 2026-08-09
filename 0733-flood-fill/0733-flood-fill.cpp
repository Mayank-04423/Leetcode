class Solution {
    void bfs(vector<vector<int>>& image , int i, int j,int oldColor , int color){
        if(i<0 || i>=image.size() || j<0 || j>image[0].size() || image[i][j]!=oldColor)
        return;

        image[i][j]= color;

        bfs(image, i , j+1, oldColor , color);
        bfs(image, i , j-1, oldColor , color);
        bfs(image, i+1 , j, oldColor , color);
        bfs(image, i-1 , j, oldColor , color);        

    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if(oldColor==color)return image ;

        bfs(image, sr ,sc ,oldColor, color);
        return image;
    }    
};