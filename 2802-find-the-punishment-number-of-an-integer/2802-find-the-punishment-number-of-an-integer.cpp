class Solution {
public:
    bool check(int i, int currSum, string s, int num) {
        if(i == s.length()) {
            return currSum == num;
        }
        if(currSum > num){
            return 0;
        }
        for(int j = i; j <s.length(); j++) {
            string sub = s.substr(i, j-i+1);
            int val = stoi(sub);
            if(check(j+1, currSum+val, s, num)) return 1;
        }
        return 0;
    }
    int punishmentNumber(int n) {
        int sum = 0;
        for(int num = 1;num<=n; num++) {
            int data = num*num;
            string s = to_string(data);
            if(check(0, 0, s, num)) {
                sum =sum + data;
            }
        }
        return sum;
    }
};