class Solution {
public:
    int sumOfDigits(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> digitSumMap;
        int maxSum = -1;
        for(int i = 0; i<n; i++) {
            int digitSum = sumOfDigits(nums[i]);
            if (digitSumMap.find(digitSum) != digitSumMap.end()) {
                maxSum = max(maxSum, digitSumMap[digitSum] + nums[i]);
            }
            digitSumMap[digitSum] = max(digitSumMap[digitSum], nums[i]);
        }
        return maxSum;
    }
};