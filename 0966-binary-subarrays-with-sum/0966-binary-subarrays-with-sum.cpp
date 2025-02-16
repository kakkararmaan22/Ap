class Solution {
public:
    int solve(vector<int>& nums, int goal) {
        int n = nums.size();
        int sum =0, left = 0, cnt= 0;
        for(int right =0; right <n; right++) {
            sum = sum + nums[right];
            while(sum>goal && left <= right) {
                sum= sum-nums[left];
                left++;
            }
            cnt = cnt + (right-left+1);
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal<0) return 0;
        return solve(nums, goal)- solve(nums, goal-1);
    }
};