class Solution {
public:
    bool check(int i, int currSum, string &s, int num, vector<vector<int>> &dp) {
        if (i == s.length()) {
            return currSum == num;
        }
        if (currSum > num) {
            return false;
        }
        if (dp[i][currSum] != -1) return dp[i][currSum];

        int val = 0; // Maintain the integer value while iterating
        for (int j = i; j < s.length(); j++) {
            val = val * 10 + (s[j] - '0'); // Convert substring to integer without using stoi()
            if (val > num) break; // Prune unnecessary computations
            if (check(j + 1, currSum + val, s, num, dp)) 
                return dp[i][currSum] = 1;
        }
        return dp[i][currSum] = 0;
    }

    int punishmentNumber(int n) {
        int sum = 0;
        for (int num = 1; num <= n; num++) {
            int data = num * num;
            string s = to_string(data);
            vector<vector<int>> dp(s.length(), vector<int>(num + 1, -1)); // Properly initialize dp
            if (check(0, 0, s, num, dp)) {
                sum += data;
            }
        }
        return sum;
    }
};