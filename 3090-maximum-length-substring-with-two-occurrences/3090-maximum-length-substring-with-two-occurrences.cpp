class Solution {
public:
    int maximumLengthSubstring(string s) {
         int n = s.size();
        vector<int> freq(26, 0);
        int left = 0, maxLen = 0;

        for (int right = 0; right < n; right++) {
            int idx = s[right] - 'a';
            freq[idx]++;

            while (freq[idx] > 2) {
                freq[s[left] - 'a']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};