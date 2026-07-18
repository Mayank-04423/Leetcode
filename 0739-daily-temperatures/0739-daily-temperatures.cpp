class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int>ans(n,0);
        stack<int>waiting;

        for(int curr=0; curr< n ; curr++){

            while( !waiting.empty() && temperatures[curr]>temperatures[waiting.top()]){
                int prev = waiting.top();
                waiting.pop();

                ans[prev] = curr - prev;
            }
            waiting.push(curr);
        }
        return ans;
    }
};