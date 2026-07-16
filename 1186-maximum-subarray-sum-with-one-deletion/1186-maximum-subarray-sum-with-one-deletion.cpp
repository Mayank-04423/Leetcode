class Solution {
public:
    int maximumSum(vector<int>& arr) {
        
        int usual = arr[0];
        int deleted = arr[0];
        int ans = arr[0];
        for(int i=1; i<arr.size(); i++){
            //cuz we need previus usual array islie pehle delete one wala run hoga 
            deleted = max(usual,deleted + arr[i]);
            usual = max(usual + arr[i], arr[i]);
            ans = max({deleted , usual, ans});
        }
        return ans;
    }
};