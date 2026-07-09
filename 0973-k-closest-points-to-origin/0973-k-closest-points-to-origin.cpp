class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int ,vector<int>>>pq;

        for(auto&pt: points){
            int x =pt[0];int y=pt[1];
            int distance = x*x + y*y ; //dynamically to reduce space 

            pq.push({distance,pt});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>>result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }

};