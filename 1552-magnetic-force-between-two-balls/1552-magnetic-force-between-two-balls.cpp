class Solution {
    private:
    bool canPlace(vector<int>&position , int balls ,int minDist ){
        int count = 1;
        int lastPlaced = position[0];

        for(int i=0; i<position.size();i++){
            if(position[i] - lastPlaced >= minDist){
                count++;
                lastPlaced = position[i];
            }
            if(count >= balls) return true;
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());

        int left = 1;
        int right = position.back() - position[0];
        int ans = 0;

        while(left<=right){
            int mid = left +(right-left)/2;

            if(canPlace(position,m,mid)){
                ans = mid;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return ans;
    }
};