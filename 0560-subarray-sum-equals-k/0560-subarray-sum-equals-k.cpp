class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int>prefixMap;

        prefixMap[0] =1;
        int currentSum = 0;
        int count =0;

        for(int i =0; i<nums.size() ;i++){
            currentSum += nums[i];

            //checking if currentsum - k exists
            if(prefixMap.find(currentSum -k)!=prefixMap.end()){
                 count+=prefixMap[currentSum - k];
            }
            prefixMap[currentSum]++;
        }
        return count;
    }
};