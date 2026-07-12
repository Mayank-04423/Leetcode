class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>set;
        int l =0;
        int max_length = 0;

        for(int r=0; r<s.length();r++){
            //if already exists
            while(set.find(s[r])!=set.end()){
                set.erase(s[l]);
                l++;
            }
            set.insert(s[r]);
            max_length = max(max_length, r-l+1);
        }
       return max_length;
    }
};