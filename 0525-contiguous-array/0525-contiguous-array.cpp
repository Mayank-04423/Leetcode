class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int , int>sumMap;
        sumMap[0] = -1;

        int currSum = 0;
        int maxLength = 0;

        for(int i=0; i< nums.size();i++){
            if(nums[i]==1){
                currSum+=1;
            }else{
                currSum -= 1;
            }

            if(sumMap.find(currSum)!=sumMap.end()){
                int distance = i - sumMap[currSum];
                maxLength = max(maxLength , distance);
            }else{
                sumMap[currSum]=i;
            }
        }
        return maxLength;
    }
};