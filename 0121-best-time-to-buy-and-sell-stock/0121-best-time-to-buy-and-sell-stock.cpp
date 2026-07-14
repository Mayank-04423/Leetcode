class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int ans = 0;

        for(int i=1; i<prices.size(); i++){
            int v1 = minPrice;
            int v2 = prices[i];
            minPrice = min(v1,v2);

            //calculate profit
            int profit = prices[i] - minPrice;
            ans = max(profit,ans);
        }
        return ans;
    }
};