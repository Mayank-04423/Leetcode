class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>st;

        int curr ;
       
        for(int curr : asteroids){
            bool destroyed = false;
            while(!st.empty() && st.back()>0 && curr<0 && !destroyed){
                if(st.back()< abs(curr)){
                    st.pop_back();
                }
                else if(st.back()==abs(curr)){
                    st.pop_back();
                    destroyed = true;
                }
                else if(st.back() >abs(curr)){
                    destroyed = true;
                }

            }

            if(!destroyed){
                st.push_back(curr);
            }
        }

        return st;
    }
};