class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n =nums.size();
        int left = 0, ans=0, zeros =0;
        for(int right = 0; right<n; right++) {
            if(nums[right] == 0) zeros++;
            if(zeros>k) {
                if(nums[left] == 0) zeros--;
                left++;
            }
            if(zeros <= k) ans= max(ans, right-left+1);
        }
        return ans;
    }
};