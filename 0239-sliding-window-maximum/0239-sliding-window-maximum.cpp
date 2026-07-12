class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>result;

        for(int i=0; i<nums.size(); i++){
            //if element is still within bounds 
            if(!dq.empty() && dq.front() == i-k){
                dq.pop_front();
            }

            //kicking smaller values from back
            while(!dq.empty() && nums[dq.back()]<nums[i]){
            dq.pop_back();
            }

            dq.push_back(i);

            //if window reached k -> front element would be the greatest
            if(i >= k-1){
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};