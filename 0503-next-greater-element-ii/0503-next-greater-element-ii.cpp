class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,-1);   //assigning -1 to each index
        stack<int>waiting;

        //running 2 times the length to avoid making custom indexing
        for(int i=0;i<n*2;i++){
            //simulating circular
            int idx = i%n;     

            while(!waiting.empty() && nums[idx]>nums[waiting.top()]){
                ans[waiting.top()] = nums[idx];
                waiting.pop();
            }

            if(i<n){
                waiting.push(idx);
            }
        }
        return ans;
    }
};