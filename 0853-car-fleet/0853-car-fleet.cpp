class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>>cars(n);
        for(int i=0; i<n ;i++){
            cars[i] = {position[i],speed[i]};
        }

        //sorting positionswise in decreasing order 
        sort(cars.rbegin(),cars.rend());

        vector<double>st;
        for(int i=0; i<n ;i++){
        double time = double(target - cars[i].first)/ cars[i].second; //time = target-position/speed
        
            //if car is slow it'll start its own new fleet 
            if(st.empty() || time>st.back()){
                st.push_back(time);
            }
        }
        return st.size();
    }
};