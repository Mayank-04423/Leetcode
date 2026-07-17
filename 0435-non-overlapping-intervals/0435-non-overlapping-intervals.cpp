class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        if(intervals.empty())return 0;
        sort(intervals.begin(),intervals.end());

        int count = 0;
        int end1 = intervals[0][1];

        for(int i=1; i<intervals.size(); i++){
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            if(end1>start2){
                count++;
                //we want to keep the one ending earlier !!!
                end1 = min(end1,end2);
            }else{
                end1 = end2;
            }
        }
        return count;
    }
};