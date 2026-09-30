class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length()!=t.length()){
            return false;
        }

        unordered_map<char, int>track;

        for(int i=0; i<s.length(); i++){
            char curr = s[i];
            track[curr]++;
        }

        for(int j = 0 ; j<t.length(); j++){
            char curr = t[j];

            if(track.count(curr)==0){
                return false;
            }
            track[curr]--;

            if(track.count(curr)<0){
                return false;
            }
        }

        for(auto pair:track){
            if(pair.second!=0){
                return false;
            }
            
        }
        return true;
    }
};