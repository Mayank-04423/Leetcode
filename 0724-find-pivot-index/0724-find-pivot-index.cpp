class Solution {
    vector<int>prefixSum;
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        prefixSum.resize(n+1,0);

        //comparing left and right sum
        for(int i=0; i< n; i++){
            prefixSum[i+1] = prefixSum[i]+nums[i];
        }

        for(int i=0; i< n; i++){
        int leftSum = prefixSum[i];
        int m = prefixSum.size(); 
        int rightSum = prefixSum[m - 1] - prefixSum[i+1];

        if(leftSum ==rightSum){
            return i;
        }
        }
        return -1;
    }
};