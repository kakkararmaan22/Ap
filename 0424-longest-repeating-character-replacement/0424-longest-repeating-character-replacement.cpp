class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int left = 0, maxLen=0, maxFreq =0, changes =0;
        unordered_map<char,int> mp;
        for(int right = 0; right<n; right++) {
            mp[s[right]]++;
            maxFreq = max(maxFreq, mp[s[right]]);
            changes = (right -left+1) - maxFreq;
            if(changes<=k) {
                maxLen = max(maxLen, right -left+1);
            }
            if(changes>k) {
                mp[s[left]]--;
                left++;
                if(mp[s[left]] == 0) mp.erase(s[left]);
            }
        }
        return maxLen;
    }
};