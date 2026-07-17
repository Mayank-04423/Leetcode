class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(),points.end());
        int end1 = points[0][1];
        int arrow = 1;

        for(int i=1;i<points.size();i++){
            int start2 = points[i][0];
            int end2 = points[i][1];

            if(end1>=start2){
                end1 = min(end1,end2);
            }else{
                arrow++;
                end1 = end2;
            }
        }
        return arrow;
    }
};