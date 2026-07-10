class Solution {
    vector<int>prefixSum;
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        prefixSum.resize(n+1,0);

        //storing previous sum
        for(int i=0; i< n; i++){
            prefixSum[i+1] = prefixSum[i] + gain[i]; 
        }
        return *max_element(prefixSum.begin(),prefixSum.end());
    }
};