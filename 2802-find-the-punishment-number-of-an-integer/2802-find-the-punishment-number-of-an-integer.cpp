class Solution {
public:
    bool check(int i, int currSum, string &s, int num,vector<vector<int>> &dp) {
        if(i == s.length()) {
            return currSum == num;
        }
        if(currSum > num){
            return 0;
        }
        if (dp[i][currSum] != -1) return dp[i][currSum];

        for(int j = i; j <s.length(); j++) {
            string sub = s.substr(i, j-i+1);
            int val = stoi(sub);
            if(check(j+1, currSum+val, s, num,dp)) return dp[i][currSum] = 1;
        }
        return dp[i][currSum] = 0;
    }
    int punishmentNumber(int n) {
        int sum = 0;
        for(int num = 1;num<=n; num++) {
            int data = num*num;
            string s = to_string(data);
            vector<vector<int>> dp(s.length(), vector<int>(num+1,-1));
            if(check(0, 0, s, num, dp)) {
                sum =sum + data;
            }
        }
        return sum;
    }
};