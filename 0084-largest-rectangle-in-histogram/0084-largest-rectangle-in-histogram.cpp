class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int>st;   //storing index
        int area = 0;
        int n = heights.size();

        for(int i=0; i<=n ;i++){

            int currHeight;
            if(i==n){ 
                currHeight = 0;
            }else {
                currHeight = heights[i];
            }

            while(!st.empty() && currHeight < heights[st.top()]){
                int h = heights[st.top()];
                st.pop();

                //width calculation
                int width;
                if(st.empty()){
                    width = i;
                }else{
                    width = (i - st.top() -1);
                }

                int currArea = h*width;
                area = max(area, currArea);
            }     
            st.push(i);
        }
        return area;
    }
};