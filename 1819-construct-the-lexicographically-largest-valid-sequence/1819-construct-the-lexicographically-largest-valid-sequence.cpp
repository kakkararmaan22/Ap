class Solution {
public:
    bool dfs(int index, int n, vector<int> &ans, vector<int> &used) {
        if(index == ans.size()) return true;
        if(ans[index] != 0) return dfs(index+1, n, ans, used);
        for (int num = n; num >= 1; num--) {
            if(used[num]) continue;
            int secondIndex = (num == 1) ? index : index + num;
            if(secondIndex < ans.size() && ans[secondIndex] == 0) {
                ans[index] = ans[secondIndex] = num;
                used[num] = true;
                if(dfs(index+1, n, ans, used)) return true;
                ans[index] = ans[secondIndex] = 0;
                used[num] = false;
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n-1,0);
        vector<int> used(n+1, 0);
        dfs(0, n, ans, used);
        return ans;
    }
};