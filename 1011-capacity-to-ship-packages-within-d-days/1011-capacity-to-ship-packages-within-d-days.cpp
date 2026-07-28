class Solution {
    private:
    bool canShip(vector<int>&weights ,int days ,int capacity){
        int daysNeeded =1;
        int currWeight = 0;
       
        for(int i =0; i<weights.size(); i++){
            if(currWeight + weights[i]> capacity){
                daysNeeded ++;
                currWeight = weights[i];
            }else{
                currWeight += weights[i];
            }
            
        }return daysNeeded <= days;
       
    }
  
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int left =*max_element(weights.begin(),weights.end());
        int right = accumulate(weights.begin(),weights.end(),0);
        int ans = right;

        while(left <= right){
            int mid = left + (right-left)/2;

            if(canShip(weights , days,mid)){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};