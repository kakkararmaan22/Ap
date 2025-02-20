class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> mp;
        int left =0, ans = 0;
        for(int right = 0; right<n; right++) {
            if(mp.size()>2) {
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0) mp.erase(fruits[left]);  
                left++;
            }
            
            mp[fruits[right]]++;
            if(mp.size()<=2) {
                ans = max(ans, right-left+1);
            }
        }
        return ans;
    }
};