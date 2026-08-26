class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int n = nums.size();

        vector<pair<int, int>>indexed(n);
        for(int i=0; i<n ;i++){
            indexed[i] = {nums[i] ,i};
        }

        sort(indexed.begin(),indexed.end());

        int p=0;
        int q= n-1;
        while(p<q){

            int currSum = indexed[p].first + indexed[q].first;

            if(currSum == target){
                return {indexed[p].second,indexed[q].second};
            }else if(currSum < target){
                p++;
            }else{
                q--;
            }
        }

        return{};

        }
    
};